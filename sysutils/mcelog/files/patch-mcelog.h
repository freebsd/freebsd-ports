--- mcelog.h.orig	2016-02-10 18:38:43 UTC
+++ mcelog.h
@@ -67,10 +67,12 @@ struct mce {
 #define MCI_STATUS_AR	 (1ULL<<55)  /* action-required */
 #define MCI_STATUS_FWST  (1ULL<<37)  /* Firmware updated status indicator */
 
+#ifndef MCG_STATUS_RIPV
 #define MCG_STATUS_RIPV  (1ULL<<0)   /* restart ip valid */
 #define MCG_STATUS_EIPV  (1ULL<<1)   /* eip points to correct instruction */
 #define MCG_STATUS_MCIP  (1ULL<<2)   /* machine check in progress */
 #define MCG_STATUS_LMCES (1ULL<<3)   /* local machine check signaled */
+#endif
 
 #define MCG_CMCI_P		(1ULL<<10)   /* CMCI supported */
 #define MCG_TES_P		(1ULL<<11)   /* Yellow bit cache threshold supported */
@@ -97,6 +99,10 @@ struct mce {
 #define noreturn
 #endif
 
+#if defined(__FreeBSD__) && defined(_STDIO_H_)
+FILE *open_memstream(char **cp, size_t *lenp);
+#endif
+
 int Wprintf(char *fmt, ...) PRINTFLIKE;
 void Eprintf(char *fmt, ...) PRINTFLIKE;
 void SYSERRprintf(char *fmt, ...) PRINTFLIKE;
