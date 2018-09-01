--- zxutil.c.orig	2018-08-06 01:37:42 UTC
+++ zxutil.c
@@ -681,7 +681,7 @@ linkrest:
 /*() Output a hexdump to stderr. Used for debugging purposes. */
 
 /* Called by: */
-int hexdump(const char* msg, const void* data, const void* lim, int max)
+int hexdump_zxid(const char* msg, const void* data, const void* lim, int max)
 {
   int i;
   const char* p = (const char*)data;
@@ -720,7 +720,7 @@ int hexdump(const char* msg, const void*
 
 /* Called by:  zx_get_symkey, zx_raw_cipher2 x4, zxbus_verify_receipt x2, zxsig_validate x19 */
 int hexdmp(const char* msg, const void* p, int len, int max) {
-  return hexdump(msg, p, p+len, max);
+  return hexdump_zxid(msg, p, p+len, max);
 }
 
 /*

