--- config.h.orig	2016-11-02 12:16:30 UTC
+++ config.h
@@ -42,7 +42,7 @@
 #if OS_LEVEL > 32
 #define HAVE_ADDR_MASK
 #define HAVE_ADDR_TYPE
-#define HAVE_ALTQ
+/* #define HAVE_ALTQ */
 #define HAVE_RULE_TOS
 #define HAVE_OP_RRG
 #endif
