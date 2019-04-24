Workaround for potential optimizer bug in clang 8 that causes hangs at runtime

https://github.com/michaelrsweet/htmldoc/issues/349

--- htmldoc/ps-pdf.cxx.orig	2018-04-10 11:56:03 UTC
+++ htmldoc/ps-pdf.cxx
@@ -5361,7 +5361,7 @@ parse_pre(tree_t *t,		/* I - Tree to parse */
 		line[10240],
 		*lineptr,
 		*dataptr;
-  int		col;
+  volatile int	col;
   float		width,
 		height,
 		rgb[3];
