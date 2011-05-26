--- ./pver_c.c.orig	2009-02-21 09:05:36.000000000 +0100
+++ ./pver_c.c	2011-05-26 12:00:10.000000000 +0200
@@ -7,7 +7,9 @@
 #include "config.h"
 
 int show_key(DBI_UNIT *key) {
-	printf("%d %.*s\n", key->DU_LEN, key->DU_LEN, (const char *)key->DU_DATA);
+	int w;
+	w = key->DU_LEN > INT_MAX ? INT_MAX : key->DU_LEN;
+	printf("%lu %.*s\n", (unsigned long)key->DU_LEN, w, (const char *)key->DU_DATA);
 	return 0;
 }
 
