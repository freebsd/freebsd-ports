--- Mail/Queue.php.orig	2016-12-15 17:08:51 UTC
+++ Mail/Queue.php
@@ -587,7 +587,7 @@ class Mail_Queue extends PEAR
      * @return  boolean   whether $value is an MAILQUEUE_ERROR
      * @access public
      */
-    function isError($value)
+    static function isError($value)
     {
         return (is_object($value) && is_a($value, 'pear_error'));
     }
