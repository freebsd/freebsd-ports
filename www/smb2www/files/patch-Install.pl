--- Install.pl.orig	Sun Aug  2 21:31:40 1998
+++ Install.pl	Sun Mar 25 17:53:37 2001
@@ -19,24 +19,24 @@
 if ($is_root == 1) {
   while (! getpwnam($uname)) {
     print "$uname is not a valid username.\n" if (! $uname eq ""); 
-    print "What username shall I use to install smb2www [www-data] ? ";
+    print "What username shall I use to install smb2www [nobody] ? ";
     $uname=<STDIN>;
     chop $uname;
-    $uname = "www-data" if ($uname eq "");
+    $uname = "nobody" if ($uname eq "");
   }
 
   while (! getgrnam($gname)) {
     print "$gname is not a valid groupname.\n" if (! $gname eq "");
-    print "What groupname shall I use to install smb2www [www-data] ? ";
+    print "What groupname shall I use to install smb2www [nobody] ? ";
     $gname= <STDIN>;
     chop $gname;
-    $gname = "www-data" if ($gname eq "");
+    $gname = "nobody" if ($gname eq "");
   }
 }
 
-print "Where shall I put smb2www [/usr/local/smb2www] ? ";
+print "Where shall I put smb2www [/usr/local/www/smb2www] ? ";
 $dir=<STDIN>; chop $dir;
-if ( $dir eq "") { $dir = "/usr/local/smb2www" };
+if ( $dir eq "") { $dir = "/usr/local/www/smb2www" };
 print "\n";
 die "Directory already exists ! Move first before continuing !" if ( -d $dir);
 mkdir "$dir",0755 or die "Unable to create directory ! Check your permissions.";
@@ -59,9 +59,9 @@
 
 $smbc = "";
 while (not -x "$smbc/smbclient" ) {
-  print "In which directory is smbclient located [/usr/local/samba/bin] ? ";
+  print "In which directory is smbclient located [/usr/local/bin] ? ";
   $smbc=<STDIN>; chop $smbc;
-  if ( $smbc eq "") { $smbc = "/usr/local/samba/bin" }; 
+  if ( $smbc eq "") { $smbc = "/usr/local/bin" }; 
   print "\n";
 }
 
@@ -100,9 +100,9 @@
 if ( $cgiroot eq "" ) { $cgiroot = "/samba" };
 print "\n";
 
-print "Where is your mime.types file [/etc] ? ";
+print "Where is your mime.types file [/usr/local/etc/apache] ? ";
 $mime=<STDIN>; chop $mime;
-if ( $mime eq "" ) { $mime = "/etc" };
+if ( $mime eq "" ) { $mime = "/usr/local/etc/apache" };
 $mime= $mime."/mime.types";
 print "\n";
 
@@ -124,7 +124,7 @@
 cfgdir        = $dir/etc
 imgroot       = $imgpath
 cgiroot       = $cgiroot
-linkto_other  = http://samba.anu.edu.au/samba/smb2www/
+linkto_other  = http://www.samba.org/samba/smb2www/
 background    = cloud.gif
 icon_other    = world.gif
 icon_all      = network.gif
@@ -209,6 +209,6 @@
 print "\nAdd this to your apache config:\n";
 print "-------------------------------\n\n";
 print "Alias $imgpath $dir/images\n";
-print "ScriptAlias $cgiroot/ $dir/cgi-bin\n";
+print "ScriptAlias $cgiroot/ $dir/cgi-bin/\n";
 
 print "\nThank you for using SMB2WWW.\n\n";
