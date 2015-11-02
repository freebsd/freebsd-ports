--- pulledpork.pl.orig	2013-09-11 21:01:05 UTC
+++ pulledpork.pl
@@ -3,7 +3,7 @@
 ## pulledpork v(whatever it says below!)
 ## cummingsj@gmail.com
 
-# Copyright (C) 2009-2013 JJ Cummings and the PulledPork Team!
+# Copyright (C) 2009-2015 JJ Cummings, Michael Shirk and the PulledPork Team!
 
 # This program is free software; you can redistribute it and/or
 # modify it under the terms of the GNU General Public License
@@ -41,16 +41,51 @@ use Data::Dumper;
 
 # we are gonna need these!
 my ( $oinkcode, $temp_path, $rule_file, $Syslogging );
-my $VERSION = "PulledPork v0.7.0 - Swine Flu!";
+my $VERSION = "PulledPork v0.7.2 - E.Coli in your water bottle!";
 my $ua      = LWP::UserAgent->new;
 
+# for certificate validation, check for the operating system
+# and set the path to the certificate store if required.
+my $oSystem = "$^O";
+my $CAFile = "OS Default";
+if ($oSystem =~ /freebsd/i) {
+    #Check to ensure the cert file exists
+    if ( -e "/etc/ssl/cert.pem" ) { 
+    	$CAFile = "/etc/ssl/cert.pem";
+        if ( -r $CAFile) {
+           $ua->ssl_opts( SSL_ca_file => $CAFile );
+        } else {	
+    	   carp "ERROR: $CAFile is not readable by ".(getpwuid($<))[0]."\n";
+	   syslogit( 'err|local0', "FATAL: ERROR: $CAFile is not readable by ".(getpwuid($<))[0]."\n")
+	   if $Syslogging;
+ 	   exit(1);
+        }
+    #Check for the other location for the cert file
+    } elsif ( -e "/usr/local/share/certs/ca-root-nss.crt" ) {
+    	$CAFile = "/usr/local/share/certs/ca-root-nss.crt";
+        if ( -r $CAFile) {
+           $ua->ssl_opts( SSL_ca_file => $CAFile );
+        } else {	
+    	   carp "ERROR: $CAFile is not readable by ".(getpwuid($<))[0]."\n";
+	   syslogit( 'err|local0', "FATAL: ERROR: $CAFile is not readable by ".(getpwuid($<))[0]."\n")
+	   if $Syslogging;
+ 	   exit(1);
+        }
+    } else {
+           carp "ERROR: cert file does not exist (/etc/ssl/cert.pem or /usr/local/share/certs/ca-root-nss.crt) Ensure that the ca_root_nss port/pkg is installed, or use -w to skip SSL verification\n";
+           syslogit( 'err|local0', "FATAL: cert file does not exist. Ensure that the ca_root_nss port/pkg is installed, or use -w to skip SSL verification\n")
+           if $Syslogging;
+           exit(1);
+    }
+}
+
 my ( $Hash, $ALogger, $Config_file, $Sorules, $Auto );
 my ( $Output, $Distro, $Snort, $sid_changelog, $ignore_files );
 my ( $Snort_config, $Snort_path, $Textonly,   $grabonly,    $ips_policy, );
 my ( $pid_path,     $SigHup,     $NoDownload, $sid_msg_map, @base_url );
 my ( $local_rules,  $arch,       $docs,       @records,     $enonly );
 my ( $rstate, $keep_rulefiles, $rule_file_path, $prefix, $black_list );
-my ( $Process, $hmatch, $bmatch , $sid_msg_version);
+my ( $Process, $hmatch, $bmatch , $sid_msg_version, $skipVerify);
 my $Sostubs = 1;
 
 # verbose and quiet control print()
