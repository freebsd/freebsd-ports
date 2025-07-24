--- scripts/logwatch.pl.orig	2025-07-21 23:56:15 UTC
+++ scripts/logwatch.pl
@@ -106,20 +106,20 @@ $Config{'appendcwdtologdirs'} = 0;
 $Config{'appendvarlogtologdirs'} = 1;
 $Config{'appendcwdtologdirs'} = 0;
 
-if (-e "$ConfigDir/conf/html/header.html") {
-   $Config{'html_header'} = "$ConfigDir/conf/html/header.html";
-} elsif (-e "$BaseDir/dist.conf/html/header.html") {
-   $Config{'html_header'} = "$BaseDir/dist.conf/html/header.html";
+if (-e "$ConfigDir/html/header.html") {
+   $Config{'html_header'} = "$ConfigDir/html/header.html";
+} elsif (-e "$ConfigDir/defaults/html/header.html") {
+   $Config{'html_header'} = "$ConfigDir/defaults/html/header.html";
 } else {
-   $Config{'html_header'} = "$BaseDir/default.conf/html/header.html";
+   $Config{'html_header'} = "$ConfigDir/defaults/html/header.html";
 }
 
-if (-e "$ConfigDir/conf/html/footer.html") {
-   $Config{'html_footer'} = "$ConfigDir/conf/html/footer.html";
-} elsif (-e "$BaseDir/dist.conf/html/footer.html") {
-   $Config{'html_footer'} = "$BaseDir/dist.conf/html/footer.html";
+if (-e "$ConfigDir/html/footer.html") {
+   $Config{'html_footer'} = "$ConfigDir/html/footer.html";
+} elsif (-e "$ConfigDir/defaults/html/footer.html") {
+   $Config{'html_footer'} = "$ConfigDir/defaults/html/footer.html";
 } else {
-   $Config{'html_footer'} = "$BaseDir/default.conf/html/footer.html";
+   $Config{'html_footer'} = "$ConfigDir/defaults/html/footer.html";
 }
 
 #Added to create switches for different os options -mgt
@@ -157,10 +157,10 @@ if ($Config{'debug'} > 8) {
 @ReadConfigNames = ();
 @ReadConfigValues = ();
 
-&ReadConfigFile ("$BaseDir/default.conf/logwatch.conf", "");
-&ReadConfigFile ("$BaseDir/dist.conf/logwatch.conf", "");
-&ReadConfigFile ("$ConfigDir/conf/logwatch.conf", "");
-&ReadConfigFile ("$ConfigDir/conf/override.conf", "logwatch");
+&ReadConfigFile ("$ConfigDir/defaults/logwatch.conf", "");
+&ReadConfigFile ("$ConfigDir/defaults/logwatch.conf", "");
+&ReadConfigFile ("$ConfigDir/logwatch.conf", "");
+&ReadConfigFile ("$ConfigDir/override.conf", "logwatch");
 
 
 for (my $i = 0; $i <= $#ReadConfigNames; $i++) {
@@ -350,7 +350,7 @@ my (@CmdList, @CmdArgList, @Separators, $ThisFile, $co
 my (@CmdList, @CmdArgList, @Separators, $ThisFile, $count);
 
 
-foreach my $ServicesDir ("$BaseDir/default.conf", "$BaseDir/dist.conf", "$ConfigDir/conf") {
+foreach my $ServicesDir ("$ConfigDir/defaults", "$ConfigDir/defaults", "$ConfigDir") {
    if (-d "$ServicesDir/services") {
       opendir(SERVICESDIR, "$ServicesDir/services") or
          die "$ServicesDir $!";
@@ -374,13 +374,13 @@ foreach my $f (@services) {
    @ReadConfigValues = ();
    @Separators = ();
    push (@Separators, scalar(@ReadConfigNames));
-   &ReadConfigFile("$BaseDir/default.conf/services/$f", "");
+   &ReadConfigFile("$ConfigDir/defaults/services/$f", "");
    push (@Separators, scalar(@ReadConfigNames));
-   &ReadConfigFile("$BaseDir/dist.conf/services/$f", "");
+   &ReadConfigFile("$ConfigDir/defaults/services/$f", "");
    push (@Separators, scalar(@ReadConfigNames));
-   &ReadConfigFile("$ConfigDir/conf/services/$f","");
+   &ReadConfigFile("$ConfigDir/services/$f","");
    push (@Separators, scalar(@ReadConfigNames));
-   &ReadConfigFile("$ConfigDir/conf/override.conf", "services/$ThisService");
+   &ReadConfigFile("$ConfigDir/override.conf", "services/$ThisService");
 
    @CmdList = ();
    @CmdArgList = ();
@@ -419,7 +419,7 @@ my @logfiles = ();
 
 # Find out what logfiles are defined...
 my @logfiles = ();
-foreach my $LogfilesDir ("$BaseDir/default.conf", "$BaseDir/dist.conf", "$ConfigDir/conf") {
+foreach my $LogfilesDir ("$ConfigDir/defaults", "$ConfigDir/defaults", "$ConfigDir") {
    if (-d "$LogfilesDir/logfiles") {
       opendir(LOGFILEDIR, "$LogfilesDir/logfiles") or
          die "$LogfilesDir $!";
@@ -440,13 +440,13 @@ for $ThisFile (@logfiles) {
          @ReadConfigValues = ();
          @Separators = ();
          push (@Separators, scalar(@ReadConfigNames));
-         &ReadConfigFile("$BaseDir/default.conf/logfiles/$ThisFile", "");
+         &ReadConfigFile("$ConfigDir/defaults/logfiles/$ThisFile", "");
          push (@Separators, scalar(@ReadConfigNames));
-         &ReadConfigFile("$BaseDir/dist.conf/logfiles/$ThisFile", "");
+         &ReadConfigFile("$ConfigDir/defaults/logfiles/$ThisFile", "");
          push (@Separators, scalar(@ReadConfigNames));
-         &ReadConfigFile("$ConfigDir/conf/logfiles/$ThisFile", "");
+         &ReadConfigFile("$ConfigDir/logfiles/$ThisFile", "");
          push (@Separators, scalar(@ReadConfigNames));
-         &ReadConfigFile("$ConfigDir/conf/override.conf", "logfiles/$ThisLogFile");
+         &ReadConfigFile("$ConfigDir/override.conf", "logfiles/$ThisLogFile");
 
          @CmdList = ();
          @CmdArgList = ();
@@ -737,7 +737,7 @@ foreach $LogFile (@LogFileList) {
 foreach $LogFile (@LogFileList) {
    next if ($LogFile eq 'none');
 	if (!defined($LogFileData{$LogFile}{'logfiles'})) {
-		print "*** Error: There is no logfile defined. Do you have a $ConfigDir/conf/logfiles/" . $LogFile . ".conf file ?\n";
+		print "*** Error: There is no logfile defined. Do you have a $ConfigDir/logfiles/" . $LogFile . ".conf file ?\n";
 		next;
 	}
 
@@ -1302,18 +1302,14 @@ sub parselogs {
 sub parselogs {
    my $Service;
 
-   #Load our ignore file order is [assume normal install]  /etc/conf, /usr/share/logwatch/dist.conf and then default.conf -mgt
+   #Load our ignore file order is [assume normal install]  /etc/logwatch and then /etc/logwatch/defaults -mgt
    my @IGNORE;
-   if ( -e "$ConfigDir/conf/ignore.conf") {
-      open( IGNORE, "$ConfigDir/conf/ignore.conf" )  or return undef;
+   if ( -e "$ConfigDir/ignore.conf") {
+      open( IGNORE, "$ConfigDir/ignore.conf" )  or return undef;
       @IGNORE = grep {!/(^#|^\s+$)/} <IGNORE>;
       close IGNORE;
-   } elsif ( -e "$BaseDir/dist.conf/ignore.conf") {
-      open( IGNORE, "$BaseDir/dist.conf/ignore.conf" )  or return undef;
-      @IGNORE = grep {!/(^#|^\s+$)/} <IGNORE>;
-      close IGNORE;
-   } elsif ( -e "$BaseDir/default.conf/ignore.conf") {
-      open( IGNORE, "$BaseDir/default.conf/ignore.conf" )  or return undef;
+   } elsif ( -e "$ConfigDir/defaults/ignore.conf") {
+      open( IGNORE, "$ConfigDir/defaults/ignore.conf" )  or return undef;
       @IGNORE = grep {!/(^#|^\s+$)/} <IGNORE>;
       close IGNORE;
    }
