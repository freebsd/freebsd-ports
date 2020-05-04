--- libcnews/mkinperm.c.orig	2020-05-02 08:20:33 UTC
+++ libcnews/mkinperm.c
@@ -24,7 +24,7 @@
 #endif
 
 int mkinpdebug = 0;
-const char *progname;
+extern const char *progname;
 
 int						/* true iff succeeded */
 mkinperm(tmpname, grade, class)
