--- C/xosBalls.c.orig	2005-05-10 08:18:13.000000000 +0000
+++ C/xosBalls.c	2007-01-24 15:12:15.000000000 +0000
@@ -17,7 +17,11 @@
 extern X2C_ADDRESS X2C_initBalls(X2C_CARD32 nBlocks, X2C_CARD32 blockSize)
 {
    bSize = blockSize;
+#if defined(__FreeBSD__) || defined(__DragonFly__)
+   heapBase = mmap(0, nBlocks*bSize, 0ul, 0x1000|0x2, -1l, 0ul);
+#else
    heapBase = mmap(0, nBlocks*bSize, 0ul, 34ul, -1l, 0ul);
+#endif
    if (heapBase==(X2C_ADDRESS)-1u) heapBase = 0;
    return heapBase;
 } /* end X2C_initBalls() */
