# CVE-2009-3720

--- modules/expat/xmltok/xmltok_impl.c.orig	2000-08-28 08:52:01 UTC
+++ modules/expat/xmltok/xmltok_impl.c
@@ -1753,7 +1753,7 @@ void PREFIX(updatePosition)(const ENCODI
 			    const char *end,
 			    POSITION *pos)
 {
-  while (ptr != end) {
+  while (ptr < end) {
     switch (BYTE_TYPE(enc, ptr)) {
 #define LEAD_CASE(n) \
     case BT_LEAD ## n: \
