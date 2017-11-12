--- src/alfont.c.orig	2016-10-18 20:04:21 UTC
+++ src/alfont.c
@@ -1,3 +1,28 @@
+/*
+ * Modified Alfont 2.0.9
+ *
+ * The original AllegroFont v2.0.9 has a few problems.
+ * This modification solves them.
+ *
+ * Modification by: Alexandre Martins (thanks to http://allegro.cc forums)
+ * Modification date: 2010-10-30
+ *
+ * Modification by: Rusmir Dusko
+ * (thanks to http://allegro.cc forums and Hans de Goede [alfont] Fix undefined reference to _msize)
+ * Modification date: 2014-03-10
+ *
+ * Original Alfont website: http://chernsha.sitesled.com/
+ * AllegroFont (c) 2001, 2002 Javier Gonzalez
+ * Enhanced by Chernsha since 2004 year
+ */
+
+//#define malloc_usable_size malloc_size
+
+#ifdef __GNUC__
+#define _msize malloc_usable_size
+#include <malloc_np.h>
+#endif
+
 /* AllegroFont - a wrapper for FreeType 2 */
 /* to render TTF and other font formats with Allegro */
 
@@ -336,7 +361,7 @@ int alfont_set_font_size(ALFONT_FONT *f,
       break;
 
     /* compare real height with asked height */
-    real_height = abs(f->face->size->metrics.ascender >> 6) + abs(f->face->size->metrics.descender >> 6);
+    real_height = labs(f->face->size->metrics.ascender >> 6) + labs(f->face->size->metrics.descender >> 6);
     if (real_height == h) {
       /* we found the wanted height */
       break;
@@ -468,7 +493,7 @@ ALFONT_FONT *alfont_load_font(const char
   alfont_set_char_extra_spacing(font, 0);
 
   //Initial Font attribute
-  font->language="";		   /* Initial Language */
+  font->language=NULL;		   /* Initial Language */
   font->type=0;				   /* Initial Code Convert */
   font->outline_top=0;		   /* Initial Font top outline width */
   font->outline_bottom=0;	   /* Initial Font bottom outline width */
@@ -515,7 +540,7 @@ ALFONT_FONT *alfont_load_font_from_mem(c
   memcpy((void *)font->data, (void *)data, data_len);
 
   /* load the font */
-  error = FT_New_Memory_Face(ft_library, font->data, font->data_size, 0, &font->face);
+  error = FT_New_Memory_Face(ft_library, (unsigned char*)font->data, font->data_size, 0, &font->face);
 
   if (error) {
     free(font->data);
@@ -548,7 +573,7 @@ ALFONT_FONT *alfont_load_font_from_mem(c
   alfont_set_char_extra_spacing(font, 0);
 
   //Initial Font attribute
-  font->language="";		   /* Initial Language */
+  font->language=NULL;		   /* Initial Language */
   font->type=0;				   /* Initial Code Convert */
   font->outline_top=0;		   /* Initial Font top outline width */
   font->outline_bottom=0;	   /* Initial Font bottom outline width */
@@ -3761,15 +3786,15 @@ int alfont_ugetx(ALFONT_FONT *f, char **
   //advances the *s pointer to the next character
 
   if (f->type==1) {
-  	ugetxc((char**)s);
+  	ugetxc((const char**)s);
 	#ifdef ALFONT_LINUX
-	ugetxc((char**)s);
+	ugetxc((const char**)s);
 	#endif
   }
   else if(f->type==2) {
-	ugetxc(&lpszWS);
+	ugetxc((const char**)&lpszWS);
 	#ifdef ALFONT_LINUX
-	ugetxc(&lpszWS);
+	ugetxc((const char**)&lpszWS);
 	#endif
   	#ifdef ALFONT_DOS
 	if ((c_pt = iconv_open(f->language, "UTF-16LE")) == (iconv_t)-1) {
@@ -3814,9 +3839,9 @@ int alfont_ugetx(ALFONT_FONT *f, char **
     #ifdef ALFONT_LINUX
 	set_uformat(U_UTF8);
     #endif
-	ugetxc((char**)s);
+	ugetxc((const char**)s);
 	#ifdef ALFONT_LINUX
-	ugetxc((char**)s);
+	ugetxc((const char**)s);
 	#endif
   }
 
@@ -4083,9 +4108,9 @@ int alfont_ugetxc(ALFONT_FONT *f, const 
 	#endif
   }
   else if(f->type==2) {
-	ugetxc(&lpszWS);
+	ugetxc((const char**)&lpszWS);
 	#ifdef ALFONT_LINUX
-	ugetxc(&lpszWS);
+	ugetxc((const char**)&lpszWS);
 	#endif
   	#ifdef ALFONT_DOS
 	if ((c_pt = iconv_open(f->language, "UTF-16LE")) == (iconv_t)-1) {
@@ -4828,7 +4853,7 @@ void alfont_set_language(ALFONT_FONT *f,
   }
   else
   {
-	f->language=(char *)malloc(strlen(language)*sizeof(char));
+	f->language=(char *)malloc((strlen(language)+1)*sizeof(char));
 	strcpy(f->language,language);
   }
 }
