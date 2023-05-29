--- libsi/util.c.orig	2006-02-18 11:17:50 UTC
+++ libsi/util.c
@@ -266,7 +266,7 @@ u_int32_t CRC32::crc32 (const char *d, int len, u_int3
 
 u_int32_t CRC32::crc32 (const char *d, int len, u_int32_t crc)
 {
-   register int i;
+   int i;
    const unsigned char *u=(unsigned char*)d; // Saves '& 0xff'
 
    for (i=0; i<len; i++)