@@ -144,11 +179,11 @@ sub Help {
    -D What Distro are you running on, for the so_rules
       For latest supported options see http://www.snort.org/snort-rules/shared-object-rules
       Valid Distro Types:
-		Debian-5-0, Debian-6-0, Ubuntu-8.04, Ubuntu-10-4
-		Centos-4-8, Centos-5-4,	FC-12, FC-14, RHEL-5-5, RHEL-6-0
-		FreeBSD-7-3, FreeBSD-8-1
-		OpenBSD-4-8
-		Slackware-13-1
+		Debian-6-0, Ubuntu-10-4, Ubuntu-12-04, Centos-5-4
+		FC-12, FC-14, RHEL-5-5, RHEL-6-0
+		FreeBSD-8-1, FreeBSD-9-0, FreeBSD-10-0
+		OpenBSD-5-2, OpenBSD-5-3
+		OpenSUSE-11-4, OpenSUSE-12-1, Slackware-13-1
    -e Where the enablesid config file lives.
    -E Write ONLY the enabled rules to the output files.
    -g grabonly (download tarball rule file(s) and do NOT process)
@@ -176,6 +211,7 @@ sub Help {
    -V Print Version and exit
    -v Verbose mode, you know.. for troubleshooting and such nonsense.
    -vv EXTRA Verbose mode, you know.. for in-depth troubleshooting and other such nonsense.
+   -w Skip the SSL verification (if there are issues pulling down rule files)
 __EOT
 
     exit(0);
@@ -186,12 +222,12 @@ sub pulledpork {
 
     print <<__EOT;
 
-    http://code.google.com/p/pulledpork/
+    https://github.com/shirkdog/pulledpork
       _____ ____
      `----,\\    )
       `--==\\\\  /    $VERSION
        `--==\\\\/
-     .-~~~~-.Y|\\\\_  Copyright (C) 2009-2013 JJ Cummings
+     .-~~~~-.Y|\\\\_  Copyright (C) 2009-2015 JJ Cummings
   \@_/        /  66\\_  cummingsj\@gmail.com
     |    \\   \\   _(\")
      \\   /-| ||'--'  Rules give me wings!
@@ -227,7 +263,7 @@ sub rule_extract {
     $tar->read( $temp_path . $rule_file );
     $tar->setcwd( cwd() );
     local $Archive::Tar::CHOWN = 0; 
-    my @ignores = split( /,/, $ignore );
+    my @ignores = split( /,/, $ignore ) if (defined $ignore);
 
     foreach (@ignores) {
         if ( $_ =~ /\.rules/ ) {
@@ -350,9 +386,27 @@ sub compare_md5 {
 ## mimic LWP::Simple getstore routine - Thx pkthound!
 sub getstore {
     my ( $url, $file ) = @_;
-    my $request = HTTP::Request->new( GET => $url );
-    my $response = $ua->request( $request, $file );
-    $response->code;
+
+    # on the first run, the file may not exist, so check.
+    if ( -e $file) { 
+        # Check to ensure the user has write access to the file
+        if ( -r $file && -w _) {
+    	   my $request = HTTP::Request->new( GET => $url );
+    	   my $response = $ua->request( $request, $file );
+    	   $response->code;
+        } else {	
+    	   carp "ERROR: $file is not writable by ".(getpwuid($<))[0]."\n";
+	   syslogit( 'err|local0', "FATAL: $file is not writable by ".(getpwuid($<))[0]."\n" )
+	   if $Syslogging;
+ 	   exit(1);
+        }
+    } else {
+	   # The file does not exist, any errors refer to permission issues
+    	   my $request = HTTP::Request->new( GET => $url );
+    	   my $response = $ua->request( $request, $file );
+    	   $response->code;
+    }
+
 }
 
 ## time to grab the real 0xb33f
@@ -527,9 +581,9 @@ sub read_rules {
                         elsif ( $row !~ /\\$/ && $trk == 1 )
                         {    # last line of multiline rule here
                             $record .= $row;
-                            if ( $record =~ /sid:\s*\d+\s*;/i ) {
+                            if ( $record =~ /\ssid:\s*\d+\s*;/i ) {
                                 $sid = $&;
-                                $sid =~ s/sid:\s*//;
+                                $sid =~ s/\ssid:\s*//;
 				$sid =~ s/\s*;//;
                                 $$hashref{0}{ trim($sid) }{'rule'} = $record;
                             }
@@ -537,9 +591,9 @@ sub read_rules {
                             undef $record;
                         }
                         else {
-                            if ( $row =~ /sid:\s*\d+\s*;/i ) {
+                            if ( $row =~ /\ssid:\s*\d+\s*;/i ) {
                                 $sid = $&;
-                                $sid =~ s/sid:\s*//;
+                                $sid =~ s/\ssid:\s*//;
 				$sid =~ s/\s*;//;
                                 $$hashref{0}{ trim($sid) }{'rule'} = $row;
                             }
@@ -563,13 +617,13 @@ sub read_rules {
                 $rule = trim($rule);
                 if ( $rule =~ /^\s*#*\s*(alert|drop|pass)/i ) {
 
-                    if ( $rule =~ /sid:\s*\d+\s*;/i ) {
+                    if ( $rule =~ /\ssid:\s*\d+\s*;/i ) {
                         $sid = $&;
-                        $sid =~ s/sid:\s*//;
+                        $sid =~ s/\ssid:\s*//;
 			$sid =~ s/\s*;//;
-                        if ( $rule =~ /gid:\s*\d+/i ) {
+                        if ( $rule =~ /\sgid:\s*\d+/i ) {
                             $gid = $&;
-                            $gid =~ s/gid:\s*//;
+                            $gid =~ s/\sgid:\s*//;
                         }
                         else { $gid = 1; }
                         if ( $rule =~ /flowbits:\s*((un)?set(x)?|toggle)/i ) {
@@ -616,12 +670,12 @@ sub read_rules {
 
         foreach my $rule (@elements) {
             if ( $rule =~ /^\s*#*\s*(alert|drop|pass)/i ) {
-                if ( $rule =~ /sid:\s*\d+/ ) {
+                if ( $rule =~ /\ssid:\s*\d+/ ) {
                     $sid = $&;
-                    $sid =~ s/sid:\s*//;
-                    if ( $rule =~ /gid:\s*\d+/i ) {
+                    $sid =~ s/\ssid:\s*//;
+                    if ( $rule =~ /\sgid:\s*\d+/i ) {
                         $gid = $&;
-                        $gid =~ s/gid:\s*//;
+                        $gid =~ s/\sgid:\s*//;
                     }
                     else { $gid = 1; }
                     if ( $rule =~ /flowbits:\s*((un)?set(x)?|toggle)/ ) {
@@ -1463,6 +1517,25 @@ sub archive_wanted {
     push( @records, $File::Find::name );
 }
 
+## Create ignore_files from conf file
+sub get_ignore_files {
+  my ($ignore_conf_file) = @_;
+  my $ignore_list;
+
+  print "\tReading ignore_file: $ignore_conf_file\n";
+
+  # Read ignore file and exclude comments/blank lines
+  open ( FH, '<', $ignore_conf_file ) || croak "Couldn't read $ignore_conf_file $!\n";
+    while ( <FH> ) {
+      chomp;
+      s/#.*//;
+      if ( ! /^\s*$/ ) { $ignore_list .= "$_," };
+    };
+  close FH;
+  $ignore_list =~ s/,\s*$//g ;
+  return $ignore_list
+}
+
 ###
 ### Main here, let's get on with it already
 ###
@@ -1507,7 +1580,8 @@ GetOptions(
     "u=s"    => \@base_url,
     "V!"     => sub { Version() },
     "v+"     => \$Verbose,
-    "help|?" => sub { Help() }
+    "help|?" => sub { Help() },
+    "w" => \$skipVerify
 );
 
 ## Fly piggy fly!
@@ -1533,7 +1607,7 @@ if ( $Verbose && !$Quiet ) {
 if ( exists $Config_info{'version'} ) {
     croak "You are not using the current version of pulledpork.conf!\n",
       "Please use the version of pulledpork.conf that shipped with $VERSION!\n\n"
-      if $Config_info{'version'} ne "0.7.0";
+      if $Config_info{'version'} ne "0.7.2";
 }
 else {
     croak
@@ -1546,6 +1620,12 @@ else {
 $pid_path     = ( $Config_info{'pid_path'} ) if exists $Config_info{'pid_path'};
 $ignore_files = ( $Config_info{'ignore'} )   if exists $Config_info{'ignore'};
 
+# Allow ignores to be specified in a file, supercedes the regular ignore config option
+if ( exists $Config_info{'ignore_file'})
+{
+  $ignore_files = get_ignore_files($Config_info{'ignore_file'});
+}
+
 if ($rule_file_path) {
     $keep_rulefiles = 1;
 }
@@ -1658,6 +1738,8 @@ if ( $Verbose && !$Quiet ) {
     print "MISC (CLI and Autovar) Variable Debug:\n";
     if ($Process)	 { print "\tProcess flag specified!\n"; }
     if ($arch)           { print "\tarch Def is: $arch\n"; }
+    if ($oSystem)        { print "\tOperating System is: $oSystem\n"; }
+    if ($CAFile)         { print "\tCA Certificate File is: $CAFile\n"; }
     if ($Config_file)    { print "\tConfig Path is: $Config_file\n"; }
     if ($Distro)         { print "\tDistro Def is: $Distro\n"; }
     if ($docs)           { print "\tDocs Reference Location is: $docs\n"; }
@@ -1700,6 +1782,8 @@ if ( $Verbose && !$Quiet ) {
     if ($Textonly)     { print "\tText Rules only Flag is Set\n"; }
     if ( $Verbose == 2 ) { print "\tExtra Verbose Flag is Set\n"; }
     if ($Verbose)        { print "\tVerbose Flag is Set\n"; }
+    if ($skipVerify)     { print "\tSSL Hostname Verification disabled\n"; }
+    if ($ignore_files)   { print "\tFile(s) to ignore = $ignore_files\n"; }
     if (@base_url)       { print "\tBase URL is: @base_url\n"; }
 }
 
@@ -1717,10 +1801,17 @@ if ( !-d $temp_path ) {
 # Validate sid_msg_map version
 Help("Please specify version 1 or 2 for sid_msg_version in your config file\n") unless $sid_msg_version =~ /(1|2)/;
 
+
 # set some UserAgent and other connection configs
 $ua->agent("$VERSION");
 $ua->show_progress(1) if ( $Verbose && !$Quiet );
 
+# check to see if SSL verfication is disabled
+if ($skipVerify) {
+    $ua->ssl_opts( verify_hostname => 0 )
+}
+
+
 # New Settings to allow proxy connections to use proper SSL formating - Thx pkthound!
 $ua->timeout(60);
 $ua->cookie_jar( {} );
