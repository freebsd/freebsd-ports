--- vendor/sabre/dav/lib/CardDAV/Plugin.php.orig	2017-04-13 09:06:24 UTC
+++ vendor/sabre/dav/lib/CardDAV/Plugin.php
@@ -450,7 +450,8 @@ class Plugin extends DAV\ServerPlugin {
 
                 $props[200]['{' . self::NS_CARDDAV . '}address-data'] = $this->convertVCard(
                     $props[200]['{' . self::NS_CARDDAV . '}address-data'],
-                    $vcardType
+                    $vcardType,
+                    $report->addressDataProperties
                 );
 
             }
@@ -807,12 +808,24 @@ class Plugin extends DAV\ServerPlugin {
      * @param string $target
      * @return string
      */
-    protected function convertVCard($data, $target) {
+    protected function convertVCard($data, $target, array $propertiesFilter = null) {
 
         if (is_resource($data)) {
             $data = stream_get_contents($data);
         }
         $input = VObject\Reader::read($data);
+        if (!empty($propertiesFilter)) {
+            $propertiesFilter = array_merge(['UID', 'VERSION', 'FN'], $propertiesFilter);
+            $keys = array_unique(array_map(function($child) {
+                return $child->name;
+            }, $input->children()));
+            $keys = array_diff($keys, $propertiesFilter);
+            $str = "";
+            foreach ($keys as $key) {
+                unset($input->$key);
+            }
+            $data = $input->serialize();
+        }
         $output = null;
         try {
 
