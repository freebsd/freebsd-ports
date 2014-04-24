--- util/grub-mkfont.c.orig
+++ util/grub-mkfont.c
@@ -39,7 +39,7 @@
 #include FT_FREETYPE_H
 #include FT_TRUETYPE_TAGS_H
 #include FT_TRUETYPE_TABLES_H
-#include <freetype/ftsynth.h>
+#include FT_SYNTHESIS_H
 
 #undef __FTERRORS_H__
 #define FT_ERROR_START_LIST   const char *ft_errmsgs[] = { 


