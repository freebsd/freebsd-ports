--- tgl/mtproto-utils.c.orig	2016-03-23 11:42:06 UTC
+++ tgl/mtproto-utils.c
@@ -98,9 +98,7 @@ static unsigned long long BN2ull (TGLC_b
   if (sizeof (unsigned long) == 8) {
     return TGLC_bn_get_word (b);
   } else if (sizeof (unsigned long long) == 8) {
-    assert (0); // As long as nobody ever uses this code, assume it is broken.
     unsigned long long tmp;
-    /* Here be dragons, but it should be okay due to be64toh */
     TGLC_bn_bn2bin (b, (unsigned char *) &tmp);
     return be64toh (tmp);
   } else {
@@ -112,9 +110,7 @@ static void ull2BN (TGLC_bn *b, unsigned
   if (sizeof (unsigned long) == 8 || val < (1ll << 32)) {
     TGLC_bn_set_word (b, val);
   } else if (sizeof (unsigned long long) == 8) {
-    assert (0); // As long as nobody ever uses this code, assume it is broken.
     htobe64(val);
-    /* Here be dragons, but it should be okay due to htobe64 */
     TGLC_bn_bin2bn ((unsigned char *) &val, 8, b);
   } else {
     assert (0);
