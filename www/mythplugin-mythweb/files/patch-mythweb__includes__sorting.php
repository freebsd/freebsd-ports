--- mythweb/includes/sorting.php.orig	2012-05-30 23:22:20.000000000 +0200
+++ mythweb/includes/sorting.php	2012-07-29 14:17:07.402674096 +0200
@@ -119,7 +119,7 @@
     function by_user_choice(&$a, &$b) {
         foreach ($GLOBALS['user_sort_choice'] as $sort) {
             $function = 'by_'.$sort['field'];
-            $response = $function(&$a, &$b);
+            $response = $function($a, $b);
         // Identical response, go on to the next sort choice
             if (!$response)
                 continue;
