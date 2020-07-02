--- pulledpork.pl.orig	2020-07-02 11:46:17 UTC
+++ pulledpork.pl
@@ -2,7 +2,7 @@
 
 ## pulledpork v(whatever it says below!)
 
-# Copyright (C) 2009-2017 JJ Cummings, Michael Shirk and the PulledPork Team!
+# Copyright (C) 2009-2019 JJ Cummings, Michael Shirk and the PulledPork Team!
 
 # This program is free software; you can redistribute it and/or
 # modify it under the terms of the GNU General Public License
@@ -24,6 +24,7 @@ use File::Copy;
 use LWP::UserAgent;
 use HTTP::Request::Common;
 use HTTP::Status qw (is_success);
+
 #use Crypt::SSLeay;
 use Sys::Syslog;
 use Digest::MD5;
@@ -41,8 +42,8 @@ use Data::Dumper;
 
 # we are gonna need these!
 my ($oinkcode, $temp_path, $rule_file, $Syslogging);
-my $VERSION = "PulledPork v0.7.3";
-my $HUMOR   = "Making signature updates great again!";
+my $VERSION = "PulledPork v0.7.4";
+my $HUMOR   = "Helping you protect your bitcoin wallet!";
 my $ua      = LWP::UserAgent->new;
 
 #Read in proxy settings from the environment
@@ -90,9 +91,24 @@ if ($oSystem =~ /freebsd/i) {
             exit(1);
         }
     }
