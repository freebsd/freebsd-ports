--- functions/global.php.orig	Fri Feb  3 22:27:47 2006
+++ functions/global.php	Tue Jun  6 10:12:22 2006
@@ -62,6 +62,47 @@
     sqstripslashes($_POST);
 }
 
+/**
+ * If register_globals are on, unregister globals.
+ * Code requires PHP 4.1.0 or newer.
+ * Second test covers boolean set as string (php_value register_globals off).
+ */
+if ((bool) @ini_get('register_globals') &&
+    strtolower(ini_get('register_globals'))!='off') {
+    /**
+     * Remove all globals from $_GET, $_POST, and $_COOKIE.
+     */
+    foreach ($_REQUEST as $key => $value) {
+        unset($GLOBALS[$key]);
+    }
+    /**
+     * Remove globalized $_FILES variables
+     * Before 4.3.0 $_FILES are included in $_REQUEST.
+     * Unglobalize them in separate call in order to remove dependency
+     * on PHP version.
+     */
+    foreach ($_FILES as $key => $value) {
+        unset($GLOBALS[$key]);
+        // there are three undocumented $_FILES globals.
+        unset($GLOBALS[$key.'_type']);
+        unset($GLOBALS[$key.'_name']);
+        unset($GLOBALS[$key.'_size']);
+    }
+    /**
+     * Remove globalized environment variables.
+     */
+    foreach ($_ENV as $key => $value) {
+        unset($GLOBALS[$key]);
+    }
+    /**
+     * Remove globalized server variables.
+     */
+    foreach ($_SERVER as $key => $value) {
+        unset($GLOBALS[$key]);
+    }
+}
+
+
 /* strip any tags added to the url from PHP_SELF.
    This fixes hand crafted url XXS expoits for any
    page that uses PHP_SELF as the FORM action */
