--- src/extension-functions.cc.orig	2017-04-19 14:17:53 UTC
+++ src/extension-functions.cc
@@ -269,7 +269,7 @@ static const int xtra_utf8_bits[] =  {
 ** masking the character with utf8_mask[N] must produce a non-zero
 ** result.  Otherwise, we have an (illegal) overlong encoding.
 */
-static const long utf_mask[] = {
+static const unsigned long utf_mask[] = {
   0x00000000,
   0xffffff80,
   0xfffff800,
