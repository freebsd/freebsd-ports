--- src/igmpproxy.h.orig	2021-01-12 08:24:34 UTC
+++ src/igmpproxy.h
@@ -112,7 +112,7 @@ void my_log( int Serverity, int Errno, const char *Fmt
 
 /* ifvc.c
  */
-#define MAX_IF         40     // max. number of interfaces recognized
+#define MAX_IF         140     // max. number of interfaces recognized
 
 // Interface states
 #define IF_STATE_DISABLED      0   // Interface should be ignored.
