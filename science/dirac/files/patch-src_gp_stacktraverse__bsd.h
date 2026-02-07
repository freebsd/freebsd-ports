--- src/gp/stacktraverse_bsd.h.orig	2022-08-10 06:57:14 UTC
+++ src/gp/stacktraverse_bsd.h
@@ -36,3 +36,5 @@
 
 void *getreturnaddr(int);
 void *getframeaddr(int);
+
+#endif
