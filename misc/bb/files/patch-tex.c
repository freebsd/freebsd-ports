--- tex.c.orig	2026-02-12 17:46:39 UTC
+++ tex.c
@@ -128,8 +128,8 @@ static inline void makej(long x1, long x2, long n1z, l
     off1 = off + x2 - x1;
     for (; off <= off1;) {
 
-	ry = (abs(n3y) >> 7) + 64;
-	rx = (abs(n3x) >> 7) + 64;
+	ry = (labs(n3y) >> 7) + 64;
+	rx = (labs(n3x) >> 7) + 64;
 	if (((n3z >> 8) - *zbptr) < 500) {
 	    *off = *(envmapa + (((unsigned int) ((ry << 7) + rx)) & (128 * 128 - 1)));
 	    *zbptr = n3z >> 8;
