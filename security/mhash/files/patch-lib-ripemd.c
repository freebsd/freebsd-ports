diff -urN -x .svn ../../branches/vendor/mhash/lib/ripemd.c ./lib/ripemd.c
--- ../../branches/vendor/mhash/lib/ripemd.c	2008-01-16 14:26:51.000000000 +0200
+++ ./lib/ripemd.c	2008-01-16 15:02:04.000000000 +0200
@@ -55,13 +55,13 @@
 /* 32-bit rotate left - kludged with shifts */
 #define ROTL(n,X)  (((X)<<(n))|((X)>>(32-(n))))
 
-#define f0(x,y,z)  (x^y^z)
+#define f0(x,y,z)  ((x)^(y)^(z))
 //#define f16(x,y,z) ((x&y)|(~(x) & z))
 #define f16(x,y,z) ((z)^((x)&((y)^(z))))
-#define f32(x,y,z) ((x|~(y))^z)
+#define f32(x,y,z) (((x)|~(y))^(z))
 //#define f48(x,y,z) ((x&z)|(y&~(z)))
 #define f48(x,y,z) ((y)^((z)&((x)^(y))))
-#define f64(x,y,z) (x^(y|(~z)))
+#define f64(x,y,z) ((x)^((y)|(~(z))))
 
 #define K0  0x00000000
 #define K1  0x5A827999     /* 2^30 * sqrt(2) */
@@ -913,9 +913,9 @@
 #define EXTRACT_UCHAR(p)  (*(mutils_word8 *)(p))
 #endif
 
-#define STRING2INT(s) ((((((EXTRACT_UCHAR(s+3) << 8)    \
-			 | EXTRACT_UCHAR(s+2)) << 8)  \
-			 | EXTRACT_UCHAR(s+1)) << 8)  \
+#define STRING2INT(s) ((((((EXTRACT_UCHAR((s)+3) << 8)    \
+			 | EXTRACT_UCHAR((s)+2)) << 8)  \
+			 | EXTRACT_UCHAR((s)+1)) << 8)  \
 			 | EXTRACT_UCHAR(s))
 
 static void ripemd_block(struct ripemd_ctx *ctx, mutils_word8 *block)
