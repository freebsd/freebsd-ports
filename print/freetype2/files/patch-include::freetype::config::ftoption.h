
$FreeBSD$

--- include/freetype/config/ftoption.h.orig	Sat Jun  8 04:05:56 2002
+++ include/freetype/config/ftoption.h	Fri Jun 21 15:49:27 2002
@@ -82,7 +82,7 @@
   /*                                                                       */
   /*   Define this if you want generic cmap support.                       */
   /*                                                                       */
-#define FT_CONFIG_OPTION_USE_CMAPS
+#undef FT_CONFIG_OPTION_USE_CMAPS
 
 
   /*************************************************************************/
@@ -375,7 +375,7 @@
   /* By undefining this, you will only compile the code necessary to load  */
   /* TrueType glyphs without hinting.                                      */
   /*                                                                       */
-#undef  TT_CONFIG_OPTION_BYTECODE_INTERPRETER
+#define  TT_CONFIG_OPTION_BYTECODE_INTERPRETER
 
 
   /*************************************************************************/
