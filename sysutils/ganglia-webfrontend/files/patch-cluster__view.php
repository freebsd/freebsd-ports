
$FreeBSD$

--- cluster_view.php.orig
+++ cluster_view.php
@@ -6,11 +6,11 @@
 
 $tpl->assign("images","./templates/$template_name/images");
 
-$cpu_num = !$showhosts ? $metrics["cpu_num"][SUM] : cluster_sum("cpu_num", $metrics);
-$load_one_sum = !$showhosts ? $metrics["load_one"][SUM] : cluster_sum("load_one", $metrics);
-$load_five_sum = !$showhosts ? $metrics["load_five"][SUM] : cluster_sum("load_five", $metrics);
-$load_fifteen_sum = !$showhosts ? $metrics["load_fifteen"][SUM] : cluster_sum("load_fifteen", $metrics);
-$units = !$showhosts ? $metrics[$metricname][UNITS] : $metrics[key($metrics)][$metricname][UNITS];
+$cpu_num = cluster_sum("cpu_num", $metrics);
+$load_one_sum = cluster_sum("load_one", $metrics);
+$load_five_sum = cluster_sum("load_five", $metrics);
+$load_fifteen_sum = cluster_sum("load_fifteen", $metrics);
+$units = $metrics[key($metrics)][$metricname][UNITS];
 
 $tpl->assign("num_nodes", intval($cluster[HOSTS_UP]));
 $tpl->assign("num_dead_nodes", intval($cluster[HOSTS_DOWN]));
