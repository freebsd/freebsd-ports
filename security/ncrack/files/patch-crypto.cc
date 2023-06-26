--- crypto.cc.orig	2019-08-24 22:25:32 UTC
+++ crypto.cc
@@ -573,7 +573,7 @@ int edf
 int edf
 )
 {
-	register int i, j, l, m, n;
+	int i, j, l, m, n;
 	unsigned char pc1m[56], pcr[56];
 	unsigned long kn[32];
 
@@ -609,12 +609,12 @@ static void cookey(
 //static void cookey(raw1)
 //register unsigned long *raw1;
 static void cookey(
-register unsigned long *raw1
+unsigned long *raw1
 )
 {
-	register unsigned long *cook, *raw0;
+	unsigned long *cook, *raw0;
 	unsigned long dough[32];
-	register int i;
+	int i;
 
 	cook = dough;
 	for( i = 0; i < 16; i++, raw1++ ) {
@@ -635,10 +635,10 @@ void cpkey(
 //void cpkey(into)
 //register unsigned long *into;
 void cpkey(
-register unsigned long *into
+unsigned long *into
 )
 {
-	register unsigned long *from, *endp;
+	unsigned long *from, *endp;
 
 	from = KnL, endp = &KnL[32];
 	while( from < endp ) *into++ = *from++;
@@ -648,10 +648,10 @@ void usekey(
 //void usekey(from)
 //register unsigned long *from;
 void usekey(
-register unsigned long *from
+unsigned long *from
 )
 {
-	register unsigned long *to, *endp;
+	unsigned long *to, *endp;
 
 	to = KnL, endp = &KnL[32];
 	while( to < endp ) *to++ = *from++;
@@ -676,8 +676,8 @@ static void scrunch(
 //register unsigned char *outof;
 //register unsigned long *into;
 static void scrunch(
-register unsigned char *outof,
-register unsigned long *into
+unsigned char *outof,
+unsigned long *into
 )
 {
 	*into	 = (*outof++ & 0xffL) << 24;
@@ -695,8 +695,8 @@ static void unscrun(
 //register unsigned long *outof;
 //register unsigned char *into;
 static void unscrun(
-register unsigned long *outof,
-register unsigned char *into
+unsigned long *outof,
+unsigned char *into
 )
 {
 	*into++ = (*outof >> 24) & 0xffL;
@@ -857,11 +857,11 @@ static void desfunc(
 //static void desfunc(block, keys)
 //register unsigned long *block, *keys;
 static void desfunc(
-register unsigned long *block, register unsigned long *keys
+unsigned long *block, unsigned long *keys
 )
 {
-	register unsigned long fval, work, right, leftt;
-	register int round;
+	unsigned long fval, work, right, leftt;
+	int round;
 
 	leftt = block[0];
 	right = block[1];
