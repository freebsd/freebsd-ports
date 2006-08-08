--- bacula-web/classes.inc.orig	Sat Nov  5 17:11:16 2005
+++ bacula-web/classes.inc	Sat Apr 29 16:34:44 2006
@@ -15,8 +15,8 @@
 +-------------------------------------------------------------------------+
 */
 // Last Err: 11
-define('CONFIG_DIR', "configs");
-define('CONFIG_FILE', "bacula.conf");
+define('CONFIG_DIR', "/usr/local/etc");
+define('CONFIG_FILE', "bacula-web.conf");
 define('BACULA_TYPE_BYTES_FILES', 1);
 define('BACULA_TYPE_FILES_JOBID', 2);
 define('BACULA_TYPE_BYTES_ENDTIME_ALLJOBS', 69);
