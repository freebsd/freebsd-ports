--- parse.h.orig	2012-04-10 18:34:40 UTC
+++ parse.h
@@ -74,6 +74,7 @@
 #ifdef MSCHAP
 #define S_mschap          42
 #endif /* MSCHAP */
+#define S_opie            43
 #define S_enable	43
 #ifdef ACLS
 # define S_acl		44
