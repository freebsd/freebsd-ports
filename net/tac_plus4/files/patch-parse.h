--- parse.h.orig	2012-04-10 22:34:40.000000000 +0400
+++ parse.h	2013-04-13 14:02:27.000000000 +0400
@@ -74,6 +74,7 @@
 #ifdef MSCHAP
 #define S_mschap          42
 #endif /* MSCHAP */
+#define S_opie            43
 #define S_enable	43
 #ifdef ACLS
 # define S_acl		44
