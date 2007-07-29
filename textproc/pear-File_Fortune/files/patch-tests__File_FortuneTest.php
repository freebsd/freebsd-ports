--- ./tests/File_FortuneTest.php.orig	2007-07-12 11:31:59.515214662 +0800
+++ ./tests/File_FortuneTest.php	2007-07-12 11:32:15.386685251 +0800
@@ -49,7 +49,7 @@
      */
     public function setUp()
     {
-        $this->base = $base = dirname(__FILE__) . '/_files/';
+        $this->base = $base = dirname(__FILE__);
         $origBase = $base . '/orig/';
         foreach ($this->fortuneFiles as $file) {
             copy($origBase . $file, $base . $file);
