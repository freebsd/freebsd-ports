--- libswscale/utils.c.orig	2010-12-21 01:01:42.465502681 +0100
+++ libswscale/utils.c	2010-12-21 01:01:45.816480317 +0100
@@ -915,7 +915,11 @@
             c->chrMmx2FilterCode = av_malloc(c->chrMmx2FilterCodeSize);
 #endif
 
+#ifdef MAP_ANONYMOUS
+            if (c->lumMmx2FilterCode == MAP_FAILED || c->chrMmx2FilterCode == MAP_FAILED)
+#else
             if (!c->lumMmx2FilterCode || !c->chrMmx2FilterCode)
+#endif
                 return AVERROR(ENOMEM);
             FF_ALLOCZ_OR_GOTO(c, c->hLumFilter   , (dstW        /8+8)*sizeof(int16_t), fail);
             FF_ALLOCZ_OR_GOTO(c, c->hChrFilter   , (c->chrDstW  /4+8)*sizeof(int16_t), fail);
