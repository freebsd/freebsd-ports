--- eruby.h.orig	2003-12-23 16:11:54.000000000 +0100
+++ eruby.h	2009-06-21 19:15:36.000000000 +0200
@@ -30,7 +30,7 @@
 extern int eruby_noheader;
 extern VALUE eruby_charset;
 extern VALUE eruby_default_charset;
-#define ERUBY_CHARSET RSTRING(eruby_charset)->ptr
+#define ERUBY_CHARSET RSTRING_PTR(eruby_charset)
 
 const char *eruby_version();
 int eruby_parse_options(int argc, char **argv, int *optind);
