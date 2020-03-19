--- library/vendor/Zend/Registry.php.orig	2019-10-18 05:39:24 UTC
+++ library/vendor/Zend/Registry.php
@@ -190,15 +190,4 @@ class Zend_Registry extends ArrayObject
         parent::__construct($array, $flags);
     }
 
-    /**
-     * @param string $index
-     * @returns mixed
-     *
-     * Workaround for http://bugs.php.net/bug.php?id=40442 (ZF-960).
-     */
-    public function offsetExists($index)
-    {
-        return array_key_exists($index, $this);
-    }
-
 }
