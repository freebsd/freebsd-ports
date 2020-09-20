--- types.h.orig	2012-06-09 21:45:22 UTC
+++ types.h
@@ -24,13 +24,3 @@ struct test {
     char *name;
     int (*fp)();
 };
-
-union {
-    unsigned char bytes[UL_LEN/8];
-    ul val;
-} mword8;
-
-union {
-    unsigned short u16s[UL_LEN/16];
-    ul val;
-} mword16;
