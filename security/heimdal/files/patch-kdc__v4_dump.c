--- kdc/v4_dump.c.orig	2010-10-15 14:18:38.000000000 +0200
+++ kdc/v4_dump.c	2010-10-15 14:20:11.000000000 +0200
@@ -33,6 +33,8 @@
 
 #include "hprop.h"
 
+#ifdef KRB4
+
 static time_t
 time_parse(const char *cp)
 {
@@ -139,3 +141,4 @@
     fclose(f);
     return 0;
 }
+#endif /* KRB4 */
