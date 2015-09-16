--- pulledpork.pl.orig	2015-06-01 19:41:36 UTC
+++ pulledpork.pl
@@ -3,7 +3,7 @@
 ## pulledpork v(whatever it says below!)
 ## cummingsj@gmail.com
 
-# Copyright (C) 2009-2013 JJ Cummings and the PulledPork Team!
+# Copyright (C) 2009-2014 JJ Cummings and the PulledPork Team!
 
 # This program is free software; you can redistribute it and/or
 # modify it under the terms of the GNU General Public License
@@ -41,16 +41,17 @@ use Data::Dumper;
 
 # we are gonna need these!
 my ( $oinkcode, $temp_path, $rule_file, $Syslogging );
-my $VERSION = "PulledPork v0.7.0 - Swine Flu!";
+my $VERSION = "PulledPork v0.7.1 - Swine Flu with a side of Ebola!";
 my $ua      = LWP::UserAgent->new;
 
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
@@ -144,11 +145,11 @@ sub Help {
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
@@ -176,6 +177,7 @@ sub Help {
    -V Print Version and exit
    -v Verbose mode, you know.. for troubleshooting and such nonsense.
    -vv EXTRA Verbose mode, you know.. for in-depth troubleshooting and other such nonsense.
+   -w Skip the SSL verification (if there are issues pulling down rule files)
 __EOT
 
     exit(0);
@@ -191,7 +193,7 @@ sub pulledpork {
      `----,\\    )
       `--==\\\\  /    $VERSION
        `--==\\\\/
-     .-~~~~-.Y|\\\\_  Copyright (C) 2009-2013 JJ Cummings
+     .-~~~~-.Y|\\\\_  Copyright (C) 2009-2014 JJ Cummings
   \@_/        /  66\\_  cummingsj\@gmail.com
     |    \\   \\   _(\")
      \\   /-| ||'--'  Rules give me wings!
@@ -350,9 +352,27 @@ sub compare_md5 {
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
@@ -1507,7 +1527,8 @@ GetOptions(
     "u=s"    => \@base_url,
     "V!"     => sub { Version() },
     "v+"     => \$Verbose,
-    "help|?" => sub { Help() }
+    "help|?" => sub { Help() },
+    "w" => \$skipVerify
 );
 
 ## Fly piggy fly!
@@ -1533,7 +1554,7 @@ if ( $Verbose && !$Quiet ) {
 if ( exists $Config_info{'version'} ) {
     croak "You are not using the current version of pulledpork.conf!\n",
       "Please use the version of pulledpork.conf that shipped with $VERSION!\n\n"
-      if $Config_info{'version'} ne "0.7.0";
+      if $Config_info{'version'} ne "0.7.1";
 }
 else {
     croak
@@ -1700,6 +1721,7 @@ if ( $Verbose && !$Quiet ) {
     if ($Textonly)     { print "\tText Rules only Flag is Set\n"; }
     if ( $Verbose == 2 ) { print "\tExtra Verbose Flag is Set\n"; }
     if ($Verbose)        { print "\tVerbose Flag is Set\n"; }
+    if ($skipVerify)     { print "\tSSL Hostname Verification disabled\n"; }
     if (@base_url)       { print "\tBase URL is: @base_url\n"; }
 }
 
@@ -1717,10 +1739,17 @@ if ( !-d $temp_path ) {
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
