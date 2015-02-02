--- texk/xdvik/dvi-draw.h.orig	2014-09-02 18:41:34.000000000 +0900
+++ texk/xdvik/dvi-draw.h	2015-01-31 21:02:18.000000000 +0900
@@ -82,6 +82,11 @@
 #define XX      currinf.data.x
 #define YY      currinf.data.y
 #define ZZ      currinf.data.z
+#ifdef PTEX
+#define TATE    currinf.data.tdir
+#else /* !PTEX */
+#define TATE    False
+#endif /* !PTEX */
 
 extern void draw_page(void);
 extern void source_reverse_search(int, int, wide_bool);
@@ -120,6 +125,13 @@
 			       wide_ubyte cmd,
 #endif
 			       wide_ubyte ch);
+#ifdef PTEX
+extern setcharRetvalT set_char2(
+#ifdef TEXXET
+				wide_ubyte cmd,
+#endif
+				wide_ubyte ch);
+#endif /* PTEX */
 extern setcharRetvalT load_n_set_char(
 #ifdef TEXXET
 				      wide_ubyte cmd,
