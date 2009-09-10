Description: Protect some macro parameters with parentheses.
Author: Peter Pentchev <roam@FreeBSD.org>
Forwarded: http://sourceforge.net/mailarchive/message.php?msg_name=20090910102100.GA26539%40straylight.m.ringlet.net
Last-Update: 2009-09-10

--- lib/tiger.c.orig
+++ lib/tiger.c
@@ -62,26 +62,26 @@
 #ifdef OPTIMIZE_FOR_ALPHA
 /* This is the official definition of round */
 #define round(a,b,c,x,mul) \
-      c ^= x; \
-      a -= t1[((c)>>(0*8))&0xFF] ^ t2[((c)>>(2*8))&0xFF] ^ \
+      (c) ^= (x); \
+      (a) -= t1[((c)>>(0*8))&0xFF] ^ t2[((c)>>(2*8))&0xFF] ^ \
 	   t3[((c)>>(4*8))&0xFF] ^ t4[((c)>>(6*8))&0xFF] ; \
-      b += t4[((c)>>(1*8))&0xFF] ^ t3[((c)>>(3*8))&0xFF] ^ \
+      (b) += t4[((c)>>(1*8))&0xFF] ^ t3[((c)>>(3*8))&0xFF] ^ \
 	   t2[((c)>>(5*8))&0xFF] ^ t1[((c)>>(7*8))&0xFF] ; \
-      b *= mul;
+      (b) *= (mul);
 #else
 /* This code works faster when compiled on 32-bit machines */
 /* (but works slower on Alpha) */
 #define round(a,b,c,x,mul) \
-      c ^= x; \
-      a -= t1[(mutils_word8)(c)] ^ \
+      (c) ^= (x); \
+      (a) -= t1[(mutils_word8)(c)] ^ \
            t2[(mutils_word8)(((mutils_word32)(c))>>(2*8))] ^ \
 	   t3[(mutils_word8)((c)>>(4*8))] ^ \
            t4[(mutils_word8)(((mutils_word32)((c)>>(4*8)))>>(2*8))] ; \
-      b += t4[(mutils_word8)(((mutils_word32)(c))>>(1*8))] ^ \
+      (b) += t4[(mutils_word8)(((mutils_word32)(c))>>(1*8))] ^ \
            t3[(mutils_word8)(((mutils_word32)(c))>>(3*8))] ^ \
 	   t2[(mutils_word8)(((mutils_word32)((c)>>(4*8)))>>(1*8))] ^ \
            t1[(mutils_word8)(((mutils_word32)((c)>>(4*8)))>>(3*8))]; \
-      b *= mul;
+      (b) *= (mul);
 #endif
 
 #define pass(a,b,c,mul) \
@@ -149,18 +149,18 @@
   register mutils_word64 x0, x1, x2, x3, x4, x5, x6, x7; \
   mutils_word8 pass_no;					 \
 \
-  a = state[0]; \
-  b = state[1]; \
-  c = state[2]; \
+  a = (state)[0]; \
+  b = (state)[1]; \
+  c = (state)[2]; \
 \
-  x0=str[0]; x1=str[1]; x2=str[2]; x3=str[3]; \
-  x4=str[4]; x5=str[5]; x6=str[6]; x7=str[7]; \
+  x0=(str)[0]; x1=(str)[1]; x2=(str)[2]; x3=(str)[3]; \
+  x4=(str)[4]; x5=(str)[5]; x6=(str)[6]; x7=(str)[7]; \
 \
   compress; \
 \
-  state[0] = a; \
-  state[1] = b; \
-  state[2] = c; \
+  (state)[0] = a; \
+  (state)[1] = b; \
+  (state)[2] = c; \
 }
 
 #ifndef OPTIMIZE_FOR_ALPHA
@@ -173,20 +173,20 @@
 #else /* OPTIMIZE_FOR_ALPHA */
 /* The compress function is inlined: works better on Alpha.        */
 #define tiger_compress(str, state) \
-  tiger_compress_macro(((mutils_word64*)str), ((mutils_word64*)state))
+  tiger_compress_macro(((mutils_word64*)(str)), ((mutils_word64*)(state)))
 #endif /* OPTIMIZE_FOR_ALPHA */
 
 #ifndef EXTRACT_UCHAR
 #define EXTRACT_UCHAR(p)  (*(mutils_word8 *)(p))
 #endif
 
-#define STRING2INT64(s) ((((((((((((((mutils_word64)(EXTRACT_UCHAR(s+7) << 8)    \
-			 | EXTRACT_UCHAR(s+6)) << 8)  \
-			 | EXTRACT_UCHAR(s+5)) << 8)  \
-			 | EXTRACT_UCHAR(s+4)) << 8)  \
-			 | EXTRACT_UCHAR(s+3)) << 8)  \
-			 | EXTRACT_UCHAR(s+2)) << 8)  \
-			 | EXTRACT_UCHAR(s+1)) << 8)  \
+#define STRING2INT64(s) ((((((((((((((mutils_word64)(EXTRACT_UCHAR((s)+7) << 8)    \
+			 | EXTRACT_UCHAR((s)+6)) << 8)  \
+			 | EXTRACT_UCHAR((s)+5)) << 8)  \
+			 | EXTRACT_UCHAR((s)+4)) << 8)  \
+			 | EXTRACT_UCHAR((s)+3)) << 8)  \
+			 | EXTRACT_UCHAR((s)+2)) << 8)  \
+			 | EXTRACT_UCHAR((s)+1)) << 8)  \
 			 | EXTRACT_UCHAR(s))
 
 static void tiger_block(struct tiger_ctx *ctx, mutils_word8 * str)
