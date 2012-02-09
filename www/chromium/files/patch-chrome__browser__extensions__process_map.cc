--- chrome/browser/extensions/process_map.cc.orig	2012-01-31 21:06:11.000000000 +0200
+++ chrome/browser/extensions/process_map.cc	2012-01-31 21:06:50.000000000 +0200
@@ -11,7 +11,7 @@
   Item() {
   }
 
-  explicit Item(const ProcessMap::Item& other)
+  Item(const ProcessMap::Item& other)
       : extension_id(other.extension_id),
         process_id(other.process_id),
         site_instance_id(other.site_instance_id) {