+    elsif (-e "/usr/local/share/certs/ca-root-nss.crt") {
+        $CAFile = "/usr/local/share/certs/ca-root-nss.crt";
+        if (-r $CAFile) {
+            $ua->ssl_opts(SSL_ca_file => $CAFile);
+        }
+        else {
+            carp "ERROR: $CAFile is not readable by "
+                . (getpwuid($<))[0] . "\n";
+            syslogit('err|local0',
+                "FATAL: ERROR: $CAFile is not readable by "
+                    . (getpwuid($<))[0] . "\n")
+                if $Syslogging;
+            exit(1);
+        }
+    }
     else {
         carp
-            "ERROR: cert file does not exist (/etc/ssl/cert.pem or /usr/local/etc/ssl/cert.pem) Ensure that the ca_root_nss port/pkg is installed, or use -w to skip SSL verification\n";
+            "ERROR: cert file does not exist (/etc/ssl/cert.pem, /usr/local/etc/ssl/cert.pem or /usr/local/share/certs/ca-root-nss.crt) Ensure that the ca_root_nss port/pkg is installed, or use -w to skip SSL verification\n";
         syslogit('err|local0',
             "FATAL: cert file does not exist. Ensure that the ca_root_nss port/pkg is installed, or use -w to skip SSL verification\n"
         ) if $Syslogging;
@@ -201,10 +217,16 @@ sub Help {
    -D What Distro are you running on, for the so_rules
       For latest supported options see http://www.snort.org/snort-rules/shared-object-rules
       Valid Distro Types:
-        Debian-6-0, Ubuntu-10-4, Ubuntu-12-04, Centos-5-4
-        FC-12, FC-14, RHEL-5-5, RHEL-6-0
-        FreeBSD-8-1, FreeBSD-9-0, FreeBSD-10-0, OpenBSD-5-2, OpenBSD-5-3
-        OpenSUSE-11-4, OpenSUSE-12-1, Slackware-13-1
+	Alpine-3-10
+	Centos-6 Centos-7 Centos-8 Debian-8 Debian-9
+	Debian-10
+	FC-27 FC-30 FC-31
+	FreeBSD-11 FreeBSD-12
+	OpenBSD-6-2 OpenBSD-6-4 OpenBSD-6-5
+	OpenSUSE-15-0 OpenSUSE-15-1 OpenSUSE-42-3
+	RHEL-6 RHEL-7 RHEL-8
+	Slackware-14-2
+	Ubuntu-14-4 Ubuntu-16-4 Ubuntu-17-10 Ubuntu-18-4 Ubuntu-19-10
    -e Where the enablesid config file lives.
    -E Write ONLY the enabled rules to the output files.
    -g grabonly (download tarball rule file(s) and do NOT process)
@@ -277,14 +299,27 @@ sub rule_extract {
         $rule_file, $temp_path, $Distro, $arch, $Snort,
         $Sorules,   $ignore,    $docs,   $prefix
     ) = @_;
-    print "Prepping rules from $rule_file for work....\n" if !$Quiet;
-    print "\textracting contents of $temp_path$rule_file...\n"
-        if ($Verbose && !$Quiet);
+
+    #special case to bypass file operations when -nPT are specified
+    my $BypassTar = 0;
+    if ($Textonly && $NoDownload && $Process) {
+        if ($rule_file =~ /opensource\.gz/) {
+            print "Skipping opensource.gz as -nPT was specified\n" if !$Quiet;
+            $BypassTar = 1;
+        }
+    }
+    if (!$BypassTar) {
+        print "Prepping rules from $rule_file for work....\n" if !$Quiet;
+        print "\textracting contents of $temp_path$rule_file...\n"
+            if ($Verbose && !$Quiet);
+    }
     mkpath($temp_path . "tha_rules");
     mkpath($temp_path . "tha_rules/so_rules");
     my $tar = Archive::Tar->new();
-    $tar->read($temp_path . $rule_file);
-    $tar->setcwd(cwd());
+    if (!$BypassTar) {
+        $tar->read($temp_path . $rule_file);
+        $tar->setcwd(cwd());
+    }
     local $Archive::Tar::CHOWN = 0;
     my @ignores = split(/,/, $ignore) if (defined $ignore);
 
@@ -345,7 +380,8 @@ sub rule_extract {
         }
         elsif ($docs
             && $filename =~ /^(doc\/signatures\/)?.*\.txt/
-            && -d $docs)
+            && -d $docs
+            && !$BypassTar)
         {
             $singlefile =~ s/^doc\/signatures\///;
             $tar->extract_file("doc/signatures/$filename",
@@ -928,7 +964,21 @@ sub modify_sid {
             }
             undef @arry;
         }
+
+        # Handle use case where we want to modify multiple sids based on
+        # comment in rule (think multiple rules with same or similar comment)
+        if ( $_ =~ /^regex:'([^']+)'\s+"(.+)"\s+"(.*)"/ ) {
+            my ( $regex, $from, $to ) = ( $1, $2, $3 );
+            # Go through each rule in gid:1 and look for matching rules
+            foreach my $sid ( sort keys( %{ $$href{1} } ) ) {
+                next unless ( $$href{1}{$sid}{'rule'} =~ /$regex/ );
+                print "\tModifying SID:$sid from:$from to:$to\n"
+                  if ( $Verbose && !$Quiet );
+                $$href{1}{$sid}{'rule'} =~ s/$from/$to/;
+            }
+        }
     }
+
     print "\tDone!\n" if !$Quiet;
     close(FH);
 }
@@ -1277,7 +1327,7 @@ sub rule_category_write {
 ## write our blacklist and blacklist version file!
 sub blacklist_write {
     my ($href, $path) = @_;
-    my $blv   = $Config_info{'IPRVersion'} . "IPRVersion.dat";
+    my $blv   = $Config_info{'IPRVersion'} . "/IPRVersion.dat";
     my $blver = 0;
 
     # First lets be sure that our data is new, if not skip the rest of it!
@@ -1769,7 +1819,7 @@ if ($Verbose && !$Quiet) {
 if (exists $Config_info{'version'}) {
     croak "You are not using the current version of pulledpork.conf!\n",
         "Please use the version of pulledpork.conf that shipped with $VERSION!\n\n"
-        if $Config_info{'version'} ne "0.7.3";
+        if $Config_info{'version'} ne "0.7.4";
 }
 else {
     croak
@@ -2118,6 +2168,7 @@ if (@base_url && -d $temp_path) {
                 }
             }
             elsif ($base_url =~ /emergingthreatspro.com/) {
+                $prefix = "ET-";
 
                 # These have to be handled separately, as emerginthreatspro will
                 # support a full version, but emergingthreats only supports the
