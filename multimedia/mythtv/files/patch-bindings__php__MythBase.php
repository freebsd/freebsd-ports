--- bindings/php/MythBase.php.orig	2012-07-16 17:21:00.000000000 +0200
+++ bindings/php/MythBase.php	2012-07-29 14:13:02.915720097 +0200
@@ -47,7 +47,7 @@
 
     public function __destruct() {
         if (!is_null($this->cacheKey))
-            Cache::setObject($this->cacheKey, &$this, $this->cacheLifetime);
+            Cache::setObject($this->cacheKey, $this, $this->cacheLifetime);
         $this->cacheKey = null;
     }
 
