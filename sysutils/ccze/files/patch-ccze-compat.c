--- src/ccze-compat.c.orig	Fri Sep 26 17:27:22 2003
+++ src/ccze-compat.c	Fri Sep 26 17:27:39 2003
@@ -275,7 +275,7 @@
 		char **valuep)
 {
   int i = getsubopt (optionp, tokens, valuep);
-#if HAVE_SUBOPTARg
+#if HAVE_SUBOPTARG
   if (!*valuep && suboptarg)
     *valuep = strdup (suboptarg);
 #endif
