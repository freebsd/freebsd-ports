--- DrupalTextile.inc.orig	Fri Dec  8 13:01:07 2006
+++ DrupalTextile.inc	Fri Dec  8 13:00:49 2006
@@ -38,11 +38,17 @@
    *    A <code>string</code> containing the formatted URL.
    */
   function format_url($args) {
+    $query = null;
+    if (preg_match ('/([^\?]*)\?(.*)/', $args['url'], $matches)) {
+      $args['url'] = $matches[1];
+      $query = $matches[2];
+    }
+
     if (preg_match('<^#>', $args['url'])) {
       $args['url'] = $_GET['q'] . $args['url'];
     }
 
-    $args['url'] = ($args['url'] ? url($args['url']) : '');
+    $args['url'] = ($args['url'] ? url($args['url'], $query) : '');
 
     return parent::format_url($args);
   }
