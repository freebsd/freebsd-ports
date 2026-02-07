--- compface/compress.c.orig
+++ compface/compress.c
@@ -17,97 +17,105 @@
 #include "compface.h"
 
 int
-Same(char *f, int wid, int hei)
+Same(f, wid, hei)
+register char *f;
+register int wid, hei;
 {
-	char val, *row;
-	int x;
+	register char val, *row;
+	register int x;
 
 	val = *f;
-	while (hei--) {
+	while (hei--)
+	{
 		row = f;
 		x = wid;
-		while (x--) {
-			if (*(row++) != val) {
+		while (x--)
+			if (*(row++) != val)
 				return(0);
-            }
-        }
 		f += WIDTH;
 	}
-	return(1);
+	return 1;
 }
 
-
 int
-AllBlack(char *f, int wid, int hei)
+AllBlack(f, wid, hei)
+char *f;
+int wid, hei;
 {
-	if (wid > 3) {
+	if (wid > 3)
+	{
 		wid /= 2;
 		hei /= 2;
-		return(AllBlack(f, wid, hei) && AllBlack(f + wid, wid, hei) &&
+		return (AllBlack(f, wid, hei) && AllBlack(f + wid, wid, hei) &&
 		       AllBlack(f + WIDTH * hei, wid, hei) &&
 		       AllBlack(f + WIDTH * hei + wid, wid, hei));
-	} else {
-		return(*f || *(f + 1) || *(f + WIDTH) || *(f + WIDTH + 1));
     }
+	else
+		return (*f || *(f + 1) || *(f + WIDTH) || *(f + WIDTH + 1));
 }
 
-
 int
-AllWhite(char *f, int wid, int hei)
+AllWhite(f, wid, hei)
+char *f;
+int wid, hei;
 {
-	return((*f == 0) && Same(f, wid, hei));
+	return ((*f == 0) && Same(f, wid, hei));
 }
 
-
 void
-PopGreys(char *f, int wid, int hei)
+PopGreys(f, wid, hei)
+char *f;
+int wid, hei;
 {
-	if (wid > 3) {
+	if (wid > 3)
+	{
 		wid /= 2;
 		hei /= 2;
 		PopGreys(f, wid, hei);
 		PopGreys(f + wid, wid, hei);
 		PopGreys(f + WIDTH * hei, wid, hei);
 		PopGreys(f + WIDTH * hei + wid, wid, hei);
-	} else {
+	}
+	else
+	{
 		wid = BigPop(freqs);
-		if (wid & 1) {
+		if (wid & 1)
 			*f = 1;
-        }
-		if (wid & 2) {
+		if (wid & 2)
 			*(f + 1) = 1;
-        }
-		if (wid & 4) {
+		if (wid & 4)
 			*(f + WIDTH) = 1;
-        }
-		if (wid & 8) {
+		if (wid & 8)
 			*(f + WIDTH + 1) = 1;
         }
-	}
 }
 
-
 void
-PushGreys(char *f, int wid, int hei)
+PushGreys(f, wid, hei)
+char *f;
+int wid, hei;
 {
-	if (wid > 3) {
+	if (wid > 3)
+	{
 		wid /= 2;
 		hei /= 2;
 		PushGreys(f, wid, hei);
 		PushGreys(f + wid, wid, hei);
 		PushGreys(f + WIDTH * hei, wid, hei);
 		PushGreys(f + WIDTH * hei + wid, wid, hei);
-	} else {
-		RevPush(freqs + *f + 2 * *(f + 1) + 
-                4 * *(f + WIDTH) + 8 * *(f + WIDTH + 1));
     }
+	else
+		RevPush(freqs + *f + 2 * *(f + 1) + 4 * *(f + WIDTH) +
+		  8 * *(f + WIDTH + 1));
 }
 
-
 void
-UnCompress(char *f, int wid, int hei, int lev)
+UnCompress(f, wid, hei, lev)
+register char *f;
+register int wid, hei, lev;
 {
-	switch (BigPop(&levels[lev][0])) {
+	switch (BigPop(&levels[lev][0]))
+	{
 		case WHITE :
 			return;
 		case BLACK :
@@ -125,15 +133,18 @@
 	}
 }
 
-
 void
-Compress(char *f, int wid, int hei, int lev)
+Compress(f, wid, hei, lev)
+register char *f;
+register int wid, hei, lev;
 {
-	if (AllWhite(f, wid, hei)) {
+	if (AllWhite(f, wid, hei))
+	{
 		RevPush(&levels[lev][WHITE]);
 		return;
 	}
-	if (AllBlack(f, wid, hei)) {
+	if (AllBlack(f, wid, hei))
+	{
 		RevPush(&levels[lev][BLACK]);
 		PushGreys(f, wid, hei);
 		return;
@@ -149,16 +160,16 @@
 }
 
 void
-UnCompAll(char *fbuf)
+UnCompAll(fbuf)
+char *fbuf;
 {
-	char *p;
+	register char *p;
 
 	BigClear();
 	BigRead(fbuf);
 	p = F;
-	while (p < F + PIXELS) {
+	while (p < F + PIXELS)
 		*(p++) = 0;
-    }
 	UnCompress(F, 16, 16, 0);
 	UnCompress(F + 16, 16, 16, 0);
 	UnCompress(F + 32, 16, 16, 0);
@@ -171,7 +182,8 @@
 }
 
 void
-CompAll(char *fbuf)
+CompAll(fbuf)
+char *fbuf;
 {
 	Compress(F, 16, 16, 0);
 	Compress(F + 16, 16, 16, 0);
@@ -183,8 +195,7 @@
 	Compress(F + WIDTH * 32 + 16, 16, 16, 0);
 	Compress(F + WIDTH * 32 + 32, 16, 16, 0);
 	BigClear();
-	while (NumProbs > 0) {
+	while (NumProbs > 0)
 		BigPush(ProbBuf[--NumProbs]);
-    }
 	BigWrite(fbuf);
 }
