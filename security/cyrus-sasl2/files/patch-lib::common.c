Index: lib/common.c
diff -u -p lib/common.c.orig lib/common.c
--- lib/common.c.orig	Wed Jul  7 01:03:05 2004
+++ lib/common.c	Sat Oct  9 02:03:02 2004
@@ -1838,7 +1838,10 @@ _sasl_getpath(void *context __attribute_
   if (! path)
     return SASL_BADPARAM;
 
-  *path = getenv(SASL_PATH_ENV_VAR);
+  /* Honor external variable only in a safe environment */
+  if (getuid() == geteuid() && getgid() == getegid())
+    *path = getenv(SASL_PATH_ENV_VAR);
+
   if (! *path)
     *path = PLUGINDIR;
 
