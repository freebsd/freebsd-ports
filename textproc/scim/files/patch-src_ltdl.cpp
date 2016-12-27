--- src/ltdl.cpp.orig	2008-11-02 06:42:40 UTC
+++ src/ltdl.cpp
@@ -3361,7 +3361,7 @@ lt_dlopenext (
 {
   lt_dlhandle	handle		= 0;
   char *	tmp		= 0;
-  char *	ext		= 0;
+  const char *	ext		= 0;
   size_t	len;
   int		errors		= 0;
 
