--- src/util.h.orig	2025-02-22 21:59:15 UTC
+++ src/util.h
@@ -79,7 +79,7 @@ typedef TSS2_RC (*KeyValueFunc) (const key_value_t* ke
 #define TPMA_CC_RES(attrs)         (attrs.val & 0xc0000000)
 */
 
-ssize_t     write_all                       (GOutputStream    *ostream,
+ssize_t     g_write_all                       (GOutputStream    *ostream,
                                              const uint8_t    *buf,
                                              const size_t      size);
 int         read_data                       (GInputStream     *istream,
