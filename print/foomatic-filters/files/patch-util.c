Resolves CVE-2015-8327 and CVE-2015-8560
--- util.c.orig	2015-12-17 18:07:21 UTC
+++ util.c
@@ -31,7 +31,7 @@
 #include <assert.h>
 
 
-const char* shellescapes = "|<>&!$\'\"#*?()[]{}";
+const char* shellescapes = "|;<>&!$\'\"`#*?()[]{}";
 
 const char * temp_dir()
 {
