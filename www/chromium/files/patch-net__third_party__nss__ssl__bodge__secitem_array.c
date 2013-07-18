--- net/third_party/nss/ssl/bodge/secitem_array.c.orig	2013-07-16 21:54:03.000000000 +0300
+++ net/third_party/nss/ssl/bodge/secitem_array.c	2013-07-16 21:54:26.000000000 +0300
@@ -11,13 +11,6 @@
 #include "secerr.h"
 #include "secport.h"
 
-typedef struct SECItemArrayStr SECItemArray;
-
-struct SECItemArrayStr {
-    SECItem *items;
-    unsigned int len;
-};
-
 SECItemArray *
 SECITEM_AllocArray(PLArenaPool *arena, SECItemArray *array, unsigned int len)
 {
