
$FreeBSD$

--- include/freetype/config/ftoption.h.orig	Thu Nov  7 00:32:53 2002
+++ include/freetype/config/ftoption.h	Fri Jan 17 20:44:08 2003
@@ -378,7 +378,7 @@
   /*   do not #undef this macro here, since the build system might         */
   /*   define for certain configurations                                   */
   /*                                                                       */
-/* #define  TT_CONFIG_OPTION_BYTECODE_INTERPRETER */
+#define  TT_CONFIG_OPTION_BYTECODE_INTERPRETER
 
 
   /*************************************************************************/
