--- texk/xdvik/dvi-draw.h.orig	2019-07-27 23:56:42 UTC
+++ texk/xdvik/dvi-draw.h
@@ -81,6 +81,11 @@ extern void src_parse(const char *str, int str_len, st
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
@@ -119,6 +124,13 @@ extern setcharRetvalT set_char(
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
