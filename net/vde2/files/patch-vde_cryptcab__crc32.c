--- ./vde_cryptcab/crc32.c.orig	Fri Jul  7 11:54:39 2006
+++ ./vde_cryptcab/crc32.c	Sun Feb 18 12:50:56 2007
@@ -15,19 +15,20 @@
 
 #include <stdio.h>
 #include <stdlib.h>
+#include <sys/types.h>
 
 /* crc_tab[] -- this crcTable is being build by chksum_crc32GenTab().
  *		so make sure, you call it before using the other
  *		functions!
  */
-u_int32_t crc_tab[256];
+uint32_t crc_tab[256];
 
 /* chksum_crc() -- to a given block, this one calculates the
  *				crc32-checksum until the length is
  *				reached. the crc32-checksum will be
  *				the result.
  */
-u_int32_t chksum_crc32 (unsigned char *block, unsigned int length)
+uint32_t chksum_crc32 (unsigned char *block, unsigned int length)
 {
    register unsigned long crc;
    unsigned long i;
