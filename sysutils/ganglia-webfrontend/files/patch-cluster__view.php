--- cluster_view.php.orig	2018-09-20 22:57:59 UTC
+++ cluster_view.php
@@ -23,7 +23,7 @@ if ($refresh) {
 }
 
 function get_picker_metrics($metrics, $reports, $gweb_root, $graph_engine) {
-  $context_metrics = "";
+  $context_metrics = array();
   if (count($metrics)) {
     foreach ($metrics as $host_metrics) {
       foreach ($host_metrics as $metric_name => $metric_value) {
