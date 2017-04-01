--- share/pnp/templates.dist/check_dns.php.orig	2017-03-21 13:39:01 UTC
+++ share/pnp/templates.dist/check_dns.php
@@ -4,7 +4,7 @@
 # Template for check_dns
 #
 
-$opt[1] = "--lower=$MIN[1] --vertical-label $UNIT[1]  --title \"DNS Response Time\" ";
+$opt[1] = "--lower-limit=$MIN[1] --vertical-label $UNIT[1]  --title \"DNS Response Time\" ";
 
 
 $def[1] =  "DEF:var1=$RRDFILE[1]:$DS[1]:AVERAGE " ;
