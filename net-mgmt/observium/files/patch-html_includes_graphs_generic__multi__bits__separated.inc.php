--- html/includes/graphs/generic_multi_bits_separated.inc.php.orig	2016-01-15 08:37:56 UTC
+++ html/includes/graphs/generic_multi_bits_separated.inc.php
@@ -76,13 +76,13 @@ foreach ($rrd_list as $rrd)
   $rrd_options .= " VDEF:totout".$i."=outB".$i.",TOTAL";
   $rrd_options .= " VDEF:tot".$i."=octets".$i.",TOTAL";
 
-  if ($i) { $stack="STACK"; }
+  if ($i) { $stack=":STACK"; }
 
   if ($vars['line_graph'])
   {
     $rrd_options .= " LINE1.25:inB".$i."#" . $colour_in . ":'" . $descr . "'";
   } else {
-    $rrd_options .= " AREA:inB".$i."#" . $colour_in . ":'" . $descr . "':$stack";
+    $rrd_options .= " AREA:inB".$i."#" . $colour_in . ":'" . $descr . "'$stack";
   }
   $rrd_options .= " GPRINT:inB".$i.":LAST:%6.2lf%s$units";
   $rrd_options .= " GPRINT:inB".$i.":AVERAGE:%6.2lf%s$units";
@@ -97,7 +97,7 @@ foreach ($rrd_list as $rrd)
     $rrd_options .= " 'LINE1.25:outB".$i."_neg#" . $colour_out . ":" . $descr_out . "'";
   } else {
     $rrd_options  .= " 'HRULE:0#" . $colour_out.":".$descr_out."'";
-    $rrd_optionsb .= " 'AREA:outB".$i."_neg#" . $colour_out . "::$stack'";
+    $rrd_optionsb .= " 'AREA:outB".$i."_neg#" . $colour_out . ":$stack'";
   }
   $rrd_options  .= " GPRINT:outB".$i.":LAST:%6.2lf%s$units";
   $rrd_options  .= " GPRINT:outB".$i.":AVERAGE:%6.2lf%s$units";
