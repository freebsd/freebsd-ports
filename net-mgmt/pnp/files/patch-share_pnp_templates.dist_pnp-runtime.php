--- share/pnp/templates.dist/pnp-runtime.php.orig	2017-08-21 15:52:37 UTC
+++ share/pnp/templates.dist/pnp-runtime.php
@@ -34,7 +34,7 @@ $opt[2] = "--vertical-label \"Counter\" --title \"Numb
 #
 $ds_name[2] = "Errors and updates";
 $def[2] = '';
-for($i=2; $i <= sizeof($DS); $i++) {
+for($i=2; $i <= count($DS); $i++) {
 $def[2] .=  rrd::def("var$i", $RRDFILE[$i], $DS[$i] , "AVERAGE") ;
 $def[2] .= rrd::line1("var$i", rrd::color($i), rrd::cut(ucfirst($LABEL[$i]),12) );
 $def[2] .= rrd::gprint("var$i", array('LAST', 'MAX', 'AVERAGE'), "%4.0lf$UNIT[$i]");
