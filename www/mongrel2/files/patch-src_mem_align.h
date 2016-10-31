--- src/mem/align.h.orig	2016-10-31 10:10:23 UTC
+++ src/mem/align.h
@@ -30,7 +30,7 @@ union max_align
 	void (*q)(void);
 };
 
-typedef union max_align max_align_t;
+typedef union max_align h_max_align_t;
 
 #endif
 
