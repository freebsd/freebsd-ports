
$FreeBSD$

--- shs.c.orig
+++ shs.c
@@ -50,9 +50,9 @@
 #include <stdio.h>
 #include "shs.h"
 
-static long nbits;
-static unsigned long *h;
-static unsigned long *w;
+static int32_t nbits;
+static uint32_t *h;
+static uint32_t *w;
 static void shs1();
 /*
 static void packl (unsigned long);
@@ -61,7 +61,7 @@
 static void opack(unsigned char);
 */
 
-#define MASK        (unsigned long)0xffffffffL        /* in case more than 32 bits per long */
+#define MASK        (uint32_t)0xffffffffL        /* in case more than 32 bits per long */
 
 /*
  * stick one byte into the current block; process the block when full
@@ -70,14 +70,14 @@
   unsigned char c;
 {
 	int n32, nd32, shiftbits;
-	register unsigned long x, mask, y;
+	register uint32_t x, mask, y;
 	
 	nd32 = (int)(nbits >> 5);  /* nbits/32 */
 	n32 = (int)(nbits & 0x1f); /* nbits%32 */
 	shiftbits = 24-n32;
 	
-	x = (unsigned long)(c<<shiftbits);
-	mask = (unsigned long)(0xff << shiftbits);
+	x = (uint32_t)(c<<shiftbits);
+	mask = (uint32_t)(0xff << shiftbits);
 	mask = ~mask;
 	
 	y = w[nd32];
@@ -97,7 +97,7 @@
 	int nd32;
 	
 	nd32 = (int)(nbits >> 5);
