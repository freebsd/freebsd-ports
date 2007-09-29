diff -rpu8 sysdep/common/libsysdep/sha1.c sysdep-FIXED/common/libsysdep/sha1.c
--- sysdep/common/libsysdep/sha1.c	Sun Jan 28 23:38:48 2001
+++ sysdep-FIXED/common/libsysdep/sha1.c	Sat Mar 25 02:48:19 2006
@@ -46,22 +46,22 @@ A million repetitions of "a"
 #define R1(v,w,x,y,z,i) z+=((w&(x^y))^y)+blk(i)+0x5A827999+rol(v,5);w=rol(w,30);
 #define R2(v,w,x,y,z,i) z+=(w^x^y)+blk(i)+0x6ED9EBA1+rol(v,5);w=rol(w,30);
 #define R3(v,w,x,y,z,i) z+=(((w|x)&y)|(w&x))+blk(i)+0x8F1BBCDC+rol(v,5);w=rol(w,30);
 #define R4(v,w,x,y,z,i) z+=(w^x^y)+blk(i)+0xCA62C1D6+rol(v,5);w=rol(w,30);
 
 
 /* Hash a single 512-bit block. This is the core of the algorithm. */
 
-void SHA1Transform(unsigned long state[5], unsigned char buffer[64])
+void SHA1Transform(UINT4 state[5], unsigned char buffer[64])
 {
-unsigned long a, b, c, d, e;
+UINT4 a, b, c, d, e;
 typedef union {
     unsigned char c[64];
-    unsigned long l[16];
+    UINT4 l[16];
 } CHAR64LONG16;
 CHAR64LONG16* block;
 #ifdef SHA1HANDSOFF
 static CHAR64LONG16 workspace;
     block = &workspace;
     memcpy(block, buffer, 64);
 #else
     block = (CHAR64LONG16*)buffer;
@@ -118,17 +118,17 @@ void SHA1Init(SHA1_CTX* context)
 }
 
 
 /* Run your data through this. */
 
 void SHA1Update(SHA1_CTX* context, unsigned char* data, unsigned int len)
 {
 unsigned int i;
-unsigned long j;
+UINT4 j;
 
     j = context->count[0];
     if ((context->count[0] += len << 3) < j) context->count[1] += (len>>29)+1;
     j = (j >> 3) & 63;
     if ((j + len) > 63) {
         memcpy(&context->buffer[j], data, (i = 64-j));
         SHA1Transform(context->state, context->buffer);
         for ( ; i + 63 < len; i += 64) {
@@ -140,17 +140,17 @@ unsigned long j;
     memcpy(&context->buffer[j], &data[i], len - i);
 }
 
 
 /* Add padding and return the message digest. */
 
 void SHA1Final(unsigned char digest[20], SHA1_CTX* context)
 {
-unsigned long i, j;
+UINT4 i, j;
 unsigned char finalcount[8];
 
     for (i = 0; i < 8; i++) {
         finalcount[i] = (unsigned char)((context->count[(i >= 4 ? 0 : 1)]
          >> ((3-(i & 3)) * 8) ) & 255);  /* Endian independent */
     }
     SHA1Update(context, (unsigned char *)"\200", 1);
     while ((context->count[0] & 504) != 448) {
