--- src/radeon_accel.c.orig	2012-04-15 19:36:08.000000000 +0200
+++ src/radeon_accel.c	2012-04-15 19:36:15.000000000 +0200
@@ -982,10 +982,9 @@
 
 	    for (; nwords > 0; --nwords, ++d, ++s)
 #ifdef __powerpc__
-		asm volatile("stwbrx %0,0,%1" : : "r" (*s), "r" (d));
+		asm volatile("sthbrx %0,0,%1" : : "r" (*s), "r" (d));
 #else
-	        *d = ((*s >> 24) & 0xff) | ((*s >> 8) & 0xff00)
-			| ((*s & 0xff00) << 8) | ((*s & 0xff) << 24);
+		*d = (*s >> 8) | (*s << 8);
 #endif
 	    return;
 	}