@@ -362,35 +362,35 @@
 
 #define sub64(s0, s1, p0, p1) \
       temps0 = (p0); \
-      tcarry = s0 < temps0; \
-      s0 -= temps0; \
-      s1 -= (p1) + tcarry;
+      tcarry = (s0) < temps0; \
+      (s0) -= temps0; \
+      (s1) -= (p1) + tcarry;
 
 #define add64(s0, s1, p0, p1) \
       temps0 = (p0); \
-      s0 += temps0; \
-      tcarry = s0 < temps0; \
-      s1 += (p1) + tcarry;
+      (s0) += temps0; \
+      tcarry = (s0) < temps0; \
+      (s1) += (p1) + tcarry;
 
 #define xor64(s0, s1, p0, p1) \
-      s0 ^= (p0); \
-      s1 ^= (p1);
+      (s0) ^= (p0); \
+      (s1) ^= (p1);
 
 #define mul5(s0, s1) \
-      tempt0 = s0<<2; \
-      tempt1 = (s1<<2)|(s0>>30); \
+      tempt0 = (s0)<<2; \
+      tempt1 = ((s1)<<2)|((s0)>>30); \
       add64(s0, s1, tempt0, tempt1);
 
 #define mul7(s0, s1) \
-      tempt0 = s0<<3; \
-      tempt1 = (s1<<3)|(s0>>29); \
+      tempt0 = (s0)<<3; \
+      tempt1 = ((s1)<<3)|((s0)>>29); \
       sub64(tempt0, tempt1, s0, s1); \
-      s0 = tempt0; \
-      s1 = tempt1;
+      (s0) = tempt0; \
+      (s1) = tempt1;
 
 #define mul9(s0, s1) \
-      tempt0 = s0<<3; \
-      tempt1 = (s1<<3)|(s0>>29); \
+      tempt0 = (s0)<<3; \
+      tempt1 = ((s1)<<3)|((s0)>>29); \
       add64(s0, s1, tempt0, tempt1);
 
 #define save_abc \
@@ -497,33 +497,33 @@
   mutils_word32 i; \
   int pass_no; \
 \
-  a0 = state[0]; \
-  a1 = state[1]; \
-  b0 = state[2]; \
-  b1 = state[3]; \
-  c0 = state[4]; \
-  c1 = state[5]; \
+  a0 = (state)[0]; \
+  a1 = (state)[1]; \
+  b0 = (state)[2]; \
+  b1 = (state)[3]; \
+  c0 = (state)[4]; \
+  c1 = (state)[5]; \
 \
-  x00=str[0*2]; x01=str[0*2+1]; x10=str[1*2]; x11=str[1*2+1]; \
-  x20=str[2*2]; x21=str[2*2+1]; x30=str[3*2]; x31=str[3*2+1]; \
-  x40=str[4*2]; x41=str[4*2+1]; x50=str[5*2]; x51=str[5*2+1]; \
-  x60=str[6*2]; x61=str[6*2+1]; x70=str[7*2]; x71=str[7*2+1]; \
+  x00=(str)[0*2]; x01=(str)[0*2+1]; x10=(str)[1*2]; x11=(str)[1*2+1]; \
+  x20=(str)[2*2]; x21=(str)[2*2+1]; x30=(str)[3*2]; x31=(str)[3*2+1]; \
+  x40=(str)[4*2]; x41=(str)[4*2+1]; x50=(str)[5*2]; x51=(str)[5*2+1]; \
+  x60=(str)[6*2]; x61=(str)[6*2+1]; x70=(str)[7*2]; x71=(str)[7*2+1]; \
 \
   compress; \
 \
-  state[0] = a0; \
-  state[1] = a1; \
-  state[2] = b0; \
-  state[3] = b1; \
-  state[4] = c0; \
-  state[5] = c1; \
+  (state)[0] = a0; \
+  (state)[1] = a1; \
+  (state)[2] = b0; \
+  (state)[3] = b1; \
+  (state)[4] = c0; \
+  (state)[5] = c1; \
 }
 
 #define UNROLL_COMPRESS
 #ifdef UNROLL_COMPRESS
 /* The compress function is inlined */
 #define tiger_compress(str, state) \
-  tiger_compress_macro(((mutils_word32*)str), ((mutils_word32*)state))
+  tiger_compress_macro(((mutils_word32*)(str)), ((mutils_word32*)(state)))
 #else
 /* The compress function is a function */
 tiger_compress(__const mutils_word32 *str, mutils_word32 state[6])
@@ -537,9 +537,9 @@
 #define EXTRACT_UCHAR(p)  (*(mutils_word8 *)(p))
 #endif
 
-#define STRING2INT(s) ((((((EXTRACT_UCHAR(s+3) << 8)    \
-			 | EXTRACT_UCHAR(s+2)) << 8)  \
-			 | EXTRACT_UCHAR(s+1)) << 8)  \
+#define STRING2INT(s) ((((((EXTRACT_UCHAR((s)+3) << 8)    \
+			 | EXTRACT_UCHAR((s)+2)) << 8)  \
+			 | EXTRACT_UCHAR((s)+1)) << 8)  \
 			 | EXTRACT_UCHAR(s))
 
 static void tiger_block(struct tiger_ctx *ctx, mutils_word8 * block)
