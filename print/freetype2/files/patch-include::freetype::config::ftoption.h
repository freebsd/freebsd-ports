
$FreeBSD$

--- include/freetype/config/ftoption.h.orig	Mon Jan  7 12:05:34 2002
+++ include/freetype/config/ftoption.h	Mon Jan 21 12:37:05 2002
@@ -375,7 +375,7 @@
   /* By undefining this, you will only compile the code necessary to load  */
   /* TrueType glyphs without hinting.                                      */
   /*                                                                       */
-#undef TT_CONFIG_OPTION_BYTECODE_INTERPRETER
+#define TT_CONFIG_OPTION_BYTECODE_INTERPRETER
 
 
   /*************************************************************************/
