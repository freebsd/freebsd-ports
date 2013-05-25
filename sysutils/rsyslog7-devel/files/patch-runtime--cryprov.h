--- runtime/cryprov.h.ori	2013-05-24 19:47:48.000000000 -0600
+++ runtime/cryprov.h	2013-05-24 20:20:40.000000000 -0600
@@ -33,7 +33,7 @@
 	rsRetVal (*Destruct)(void *ppThis);
 	rsRetVal (*OnFileOpen)(void *pThis, uchar *fn, void *pFileInstData);
 	rsRetVal (*Encrypt)(void *pFileInstData, uchar *buf, size_t *lenBuf);
-	rsRetVal (*OnFileClose)(void *pFileInstData, off64_t offsLogfile);
+	rsRetVal (*OnFileClose)(void *pFileInstData, off_t offsLogfile);
 ENDinterface(cryprov)
 #define cryprovCURR_IF_VERSION 1 /* increment whenever you change the interface structure! */
 #endif /* #ifndef INCLUDED_CRYPROV_H */
