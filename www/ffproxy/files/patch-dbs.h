--- dbs.h.orig	2002-07-25 12:24:10 UTC
+++ dbs.h
@@ -1,3 +1,4 @@
+#include <unistd.h>
 #include <regex.h>
 
 extern regex_t *a_ip[];
