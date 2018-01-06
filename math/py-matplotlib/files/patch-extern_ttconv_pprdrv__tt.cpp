extern/ttconv/pprdrv_tt.cpp:245:41: error: cast from pointer to smaller type 'char' loses information
                font->Copyright[length]=(char)NULL;
                                        ^~~~~~~~~~
extern/ttconv/pprdrv_tt.cpp:261:42: error: cast from pointer to smaller type 'char' loses information
                font->FamilyName[length]=(char)NULL;
                                         ^~~~~~~~~~
extern/ttconv/pprdrv_tt.cpp:277:37: error: cast from pointer to smaller type 'char' loses information
                font->Style[length]=(char)NULL;
                                    ^~~~~~~~~~
extern/ttconv/pprdrv_tt.cpp:293:40: error: cast from pointer to smaller type 'char' loses information
                font->FullName[length]=(char)NULL;
                                       ^~~~~~~~~~
extern/ttconv/pprdrv_tt.cpp:309:39: error: cast from pointer to smaller type 'char' loses information
                font->Version[length]=(char)NULL;
                                      ^~~~~~~~~~
extern/ttconv/pprdrv_tt.cpp:325:40: error: cast from pointer to smaller type 'char' loses information
                font->PostName[length]=(char)NULL;
                                       ^~~~~~~~~~
extern/ttconv/pprdrv_tt.cpp:340:42: error: cast from pointer to smaller type 'char' loses information
                font->PostName[length/2]=(char)NULL;
                                         ^~~~~~~~~~
extern/ttconv/pprdrv_tt.cpp:355:41: error: cast from pointer to smaller type 'char' loses information
                font->Trademark[length]=(char)NULL;
                                        ^~~~~~~~~~
extern/ttconv/pprdrv_tt.cpp:1041:19: error: cast from pointer to smaller type 'char' loses information
        temp[len]=(char)NULL;   /* a buffer and make it ASCIIz. */
                  ^~~~~~~~~~

--- extern/ttconv/pprdrv_tt.cpp.orig	2016-09-09 02:50:50 UTC
+++ extern/ttconv/pprdrv_tt.cpp
@@ -242,7 +242,7 @@ void Read_name(struct TTFONT *font)
             {
                 font->Copyright = (char*)calloc(sizeof(char),length+1);
                 strncpy(font->Copyright,(const char*)strings+offset,length);
-                font->Copyright[length]=(char)NULL;
+                font->Copyright[length]='\0';
                 replace_newlines_with_spaces(font->Copyright);
 
 #ifdef DEBUG_TRUETYPE
@@ -258,7 +258,7 @@ void Read_name(struct TTFONT *font)
                 free(font->FamilyName);
                 font->FamilyName = (char*)calloc(sizeof(char),length+1);
                 strncpy(font->FamilyName,(const char*)strings+offset,length);
-                font->FamilyName[length]=(char)NULL;
+                font->FamilyName[length]='\0';
                 replace_newlines_with_spaces(font->FamilyName);
 
 #ifdef DEBUG_TRUETYPE
@@ -274,7 +274,7 @@ void Read_name(struct TTFONT *font)
                 free(font->Style);
                 font->Style = (char*)calloc(sizeof(char),length+1);
                 strncpy(font->Style,(const char*)strings+offset,length);
-                font->Style[length]=(char)NULL;
+                font->Style[length]='\0';
                 replace_newlines_with_spaces(font->Style);
 
 #ifdef DEBUG_TRUETYPE
@@ -290,7 +290,7 @@ void Read_name(struct TTFONT *font)
                 free(font->FullName);
                 font->FullName = (char*)calloc(sizeof(char),length+1);
                 strncpy(font->FullName,(const char*)strings+offset,length);
-                font->FullName[length]=(char)NULL;
+                font->FullName[length]='\0';
                 replace_newlines_with_spaces(font->FullName);
 
 #ifdef DEBUG_TRUETYPE
@@ -306,7 +306,7 @@ void Read_name(struct TTFONT *font)
                 free(font->Version);
                 font->Version = (char*)calloc(sizeof(char),length+1);
                 strncpy(font->Version,(const char*)strings+offset,length);
-                font->Version[length]=(char)NULL;
+                font->Version[length]='\0';
                 replace_newlines_with_spaces(font->Version);
 
 #ifdef DEBUG_TRUETYPE
@@ -322,7 +322,7 @@ void Read_name(struct TTFONT *font)
                 free(font->PostName);
                 font->PostName = (char*)calloc(sizeof(char),length+1);
                 strncpy(font->PostName,(const char*)strings+offset,length);
-                font->PostName[length]=(char)NULL;
+                font->PostName[length]='\0';
                 replace_newlines_with_spaces(font->PostName);
 
 #ifdef DEBUG_TRUETYPE
@@ -337,7 +337,7 @@ void Read_name(struct TTFONT *font)
                 free(font->PostName);
                 font->PostName = (char*)calloc(sizeof(char),length+1);
                 utf16be_to_ascii(font->PostName, (char *)strings+offset, length);
-                font->PostName[length/2]=(char)NULL;
+                font->PostName[length/2]='\0';
                 replace_newlines_with_spaces(font->PostName);
 
 #ifdef DEBUG_TRUETYPE
@@ -352,7 +352,7 @@ void Read_name(struct TTFONT *font)
             {
                 font->Trademark = (char*)calloc(sizeof(char),length+1);
                 strncpy(font->Trademark,(const char*)strings+offset,length);
-                font->Trademark[length]=(char)NULL;
+                font->Trademark[length]='\0';
                 replace_newlines_with_spaces(font->Trademark);
 
 #ifdef DEBUG_TRUETYPE
@@ -1038,7 +1038,7 @@ const char *ttfont_CharStrings_getname(struct TTFONT *
         }
 
         strncpy(temp,ptr,len);  /* Copy the pascal string into */
-        temp[len]=(char)NULL;   /* a buffer and make it ASCIIz. */
+        temp[len]='\0';   /* a buffer and make it ASCIIz. */
 
         return temp;
     }
