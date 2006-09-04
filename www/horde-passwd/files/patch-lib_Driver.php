--- lib/Driver.php.orig    Wed Aug 23 13:18:54 2006
+++ lib/Driver.php  Wed Aug 23 13:19:40 2006
@@ -107,7 +107,8 @@
         require_once dirname(__FILE__) . '/Driver/' . $driver . '.php';
         $class = 'Passwd_Driver_' . $driver;
         if (class_exists($class)) {
-            return $ret = &new $class($params);
+            $ret = &new $class($params);
+            return $ret;
         } else {
             Horde::fatal(PEAR::raiseError(sprintf(_("No such backend \"%s\" found."), $driver)), __FILE__, __LINE__);
         }
