
$FreeBSD$

--- ganglia.php.orig
+++ ganglia.php
@@ -260,8 +260,8 @@
             $request = "/$clustername";
              break;
          case "cluster-summary":
-            xml_set_element_handler($parser, "start_cluster_summary", "end_all");
-            $request = "/$clustername?filter=summary";
+            xml_set_element_handler($parser, "start_cluster", "end_all");
+            $request = "/$clustername";
             break;
          case "node":
          case "host":
