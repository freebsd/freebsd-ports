
$FreeBSD$

--- include/freetype/config/ftoption.h	2001/07/03 08:51:20	1.1
+++ include/freetype/config/ftoption.h	2001/07/03 08:51:56
@@ -321,7 +321,7 @@
   /* By undefining this, you will only compile the code necessary to load  */
   /* TrueType glyphs without hinting.                                      */
   /*                                                                       */
-#undef  TT_CONFIG_OPTION_BYTECODE_INTERPRETER
+#define  TT_CONFIG_OPTION_BYTECODE_INTERPRETER
 
 
   /*************************************************************************/
