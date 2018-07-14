--- libxorp/strptime.c.orig	2018-07-10 12:54:53 UTC
+++ libxorp/strptime.c
@@ -85,10 +85,10 @@
 #define TM_YEAR_BASE 1900
 #endif
 
-static inline void *
+static inline const char *
 UNCONST(const void *a)
 {
-	return ((const char *)a - (const char *)0) + (char *)0;
+	return ((const char *)a - sizeof((const char *)0)) + sizeof((char *)0);
 }
 
 
