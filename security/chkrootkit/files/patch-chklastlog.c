--- chklastlog.c.orig	2014-05-06 10:12:14 UTC
+++ chklastlog.c
@@ -33,7 +33,7 @@
 #else
 #undef HAVE_LASTLOG_H
 #endif
-#if __FreeBSD__ > 9
+#if __FreeBSD__ >= 9
 int main () { return 0; }
 #else
 #include <stdio.h>
