--- lib/Horde.php.orig	Wed Apr 23 23:43:06 2003
+++ lib/Horde.php	Sat Aug  2 21:14:12 2003
@@ -120,7 +120,7 @@
  *
  * @author  Chuck Hagenbuch <chuck@horde.org>
  * @author  Jon Parise <jon@horde.org>
- * @version $Revision: 1.118.2.42 $
+ * @version $Revision: 1.118.2.43 $
  * @since   Horde 1.3
  * @package horde
  */
@@ -184,8 +184,8 @@
         }
 
         include_once 'Log.php';
-        $logger = Log::singleton($conf['log']['type'], $conf['log']['name'],
-                                 $conf['log']['ident'], $conf['log']['params']);
+        $logger = &Log::singleton($conf['log']['type'], $conf['log']['name'],
+                                  $conf['log']['ident'], $conf['log']['params']);
 
         if (!$logger) {
             Horde::fatal(new PEAR_Error('An error has occurred. Furthermore, Horde encountered an error attempting to log this error. Please check your Horde logging configuration in horde/config/horde.php.'), __FILE__, __LINE__, false);
