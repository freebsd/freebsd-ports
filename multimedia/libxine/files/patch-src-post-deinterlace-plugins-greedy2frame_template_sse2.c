--- src/post/deinterlace/plugins/greedy2frame_template_sse2.c.orig	2013-09-03 20:12:37.000000000 +0200
+++ src/post/deinterlace/plugins/greedy2frame_template_sse2.c	2013-09-03 20:22:34.000000000 +0200
@@ -173,8 +173,8 @@
         */
             "movdqa  (%3), %%xmm1		\n\t" /* xmm1 = T1 */
             "movdqa  (%4), %%xmm0		\n\t" /* xmm0 = T0 */
-            "movdqa  (%q5,%3), %%xmm3		\n\t" /* xmm3 = B1 */
-            "movdqa  (%q5,%4), %%xmm2		\n\t" /* xmm2 = B0 */
+            "movdqa  (%3,%5), %%xmm3		\n\t" /* xmm3 = B1 */
+            "movdqa  (%4,%5), %%xmm2		\n\t" /* xmm2 = B0 */
 
             /* calculate |T1-T0| keep T1 put result in xmm5 */
             "movdqa  %%xmm1, %%xmm5		\n\t"
@@ -192,11 +192,11 @@
             "pcmpgtb %1, %%xmm5			\n\t"
             "pcmpeqd %%xmm7, %%xmm5		\n\t"
 
-            "prefetcht0  64(%q5,%3)		\n\t"
-            "prefetcht0  64(%q5,%4)		\n\t"
+            "prefetcht0  64(%3,%5)		\n\t"
+            "prefetcht0  64(%4,%5)		\n\t"
           :
           : "r" (M1), "m" (GreedyTwoFrameThreshold128),
-            "m" (*Destc), "r" (T1), "r" (T0), "r" (Pitch) );
+            "m" (*Destc), "r" (T1), "r" (T0), "r" ((register_t)Pitch) );
 
           asm volatile (
             /* calculate |B1-B0| keep B1 put result in xmm4 */
