Index: lib/common.c
diff -u lib/common.c.orig lib/common.c
--- lib/common.c.orig	Mon Nov 15 18:23:04 2004
+++ lib/common.c	Mon Nov 15 18:24:43 2004
@@ -684,7 +684,13 @@
 
   if (! path_dest)
     return SASL_BADPARAM;
-  path = getenv(SASL_PATH_ENV_VAR);
+
+  path = NULL;
+
+  /* Honor external variable only in a safe environment */
+  if (getuid() == geteuid() && getgid() == getegid())
+    path = getenv(SASL_PATH_ENV_VAR);
+
   if (! path)
     path = PLUGINDIR;
   return _sasl_strdup(path, path_dest, NULL);
