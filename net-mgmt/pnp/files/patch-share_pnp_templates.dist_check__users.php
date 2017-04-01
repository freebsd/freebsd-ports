--- share/pnp/templates.dist/check_users.php.orig	2017-03-21 13:39:19 UTC
+++ share/pnp/templates.dist/check_users.php
@@ -4,7 +4,7 @@
 # Template for check_users
 #
 
-$opt[1] = "--lower=$MIN[1] --vertical-label \"Users\"  --title \"Users\" ";
+$opt[1] = "--lower-limit=$MIN[1] --vertical-label \"Users\"  --title \"Users\" ";
 
 
 $def[1] =  "DEF:var1=$RRDFILE[1]:$DS[1]:MAX " ;
