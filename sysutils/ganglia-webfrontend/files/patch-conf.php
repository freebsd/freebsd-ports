
$FreeBSD$

--- conf.php.orig	Thu Feb 20 18:10:49 2003
+++ conf.php	Thu Feb 20 18:14:37 2003
@@ -22,12 +22,12 @@
 #$gmetad_root = "/usr/local/gmetad";
 
 # The high-performance gmetad.
-$gmetad_root = "/var/lib/ganglia";
+$gmetad_root = "/var/db/ganglia";
 $rrds = "$gmetad_root/rrds";
 
 # Leave this alone if rrdtool is installed in $gmetad_root,
 # otherwise, change it if it's installed elsewhere (like /usr/bin)
-define("RRDTOOL", "/usr/bin/rrdtool");
+define("RRDTOOL", "%%PREFIX%%/bin/rrdtool");
 
 #
 # If you want to grab data from a different ganglia source specify it here.