-	w[nd32] = (u_long)(((u_long)c0<<24) | ((u_long)c1<<16) | ((u_long)c2<<8) | (u_long)c3);
+	w[nd32] = (uint32_t)(((uint32_t)c0<<24) | ((uint32_t)c1<<16) | ((uint32_t)c2<<8) | (uint32_t)c3);
 	
 	nbits += 32;
 	if(nbits==512){
@@ -111,7 +111,7 @@
  */
 static void
 packl(x)
-  unsigned long x;
+  uint32_t x;
 {
 	pack((unsigned char)(x>>24), (unsigned char)(x>>16),
 	     (unsigned char)(x>>8), (unsigned char)(x>>0));
@@ -123,24 +123,24 @@
 static void
 shs1()
 {
-	unsigned long *wp;
-	unsigned long temp;
-	unsigned long A, B, C, D, E;
+	uint32_t *wp;
+	uint32_t temp;
+	uint32_t A, B, C, D, E;
 	int t;
 	
-#define S(n,x) (u_long)(((x)<<(n))|((MASK&(x))>>(32-(n))))
+#define S(n,x) (uint32_t)(((x)<<(n))|((MASK&(x))>>(32-(n))))
 	
 	wp = w;
 	t = 8;
 	do {
-		wp[16] = S(1, (u_long)(wp[13]^wp[8]^wp[2]^wp[0]));
-		wp[17] = S(1, (u_long)(wp[14]^wp[9]^wp[3]^wp[1]));
-		wp[18] = S(1, (u_long)(wp[15]^wp[10]^wp[4]^wp[2]));
-		wp[19] = S(1, (u_long)(wp[16]^wp[11]^wp[5]^wp[3]));
-		wp[20] = S(1, (u_long)(wp[17]^wp[12]^wp[6]^wp[4]));
-		wp[21] = S(1, (u_long)(wp[18]^wp[13]^wp[7]^wp[5]));
-		wp[22] = S(1, (u_long)(wp[19]^wp[14]^wp[8]^wp[6]));
-		wp[23] = S(1, (u_long)(wp[20]^wp[15]^wp[9]^wp[7]));
+		wp[16] = S(1, (uint32_t)(wp[13]^wp[8]^wp[2]^wp[0]));
+		wp[17] = S(1, (uint32_t)(wp[14]^wp[9]^wp[3]^wp[1]));
+		wp[18] = S(1, (uint32_t)(wp[15]^wp[10]^wp[4]^wp[2]));
+		wp[19] = S(1, (uint32_t)(wp[16]^wp[11]^wp[5]^wp[3]));
+		wp[20] = S(1, (uint32_t)(wp[17]^wp[12]^wp[6]^wp[4]));
+		wp[21] = S(1, (uint32_t)(wp[18]^wp[13]^wp[7]^wp[5]));
+		wp[22] = S(1, (uint32_t)(wp[19]^wp[14]^wp[8]^wp[6]));
+		wp[23] = S(1, (uint32_t)(wp[20]^wp[15]^wp[9]^wp[7]));
 		wp += 8;
 		t--;
 	} while (t > 0);
@@ -154,22 +154,22 @@
 	t = 0;
 	while (t<20) {
 		temp = S(5,A) + E + w[t++];
-		temp += (unsigned long)0x5a827999L + ((B&C)|(D&~B));
+		temp += (uint32_t)0x5a827999L + ((B&C)|(D&~B));
 		E = D; D = C; C = S(30,B); B = A; A = temp;
 	}
 	while (t<40) {
 		temp = S(5,A) + E + w[t++];
-		temp += (unsigned long)0x6ed9eba1L + (B^C^D);
+		temp += (uint32_t)0x6ed9eba1L + (B^C^D);
 		E = D; D = C; C = S(30,B); B = A; A = temp;
 	}
 	while (t<60) {
 		temp = S(5,A) + E + w[t++];
-		temp += (unsigned long)0x8f1bbcdcL + ((B&C)|(B&D)|(C&D));
+		temp += (uint32_t)0x8f1bbcdcL + ((B&C)|(B&D)|(C&D));
 		E = D; D = C; C = S(30,B); B = A; A = temp;
 	}
 	while (t<80) {
 		temp = S(5,A) + E + w[t++];
-		temp += (unsigned long)0xca62c1d6L + (B^C^D);
+		temp += (uint32_t)0xca62c1d6L + (B^C^D);
 		E = D; D = C; C = S(30,B); B = A; A = temp;
 	}
 	h[0] = MASK&(h[0] + A);
@@ -179,7 +179,7 @@
 	h[4] = MASK&(h[4] + E);
 }
 
-#define CHARSTOLONG(wp,s,i) {*wp++ = (u_long)((((u_long)(s[i])&0xff)<<24)|(((u_long)(s[i+1])&0xff)<<16)|(((u_long)(s[i+2])&0xff)<<8)|(u_long)(s[i+3]&0xff));}
+#define CHARSTOLONG(wp,s,i) {*wp++ = (uint32_t)((((uint32_t)(s[i])&0xff)<<24)|(((uint32_t)(s[i+1])&0xff)<<16)|(((uint32_t)(s[i+2])&0xff)<<8)|(uint32_t)(s[i+3]&0xff));}
 
 
 void
@@ -187,11 +187,11 @@
   SHS_CTX *mdContext;
 {
 	nbits = 0;
-	mdContext->h[0] = (unsigned long)0x67452301L;
-	mdContext->h[1] = (unsigned long)0xefcdab89L;
-	mdContext->h[2] = (unsigned long)0x98badcfeL;
-	mdContext->h[3] = (unsigned long)0x10325476L;
-	mdContext->h[4] = (unsigned long)0xc3d2e1f0L;
+	mdContext->h[0] = (uint32_t)0x67452301L;
+	mdContext->h[1] = (uint32_t)0xefcdab89L;
+	mdContext->h[2] = (uint32_t)0x98badcfeL;
+	mdContext->h[3] = (uint32_t)0x10325476L;
+	mdContext->h[4] = (uint32_t)0xc3d2e1f0L;
 	mdContext->totalLength = 0;
 }
 
@@ -202,16 +202,16 @@
   unsigned char *s;
   unsigned int n;
 {
-	register unsigned long *wp;
-	long nn = n;
-	long i;
+	register uint32_t *wp;
+	int32_t nn = n;
+	int32_t i;
 	
 	w = mdContext->w;
 	h = mdContext->h;
 	mdContext->totalLength += n;
 	
 	nbits = 0;
-	n = n/(u_long)64;
+	n = n/(uint32_t)64;
 	wp = w;
 	
 	while(n>0){
@@ -240,7 +240,7 @@
 	while(i>3) {
 		CHARSTOLONG(wp,s,0);
 		s = (s + 4);
-		nbits += (u_long)32;
+		nbits += (uint32_t)32;
 		i -= 4;
 	}
 	while (i) {
@@ -253,14 +253,14 @@
 shsFinal(mdContext)
   SHS_CTX *mdContext;
 {
-	long nn = mdContext->totalLength;
+	int32_t nn = mdContext->totalLength;
 	w = mdContext->w;
 	h = mdContext->h;
 	
 	opack(128);
 	while(nbits != 448)opack(0);
-	packl((unsigned long)(nn>>29));
-	packl((unsigned long)(nn<<3));
+	packl((uint32_t)(nn>>29));
+	packl((uint32_t)(nn<<3));
 	
 	/* if(nbits != 0)
 	   handle_exception(CRITICAL,"shsFinal(): nbits != 0\n");*/
@@ -269,7 +269,7 @@
 unsigned char *
 qshs(s, n)
   unsigned char *s;
-  long n;
+  int32_t n;
 {
         SHS_CTX *mdContext;
 	static SHS_CTX mdC;
@@ -291,6 +291,7 @@
 	return ret;
 }
 
+#if 0	/* This doesn't work and isn't used.  */
 /*int fread(char *, int, int, FILE *);*/
 
 unsigned long *
@@ -316,6 +317,5 @@
 
 	return mdContext->h;
 }
-
-
+#endif
 
