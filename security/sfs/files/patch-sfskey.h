$FreeBSD$

--- agent/sfskey.h.orig	Sun Dec  1 17:32:05 2002
+++ agent/sfskey.h	Sun Dec  1 18:03:45 2002
@@ -34,7 +34,7 @@
 extern bool opt_quiet;
 extern ref<agentconn> aconn;

-#if __GNUC__ == 2 && __GNUC_MINOR__ <= 95 && defined (__alpha__)
+#if __GNUC__ == 2 && __GNUC_MINOR__ <= 95 && defined (__alpha__) && !defined(__FreeBSD__)
 # define XXX_EXIT 1
 #endif /* gcc <= 2.95.x && alpha */
