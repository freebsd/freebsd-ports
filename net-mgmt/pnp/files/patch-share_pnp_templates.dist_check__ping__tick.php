--- share/pnp/templates.dist/check_ping_tick.php.orig	2017-03-21 13:39:12 UTC
+++ share/pnp/templates.dist/check_ping_tick.php
@@ -6,7 +6,7 @@
 # RTA
 #
 $ds_name[1] = "Round Trip Times";
-$opt[1]  = "--lower=0 --vertical-label \"RTA\" --title \"Ping times\" ";
+$opt[1]  = "--lower-limit=0 --vertical-label \"RTA\" --title \"Ping times\" ";
 $opt[1] .=  rrd::darkteint();
 $def[1]  =  rrd::def("var1", $RRDFILE[1], $DS[1], "AVERAGE") ;
 $def[1] .=  rrd::ticker("var1", $WARN[1], $CRIT[1]) ;
