--- src/cmd.dc.h.orig	Mon Mar 20 04:03:53 2006
+++ src/cmd.dc.h	Fri Apr 28 15:10:57 2006
@@ -13,6 +13,10 @@
 #if !defined(__CMD_DC_H__)
 #define __CMD_DC_H__
 
+#ifndef UINT64_C
+#define        UINT64_C(c)     (c ## ULL)
+#endif
+
 typedef struct{
 	userrec_t *usr;
 	char *cmd;
