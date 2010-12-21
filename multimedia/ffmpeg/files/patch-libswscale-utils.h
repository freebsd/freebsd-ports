--- libswscale/utils.c.orig	2010-12-17 18:58:26.307218801 +0200
+++ libswscale/utils.c	2010-12-17 19:00:13.409221287 +0200
@@ -955,8 +955,8 @@
             c->chrMmx2FilterCodeSize = initMMX2HScaler(c->chrDstW, c->chrXInc, NULL, NULL, NULL, 4);
 
 #ifdef MAP_ANONYMOUS
-            c->lumMmx2FilterCode = mmap(NULL, c->lumMmx2FilterCodeSize, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, 0, 0);
-            c->chrMmx2FilterCode = mmap(NULL, c->chrMmx2FilterCodeSize, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, 0, 0);
+            c->lumMmx2FilterCode = mmap(NULL, c->lumMmx2FilterCodeSize, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
+            c->chrMmx2FilterCode = mmap(NULL, c->chrMmx2FilterCodeSize, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
 #elif HAVE_VIRTUALALLOC
             c->lumMmx2FilterCode = VirtualAlloc(NULL, c->lumMmx2FilterCodeSize, MEM_COMMIT, PAGE_EXECUTE_READWRITE);
             c->chrMmx2FilterCode = VirtualAlloc(NULL, c->chrMmx2FilterCodeSize, MEM_COMMIT, PAGE_EXECUTE_READWRITE);
@@ -965,7 +965,11 @@
             c->chrMmx2FilterCode = av_malloc(c->chrMmx2FilterCodeSize);
 #endif
 
+#ifdef MAP_ANONYMOUS
+            if (c->lumMmx2FilterCode == MAP_FAILED || c->chrMmx2FilterCode == MAP_FAILED)
+#else
             if (!c->lumMmx2FilterCode || !c->chrMmx2FilterCode)
+#endif
                 goto fail;
             FF_ALLOCZ_OR_GOTO(c, c->hLumFilter   , (dstW        /8+8)*sizeof(int16_t), fail);
             FF_ALLOCZ_OR_GOTO(c, c->hChrFilter   , (c->chrDstW  /4+8)*sizeof(int16_t), fail);
