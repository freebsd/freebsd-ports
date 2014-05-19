--- runtime/lmcry_gcry.c.ori	2013-05-24 20:25:10.000000000 -0600
+++ runtime/lmcry_gcry.c	2013-05-24 20:25:25.000000000 -0600
@@ -216,7 +216,7 @@
 }
 
 static rsRetVal
-OnFileClose(void *pF, off64_t offsLogfile)
+OnFileClose(void *pF, off_t offsLogfile)
 {
 	DEFiRet;
 	gcryfileDestruct(pF, offsLogfile);
