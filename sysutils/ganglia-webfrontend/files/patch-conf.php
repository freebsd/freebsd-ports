
$FreeBSD$

--- conf.php.orig	Mon Nov 10 10:54:16 2003
+++ conf.php	Thu Feb 12 18:40:24 2004
@@ -5,7 +5,7 @@
 #
 $majorversion = 2;
 $minorversion = 5;
-$microversion = 4;
+$microversion = 5;
 #
 # The name of the directory in "./templates" which contains the
 # templates that you want to use. Templates are like a skin for the
@@ -22,12 +22,12 @@
 #$gmetad_root = "/usr/local/gmetad";
 
 # The high-performance gmetad.
-$gmetad_root = "/var/lib/ganglia";
+$gmetad_root = "/var/db/ganglia";
 $rrds = "$gmetad_root/rrds";
 
 # Leave this alone if rrdtool is installed in $gmetad_root,
 # otherwise, change it if it is installed elsewhere (like /usr/bin)
-define("RRDTOOL", "/usr/bin/rrdtool");
+define("RRDTOOL", "%%PREFIX%%/bin/rrdtool");
 
 #
 # If you want to grab data from a different ganglia source specify it here.
