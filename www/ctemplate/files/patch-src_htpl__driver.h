--- src/htpl_driver.h.orig	2008-04-15 23:08:27 UTC
+++ src/htpl_driver.h
@@ -40,7 +40,7 @@ const char *getprogname(void);
 #endif
 
 extern char* tplargs;
-const extern char* funcname;
+extern char* funcname;
 extern const char* funcprefix;
 
 class htpl_driver {
