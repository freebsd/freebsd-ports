--- applications/utilities/miscellaneous/foamFlex/config.h.orig	Mon Dec  2 18:16:12 2002
+++ applications/utilities/miscellaneous/foamFlex/config.h	Sun Dec 18 14:37:39 2005
@@ -11,7 +11,7 @@
 #define STDC_HEADERS 1
 
 /* Define if you have the <malloc.h> header file.  */
-#define HAVE_MALLOC_H 1
+#undef HAVE_MALLOC_H
 
 /* Define if you have the <string.h> header file.  */
 #define HAVE_STRING_H 1
@@ -20,7 +20,7 @@
 #define HAVE_SYS_TYPES_H 1
 
 /* Define if you have <alloca.h> and it should be used (not on Ultrix).  */
-#define HAVE_ALLOCA_H 1
+#undef HAVE_ALLOCA_H
 
 /* Define if platform-specific command line handling is necessary.  */
 /* #undef NEED_ARGV_FIXUP */
