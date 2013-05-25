--- runtime/libgcry.h.ori	2013-05-24 20:23:45.000000000 -0600
+++ runtime/libgcry.h	2013-05-24 20:24:03.000000000 -0600
@@ -49,7 +49,7 @@
 rsRetVal rsgcrySetAlgo(gcryctx ctx, uchar *modename);
 gcryctx gcryCtxNew(void);
 void rsgcryCtxDel(gcryctx ctx);
-int gcryfileDestruct(gcryfile gf, off64_t offsLogfile);
+int gcryfileDestruct(gcryfile gf, off_t offsLogfile);
 rsRetVal rsgcryInitCrypt(gcryctx ctx, gcryfile *pgf, uchar *fname);
 int rsgcryEncrypt(gcryfile pF, uchar *buf, size_t *len);
 
