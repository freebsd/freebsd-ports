--- ./mcelog.h.orig	2009-12-15 07:18:40.000000000 -0500
+++ ./mcelog.h	2011-10-14 22:37:06.000000000 -0400
@@ -64,9 +64,11 @@
 #define MCI_STATUS_ADDRV (1ULL<<58)  /* addr reg. valid */
 #define MCI_STATUS_PCC   (1ULL<<57)  /* processor context corrupt */
 
+#ifndef MCG_STATUS_RIPV
 #define MCG_STATUS_RIPV  (1ULL<<0)   /* restart ip valid */
 #define MCG_STATUS_EIPV  (1ULL<<1)   /* eip points to correct instruction */
 #define MCG_STATUS_MCIP  (1ULL<<2)   /* machine check in progress */
+#endif
 
 #define MCG_CMCI_P		(1ULL<<10)   /* CMCI supported */
 #define MCG_TES_P		(1ULL<<11)   /* Yellow bit cache threshold supported */
@@ -89,6 +91,10 @@
 #define PRINTFLIKE 
 #endif
 
+#if defined(__FreeBSD__) && defined(_STDIO_H_)
+FILE *open_memstream(char **cp, size_t *lenp);
+#endif
+
 int Wprintf(char *fmt, ...) PRINTFLIKE;
 void Eprintf(char *fmt, ...) PRINTFLIKE;
 void SYSERRprintf(char *fmt, ...) PRINTFLIKE;
