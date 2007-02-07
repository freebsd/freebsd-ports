--- html/inc/drawrrd.php.orig	Wed Dec 20 17:09:25 2006
+++ html/inc/drawrrd.php	Mon Feb  5 19:51:47 2007
@@ -7,7 +7,7 @@
 //===============================
 */
 $rrdcmd  = "rrdtool";										# point to rrdtool
-$rrdpath = "/var/nedi/rrd";									# point to rrds
+$rrdpath = "/usr/local/www/nedi/rrd";									# point to rrds
 
 # The above is the FASTEST way. People may argue to put this in nedi.conf. This enables 2 more ways, but I won't do it...
 # LITTLE SLOWER and as dirty as above:
