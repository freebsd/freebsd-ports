--- cipher/crc-intel-pclmul.c.orig	2016-04-07 15:30:08 UTC
+++ cipher/crc-intel-pclmul.c
@@ -143,7 +143,7 @@ crc32_reflected_bulk (u32 *pcrc, const b
 		      [inbuf_2] "m" (inbuf[2 * 16]),
 		      [inbuf_3] "m" (inbuf[3 * 16]),
 		      [crc] "m" (*pcrc)
-		    : );
+		    );
 
       inbuf += 4 * 16;
       inlen -= 4 * 16;
@@ -151,7 +151,7 @@ crc32_reflected_bulk (u32 *pcrc, const b
       asm volatile ("movdqa %[k1k2], %%xmm4\n\t"
 		    :
 		    : [k1k2] "m" (consts->k[1 - 1])
-		    : );
+		    );
 
       /* Fold by 4. */
       while (inlen >= 4 * 16)
@@ -188,7 +188,7 @@ crc32_reflected_bulk (u32 *pcrc, const b
 			  [inbuf_1] "m" (inbuf[1 * 16]),
 			  [inbuf_2] "m" (inbuf[2 * 16]),
 			  [inbuf_3] "m" (inbuf[3 * 16])
-			: );
+			);
 
 	  inbuf += 4 * 16;
 	  inlen -= 4 * 16;
@@ -199,7 +199,7 @@ crc32_reflected_bulk (u32 *pcrc, const b
 		    :
 		    : [k3k4] "m" (consts->k[3 - 1]),
 		      [my_p] "m" (consts->my_p[0])
-		    : );
+		    );
 
       /* Fold 4 to 1. */
 
@@ -222,7 +222,7 @@ crc32_reflected_bulk (u32 *pcrc, const b
 		    "pxor %%xmm4, %%xmm0\n\t"
 		    :
 		    :
-		    : );
+		    );
     }
   else
     {
@@ -236,7 +236,7 @@ crc32_reflected_bulk (u32 *pcrc, const b
 		      [crc] "m" (*pcrc),
 		      [k3k4] "m" (consts->k[3 - 1]),
 		      [my_p] "m" (consts->my_p[0])
-		    : );
+		    );
 
       inbuf += 16;
       inlen -= 16;
@@ -256,7 +256,7 @@ crc32_reflected_bulk (u32 *pcrc, const b
 			"pxor %%xmm1, %%xmm0\n\t"
 			:
 			: [inbuf] "m" (*inbuf)
-			: );
+			);
 
 	  inbuf += 16;
 	  inlen -= 16;
@@ -288,7 +288,7 @@ crc32_reflected_bulk (u32 *pcrc, const b
 		      [mask] "m" (crc32_partial_fold_input_mask[inlen]),
 		      [shl_shuf] "m" (crc32_refl_shuf_shift[inlen]),
 		      [shr_shuf] "m" (crc32_refl_shuf_shift[inlen + 16])
-		    : );
+		    );
 
       inbuf += inlen;
       inlen -= inlen;
@@ -318,7 +318,7 @@ crc32_reflected_bulk (u32 *pcrc, const b
 		"pextrd $2, %%xmm0, %[out]\n\t"
 		: [out] "=m" (*pcrc)
 		: [k5] "m" (consts->k[5 - 1])
-	        : );
+	        );
 }
 
 static inline void
@@ -333,7 +333,7 @@ crc32_reflected_less_than_16 (u32 *pcrc,
       asm volatile ("movdqa %[my_p], %%xmm5\n\t"
 		    :
 		    : [my_p] "m" (consts->my_p[0])
-		    : );
+		    );
 
       if (inlen == 1)
 	{
@@ -372,7 +372,7 @@ crc32_reflected_less_than_16 (u32 *pcrc,
 		    : [out] "=m" (*pcrc)
 		    : [in] "rm" (data),
 		      [crc] "rm" (crc)
-		    : );
+		    );
     }
   else if (inlen == 4)
     {
@@ -391,7 +391,7 @@ crc32_reflected_less_than_16 (u32 *pcrc,
 		    : [in] "m" (*inbuf),
 		      [crc] "m" (*pcrc),
 		      [my_p] "m" (consts->my_p[0])
-		    : );
+		    );
     }
   else
     {
@@ -404,14 +404,14 @@ crc32_reflected_less_than_16 (u32 *pcrc,
 		      [crc] "m" (*pcrc),
 		      [my_p] "m" (consts->my_p[0]),
 		      [k3k4] "m" (consts->k[3 - 1])
-		    : );
+		    );
 
       if (inlen >= 8)
 	{
 	  asm volatile ("movq %[inbuf], %%xmm0\n\t"
 			:
 			: [inbuf] "m" (*inbuf)
-			: );
+			);
 	  if (inlen > 8)
 	    {
 	      asm volatile (/*"pinsrq $1, %[inbuf_tail], %%xmm0\n\t"*/
@@ -422,7 +422,7 @@ crc32_reflected_less_than_16 (u32 *pcrc,
 			    : [inbuf_tail] "m" (inbuf[inlen - 8]),
 			      [merge_shuf] "m"
 				(*crc32_merge9to15_shuf[inlen - 9])
-			    : );
+			    );
 	    }
 	}
       else
@@ -435,7 +435,7 @@ crc32_reflected_less_than_16 (u32 *pcrc,
 			  [inbuf_tail] "m" (inbuf[inlen - 4]),
 			  [merge_shuf] "m"
 			    (*crc32_merge5to7_shuf[inlen - 5])
-			: );
+			);
 	}
 
       /* Final fold. */
@@ -465,7 +465,7 @@ crc32_reflected_less_than_16 (u32 *pcrc,
 		    "pextrd $2, %%xmm0, %[out]\n\t"
 		    : [out] "=m" (*pcrc)
 		    : [k5] "m" (consts->k[5 - 1])
-		    : );
+		    );
     }
 }
 
@@ -477,7 +477,7 @@ crc32_bulk (u32 *pcrc, const byte *inbuf
   asm volatile ("movdqa %[bswap], %%xmm7\n\t"
 		:
 		: [bswap] "m" (*crc32_bswap_shuf)
-		: );
+		);
 
   if (inlen >= 8 * 16)
     {
@@ -497,7 +497,7 @@ crc32_bulk (u32 *pcrc, const byte *inbuf
 		      [inbuf_2] "m" (inbuf[2 * 16]),
 		      [inbuf_3] "m" (inbuf[3 * 16]),
 		      [crc] "m" (*pcrc)
-		    : );
+		    );
 
       inbuf += 4 * 16;
       inlen -= 4 * 16;
@@ -505,7 +505,7 @@ crc32_bulk (u32 *pcrc, const byte *inbuf
       asm volatile ("movdqa %[k1k2], %%xmm4\n\t"
 		    :
 		    : [k1k2] "m" (consts->k[1 - 1])
-		    : );
+		    );
 
       /* Fold by 4. */
       while (inlen >= 4 * 16)
@@ -546,7 +546,7 @@ crc32_bulk (u32 *pcrc, const byte *inbuf
 			  [inbuf_1] "m" (inbuf[1 * 16]),
 			  [inbuf_2] "m" (inbuf[2 * 16]),
 			  [inbuf_3] "m" (inbuf[3 * 16])
-			: );
+			);
 
 	  inbuf += 4 * 16;
 	  inlen -= 4 * 16;
@@ -557,7 +557,7 @@ crc32_bulk (u32 *pcrc, const byte *inbuf
 		    :
 		    : [k3k4] "m" (consts->k[3 - 1]),
 		      [my_p] "m" (consts->my_p[0])
-		    : );
+		    );
 
       /* Fold 4 to 1. */
 
@@ -580,7 +580,7 @@ crc32_bulk (u32 *pcrc, const byte *inbuf
 		    "pxor %%xmm4, %%xmm0\n\t"
 		    :
 		    :
-		    : );
+		    );
     }
   else
     {
@@ -595,7 +595,7 @@ crc32_bulk (u32 *pcrc, const byte *inbuf
 		      [crc] "m" (*pcrc),
 		      [k3k4] "m" (consts->k[3 - 1]),
 		      [my_p] "m" (consts->my_p[0])
-		    : );
+		    );
 
       inbuf += 16;
       inlen -= 16;
@@ -616,7 +616,7 @@ crc32_bulk (u32 *pcrc, const byte *inbuf
 			"pxor %%xmm1, %%xmm0\n\t"
 			:
 			: [inbuf] "m" (*inbuf)
-			: );
+			);
 
 	  inbuf += 16;
 	  inlen -= 16;
@@ -650,7 +650,7 @@ crc32_bulk (u32 *pcrc, const byte *inbuf
 		      [mask] "m" (crc32_partial_fold_input_mask[inlen]),
 		      [shl_shuf] "m" (crc32_refl_shuf_shift[32 - inlen]),
 		      [shr_shuf] "m" (crc32_shuf_shift[inlen + 16])
-		    : );
+		    );
 
       inbuf += inlen;
       inlen -= inlen;
@@ -697,7 +697,7 @@ crc32_less_than_16 (u32 *pcrc, const byt
       asm volatile ("movdqa %[my_p], %%xmm5\n\t"
 		    :
 		    : [my_p] "m" (consts->my_p[0])
-		    : );
+		    );
 
       if (inlen == 1)
 	{
@@ -774,14 +774,14 @@ crc32_less_than_16 (u32 *pcrc, const byt
 		      [crc] "m" (*pcrc),
 		      [my_p] "m" (consts->my_p[0]),
 		      [k3k4] "m" (consts->k[3 - 1])
-		    : );
+		    );
 
       if (inlen >= 8)
 	{
 	  asm volatile ("movq %[inbuf], %%xmm0\n\t"
 			:
 			: [inbuf] "m" (*inbuf)
-			: );
+			);
 	  if (inlen > 8)
 	    {
 	      asm volatile (/*"pinsrq $1, %[inbuf_tail], %%xmm0\n\t"*/
@@ -792,7 +792,7 @@ crc32_less_than_16 (u32 *pcrc, const byt
 			    : [inbuf_tail] "m" (inbuf[inlen - 8]),
 			      [merge_shuf] "m"
 				(*crc32_merge9to15_shuf[inlen - 9])
-			    : );
+			    );
 	    }
 	}
       else
@@ -805,7 +805,7 @@ crc32_less_than_16 (u32 *pcrc, const byt
 			  [inbuf_tail] "m" (inbuf[inlen - 4]),
 			  [merge_shuf] "m"
 			    (*crc32_merge5to7_shuf[inlen - 5])
-			: );
+			);
 	}
 
       /* Final fold. */
