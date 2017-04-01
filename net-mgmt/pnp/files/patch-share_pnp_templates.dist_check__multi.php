--- share/pnp/templates.dist/check_multi.php.orig	2017-03-21 13:39:07 UTC
+++ share/pnp/templates.dist/check_multi.php
@@ -4,7 +4,7 @@
 # Template for check_multi
 # 
 
-$opt[1] = "--lower=$MIN[1] --vertical-label num  --title \"Number of Checks\" ";
+$opt[1] = "--lower-limit=$MIN[1] --vertical-label num  --title \"Number of Checks\" ";
 $ds_name[1] = "Executed Plugins";
 
 $def[1] =  "DEF:var1=$RRDFILE[1]:$DS[1]:AVERAGE " ;
