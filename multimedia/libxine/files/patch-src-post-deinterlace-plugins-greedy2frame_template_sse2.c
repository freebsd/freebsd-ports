--- src/post/deinterlace/plugins/greedy2frame_template_sse2.c.orig
+++ src/post/deinterlace/plugins/greedy2frame_template_sse2.c
@@ -174,8 +174,8 @@ static void DeinterlaceGreedy2Frame_SSE2
         */
             "movdqa  (%2), %%xmm1		\n\t" /* xmm1 = T1 */
             "movdqa  (%3), %%xmm0		\n\t" /* xmm0 = T0 */
-            "movdqa  (%q4,%2), %%xmm3		\n\t" /* xmm3 = B1 */
-            "movdqa  (%q4,%3), %%xmm2		\n\t" /* xmm2 = B0 */
+            "movdqa  (%2,%4), %%xmm3		\n\t" /* xmm3 = B1 */
+            "movdqa  (%3,%4), %%xmm2		\n\t" /* xmm2 = B0 */
 
             /* calculate |T1-T0| keep T1 put result in xmm5 */
             "movdqa  %%xmm1, %%xmm5		\n\t"
@@ -192,11 +192,11 @@ static void DeinterlaceGreedy2Frame_SSE2
             "pcmpgtb %0, %%xmm5			\n\t"
             "pcmpeqd %%xmm7, %%xmm5		\n\t"
 
-            "prefetcht0  64(%q4,%2)		\n\t"
-            "prefetcht0  64(%q4,%3)		\n\t"
+            "prefetcht0  64(%2,%4)		\n\t"
+            "prefetcht0  64(%3,%4)		\n\t"
           :
           : "m" (GreedyTwoFrameThreshold128),
-            "m" (*Destc), "r" (T1), "r" (T0), "r" (Pitch) );
+            "m" (*Destc), "r" (T1), "r" (T0), "r" ((register_t)Pitch) );
 
           asm volatile (
             /* calculate |B1-B0| keep B1 put result in xmm4 */
