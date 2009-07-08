--- ./wginstall.pl.orig	1998-09-25 11:34:42.000000000 -0400
+++ ./wginstall.pl	2009-07-07 22:30:26.504066256 -0400
@@ -31,7 +31,7 @@
 
 
 # Get operating system
-$LEGALOS = 'linux osf sunos solaris';
+#$LEGALOS = 'linux osf sunos solaris freebsd';
 $DEFAULTOS = 'linux';
 $PLATFORM = $ARGV[1] || $^O || '';
 
@@ -46,16 +46,16 @@
 }
 
 
-do {
-    $PLATFORM = prompt("What OS are you running (must be one of $LEGALOS)?", $PLATFORM);
-} while ($LEGALOS !~ /$PLATFORM/);
+#do {
+#    $PLATFORM = prompt("What OS are you running (must be one of $LEGALOS)?", $PLATFORM);
+#} while ($LEGALOS !~ /$PLATFORM/);
 
 ###########################################################
 # Make sure we can find needed system binaries
 # Since not all systems have which, we make a guess if which fails
 #
 # get the paths for perl and glimpse
-$PERL = $ARGV[0] || `which perl` || '/usr/local/bin/perl';
+$PERL = '%PERL%';
 $CONVERT_LOC = `which wgconvert` || '/usr/local/bin/wgconvert';
 $GLIMPSE_LOC = `which glimpse` || '/usr/local/bin/glimpse';
 $GLIMPSEIDX_LOC = `which glimpseindex` || '/usr/local/bin/glimpseindex';
@@ -168,9 +168,10 @@
 }
 chomp $guess;
 if (($guess eq '')||($guess eq '.')) {
-	$guess = '/usr/local/webglimpse';
+	$guess = '/usr/local/www/webglimpse';
 }
