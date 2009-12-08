--- lib/xmltok_impl.c.orig	2009-12-08 10:16:58.047943029 +0900
+++ lib/xmltok_impl.c	2009-12-08 10:17:13.228143919 +0900
@@ -1744,7 +1744,7 @@
                        const char *end,
                        POSITION *pos)
 {
-  while (ptr != end) {
+  while (ptr < end) {
     switch (BYTE_TYPE(enc, ptr)) {
 #define LEAD_CASE(n) \
     case BT_LEAD ## n: \
