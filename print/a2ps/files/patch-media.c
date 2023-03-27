--- liba2ps/media.c.orig	2023-01-26 13:04:21 UTC
+++ liba2ps/media.c
@@ -147,7 +147,7 @@ a2ps_get_medium (a2ps_job * job, const char * name)
 
   token.name = NULL;
   if (strcaseequ (name, LIBPAPER_MEDIUM))
-    token.name = (char *) defaultpapername ();
+    token.name = (char *) systempapername ();
 
   if (!token.name)
     token.name = (char *) name;