-$WEBGLIMPSE_HOME = prompt('Webglimpse Home Directory: ', $guess);
+#$WEBGLIMPSE_HOME = prompt('Webglimpse Home Directory: ', $guess);
+$WEBGLIMPSE_HOME = $guess;
 
 # Remove any trailing '/'
 if ($WEBGLIMPSE_HOME =~ /\/$/) { 
@@ -211,12 +212,12 @@
 # Check if .wgsiteconf already exists
 $HAVECONFIG = 'N';
 if ( -e "$WEBGLIMPSE_HOME/.wgsiteconf" ) {
-	$HAVECONFIG = prompt('Existing installation found.  Keep configuration info? (Y/n)', 'Y');
-	if ($HAVECONFIG =~ /^[yY]/) {
+#       $HAVECONFIG = prompt('Existing installation found.  Keep configuration info? (Y/n)', 'Y');
+#       if ($HAVECONFIG =~ /^[yY]/) {
 		$HAVECONFIG = 'Y';
-	} else {
-		$HAVECONFIG = 'N';
-	}
+#       } else {
+#               $HAVECONFIG = 'N';
+#       }
 }
 
 #######################################################################
@@ -225,53 +226,53 @@
 #
 if ($HAVECONFIG eq 'N') {
 
-	print "\nI will now ask you some questions about your HTTP server.\n";
-	print "Automatic configuration is supported for Apache servers v1.2 and above\n";
-	print "If you do not have an Apache server, you may need to edit the file\n";
-	print "$WEBGLIMPSE_HOME/.wgsiteconf by hand after the installation is completed.\n\n";
-
+#        print "\nI will now ask you some questions about your HTTP server.\n";
+#        print "Automatic configuration is supported for Apache servers v1.2 and above\n";
+#        print "If you do not have an Apache server, you may need to edit the file\n";
+#        print "$WEBGLIMPSE_HOME/.wgsiteconf by hand after the installation is completed.\n\n";
+#
 	#		
 	# Try to guess the configuration directory/file from the process list
 	#
-	$allprocs = `ps -a` || '';
-	$confdir = '';
-	$conffile = '';
-	if ($allprocs ne '') {
-		@allprocs = split(/\n/,$allprocs);
-		foreach $proc ( @allprocs ) {
-			if ($proc =~ /httpd/) {
-				if ($proc =~ / -f (\S+)/) {
-					$conffile = $1;
-				}
-				if ($proc =~ / -d (\S+)/) {
-					$confdir = $1;
-				}
-				last;
-			}
-		}
-	}
-	$HTTPD_CONF = '';
-	if ($conffile ne '') {
-		# Usually the daemon is run as httpd -f /path/httpd.conf
-		$HTTPD_CONF = $conffile;
-	}
-
- 	if ($confdir ne '') {
-		if ($confdir =~ /\/$/) {
-			chop $confdir;
-		}
-		if ($HTTPD_CONF eq '') {
-			$HTTPD_CONF = 'httpd.conf';
-		}
-		$HTTPD_CONF = $confdir.'/'.$HTTPD_CONF;
-	} 
-
-	if ($HTTPD_CONF eq '') {
-		$HTTPD_CONF = '/usr/local/etc/httpd/conf/httpd.conf';
-	}
+#        $allprocs = `ps -a` || '';
+#        $confdir = '';
+#        $conffile = '';
+#        if ($allprocs ne '') {
+#                @allprocs = split(/\n/,$allprocs);
+#                foreach $proc ( @allprocs ) {
+#                        if ($proc =~ /httpd/) {
+#                                if ($proc =~ / -f (\S+)/) {
+#                                        $conffile = $1;
+#                                }
+#                                if ($proc =~ / -d (\S+)/) {
+#                                        $confdir = $1;
+#                                }
+#                                last;
+#                        }
+#                }
+#        }
+#        $HTTPD_CONF = '';
+#        if ($conffile ne '') {
+#                # Usually the daemon is run as httpd -f /path/httpd.conf
+#                $HTTPD_CONF = $conffile;
+#        }
+#
+#        if ($confdir ne '') {
+#                if ($confdir =~ /\/$/) {
+#                        chop $confdir;
+#                }
+#                if ($HTTPD_CONF eq '') {
+#                        $HTTPD_CONF = 'httpd.conf';
+#                }
+#                $HTTPD_CONF = $confdir.'/'.$HTTPD_CONF;
+#        }
+#
+#        if ($HTTPD_CONF eq '') {
+		$HTTPD_CONF = '/usr/local/etc/apache/httpd.conf';
+#        }
 
 	# Check with the user if our guess is right.
-	$HTTPD_CONF = &prompt('Full path to HTTP server config file: ',$HTTPD_CONF);
+#        $HTTPD_CONF = &prompt('Full path to HTTP server config file: ',$HTTPD_CONF);
 
 	########################################################################
 	# Call wgSiteConfig from wgserver.pl to parse server config file
@@ -351,13 +352,13 @@
 
 
 # Prompt user no matter what; we may be overwriting a file here.
-$CGIBIN_PWD = 
-	&prompt("Which directory should I copy the WebGlimpse cgi-bin scripts to?\nIf you choose a different\ndirectory than the default, make sure it exists.\n",
-	"$CGIBIN_PWD");
+#$CGIBIN_PWD =
+#        &prompt("Which directory should I copy the WebGlimpse cgi-bin scripts to?\nIf you choose a different\ndirectory than the default, make sure it exists.\n",
+#        "$CGIBIN_PWD");
 
-$CGIBIN = 
-	&prompt("What is the script alias for $CGIBIN_PWD?",
-		$CGIBIN);
+#$CGIBIN =
+#        &prompt("What is the script alias for $CGIBIN_PWD?",
+#                $CGIBIN);
 
 # If this is news to us, add/change the WGSCRIPTALIAS line to the site config file
 $wg_added = 0;
@@ -435,8 +436,8 @@
 print "cgi-bin *relative* URL: $CGIBIN\n";
 print "-----------------------------------------------------\n";
 
-print "To continue with these settings, press RETURN.  Otherwise, press ^C to abort.\n";
-$_=<STDIN>;
+#print "To continue with these settings, press RETURN.  Otherwise, press ^C to abort.\n";
+#$_=<STDIN>;
 
 
 # build local copy of httpget and html2txt
@@ -491,6 +492,7 @@
 					"OutputTool.pm", # New with v1.6b3
 					"config.pl",
 					"httpget.c",
+					"html2txt.c",
 					"url_get");
 
 @optlibfiles = (			"CustomOutputTool.pm", # New with v1.6b4 - only distributed w/commercial version
@@ -606,11 +608,11 @@
 
 print "Webglimpse installation complete.\n\n";
 
-print "**NOTE: You may need to edit your web server configuration file \n";
-print "and specify $CGIBIN_PWD as a cgi-bin directory.\n";
-print "For Apache, use the ScriptAlias directive.\n\n";
-print("Press RETURN to continue\n");
-<STDIN>;
+#print "**NOTE: You may need to edit your web server configuration file \n";
+#print "and specify $CGIBIN_PWD as a cgi-bin directory.\n";
+#print "For Apache, use the ScriptAlias directive.\n\n";
+#print("Press RETURN to continue\n");
+#<STDIN>;
 
 
 print "\nSee http://glimpse.cs.arizona.edu/webglimpse for more\n";
@@ -619,25 +621,25 @@
 print "You may configure an archive at any time with the command \n";
 print "$WEBGLIMPSE_HOME/confarc\n\n";
 
-print "To configure one or more archives now, just enter the directory to index or URL to traverse.\n";
-print "A directory should be a full path starting with   /  \n";
-print "A URL should be absolute starting with    http://  \n\n";
+#print "To configure one or more archives now, just enter the directory to index or URL to traverse.\n";
+#print "A directory should be a full path starting with   /  \n";
+#print "A URL should be absolute starting with    http://  \n\n";
 
-$archivepath = &prompt("Enter directory or URL to index, return to quit:", '');
-while($archivepath ne '') {
+#$archivepath = &prompt("Enter directory or URL to index, return to quit:", '');
+#while($archivepath ne '') {
 
 	# We want to make certain simplified assumptions here.
 	# User can get full flexibility by running confarc from
 	# command line later.
-	$type = 'D';
-	if ($archivepath =~ /^http/) {
-		$type = 'T';
-	}
+#        $type = 'D';
+#        if ($archivepath =~ /^http/) {
+#                $type = 'T';
+#        }
 
-	system("$WEBGLIMPSE_HOME/confarc -i $archivepath -t $type -l $archivepath");
+#        system("$WEBGLIMPSE_HOME/confarc -i $archivepath -t $type -l $archivepath");
 
-	$archivepath = &prompt("Enter directory or URL to index, return to quit:", '');
-}
+#        $archivepath = &prompt("Enter directory or URL to index, return to quit:", '');
+#}
 
 1;
 
@@ -703,8 +705,8 @@
 			print TEMP "\$CGIBIN = \"$CGIBIN\";\n";
 		}elsif(/^\$gunzip *=/){
 			print TEMP "\$gunzip = \"$gunzip\";\n";
-		}elsif(/^#!\/usr\/local\/bin\/perl$/){
-			print TEMP "#!$PERL\n";
+		}elsif(/^#!\/usr\/local\/bin[^ ]*\/perl(.*)/){
+			print TEMP "#!$PERL$1\n";
 		}else{
 			print TEMP $_;
 		}
