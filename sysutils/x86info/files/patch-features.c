--- features.c.orig	2011-09-16 16:57:57.000000000 -0700
+++ features.c	2011-09-16 16:58:06.000000000 -0700
@@ -469,7 +469,7 @@
 	died = sigsetjmp(out, 1);
 
 	if (!died)
-		asm volatile("nopl 0(%eax)");
+		asm volatile(".byte 0x0f,0x1f,0x00 /* nopl 0(%eax) */");
 
 	printf("Long NOPs supported: %s\n", died ? "no" : "yes");
 }
