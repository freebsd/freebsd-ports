--- ./Install.pl.orig	2009-05-11 05:39:12.000000000 +0000
+++ ./Install.pl	2009-05-11 05:46:51.000000000 +0000
@@ -7,38 +7,11 @@
 chop $version;
 close VERSION;
 
-print <<"EOF";
-
-Welcome to the installation of SMB2WWW, release $version. 
-Press <Return> to continue, or press <Ctrl-C> to stop.
-EOF
 
-$foo=<STDIN>;
-
-
-if ($is_root == 1) {
-  while (! getpwnam($uname)) {
-    print "$uname is not a valid username.\n" if (! $uname eq ""); 
-    print "What username shall I use to install smb2www [www-data] ? ";
-    $uname=<STDIN>;
-    chop $uname;
-    $uname = "www-data" if ($uname eq "");
-  }
-
-  while (! getgrnam($gname)) {
-    print "$gname is not a valid groupname.\n" if (! $gname eq "");
-    print "What groupname shall I use to install smb2www [www-data] ? ";
-    $gname= <STDIN>;
-    chop $gname;
-    $gname = "www-data" if ($gname eq "");
-  }
-}
+$uname = 'nobody';
+$gname = 'nobody';
 
-print "Where shall I put smb2www [/usr/local/smb2www] ? ";
-$dir=<STDIN>; chop $dir;
-if ( $dir eq "") { $dir = "/usr/local/smb2www" };
-print "\n";
-die "Directory already exists ! Move first before continuing !" if ( -d $dir);
+$dir = '/usr/local/www/smb2www';
 mkdir "$dir",0755 or die "Unable to create directory ! Check your permissions.";
 
 print "\nDirectory $dir created successfully.\nNow creating subdirectories.\n";
@@ -57,54 +30,24 @@
   print "done.\n\n";
 }
 
-$smbc = "";
-while (not -x "$smbc/smbclient" ) {
-  print "In which directory is smbclient located [/usr/local/samba/bin] ? ";
-  $smbc=<STDIN>; chop $smbc;
-  if ( $smbc eq "") { $smbc = "/usr/local/samba/bin" }; 
-  print "\n";
-}
+$smbc = "/usr/local/bin";
 
 symlink "$smbc/smbclient","$dir/bin/smbclient" or die "unable to symlink smbclient to $dir/bin !\n";
 
-$perl = "";
-while (not -x "$perl" ){
-  print "What is your perl 5 binary [/usr/bin/perl] ? ";
-  $perl=<STDIN>; chop $perl;
-  if ( $perl eq "") { $perl = "/usr/bin/perl" };
-  print "\n";
-}
+$perl = "/usr/bin/perl";
 
-print "Which server shall I use as master browser ? ";
-$mbrowse=<STDIN>; chop $mbrowse;
-print "\n";
+$mbrowse='localhost';
 
 srand ( time ^ ($$ + ($$ << 15)) );
 while (length $key < 25) {
   $key = $key.chr(rand(64)+64); 
 }
-print "Which language would you like to use with SMB2WWW ?\n   (english dutch finnish) [english] ";
-$language = <STDIN>; chop $language;
-if ( $language eq "" ) { $language = "english" };
-print "\n";
-
-
-
-print "Which path shall I use for SMB2WWW pictures on your webserver\n[/smbimg] ? ";
-$imgpath=<STDIN>; chop $imgpath;
-if ( $imgpath eq "" ) { $imgpath = "/smbimg" };
-print "\n";	
+$language = 'english';
 
-print "Which path shall I use as SMB2WWW root on your webserver [/samba] ? ";
-$cgiroot=<STDIN>; chop $cgiroot;
-if ( $cgiroot eq "" ) { $cgiroot = "/samba" };
-print "\n";
+$imgpath='/sbming';
+$cgiroot='/samba';
 
-print "Where is your mime.types file [/etc] ? ";
-$mime=<STDIN>; chop $mime;
-if ( $mime eq "" ) { $mime = "/etc" };
-$mime= $mime."/mime.types";
-print "\n";
+$mime='/usr/local/etc/apache';
 
 print "Now modifying scripts and configuration files...\n\n";
 
@@ -124,7 +67,7 @@
 cfgdir        = $dir/etc
 imgroot       = $imgpath
 cgiroot       = $cgiroot
-linkto_other  = http://samba.anu.edu.au/samba/smb2www/
+linkto_other  = http://www.samba.org/samba/smb2www/
 background    = cloud.gif
 icon_other    = world.gif
 icon_all      = network.gif
@@ -209,6 +152,6 @@
 print "\nAdd this to your apache config:\n";
 print "-------------------------------\n\n";
 print "Alias $imgpath $dir/images\n";
-print "ScriptAlias $cgiroot/ $dir/cgi-bin\n";
+print "ScriptAlias $cgiroot/ $dir/cgi-bin/\n";
 
 print "\nThank you for using SMB2WWW.\n\n";
