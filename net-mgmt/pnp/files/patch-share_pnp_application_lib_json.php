--- share/pnp/application/lib/json.php.orig	2017-08-21 15:52:37 UTC
+++ share/pnp/application/lib/json.php
@@ -375,7 +375,7 @@ class Services_JSON
                 */
 
                 // treat as a JSON object
-                if (is_array($var) && count($var) && (array_keys($var) !== range(0, sizeof($var) - 1))) {
+                if (is_array($var) && count($var) && (array_keys($var) !== range(0, count($var) - 1))) {
                     $properties = array_map(array($this, 'name_value'),
                                             array_keys($var),
                                             array_values($var));
