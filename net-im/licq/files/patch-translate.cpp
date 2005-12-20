--- src/translate.cpp.orig	Thu Oct 13 17:09:23 2005
+++ src/translate.cpp	Sun Dec 11 16:46:24 2005
@@ -223,7 +223,8 @@
   char *szNewStr = new char[nLen + 1];
   size_t nInSize, nOutSize;
 
-  char *szIn = _sz, *szOut = szNewStr;
+  const char *szIn = _sz;
+  char *szOut = szNewStr;
   iconv_t tr;
 
   nInSize = nLen;
@@ -268,7 +269,8 @@
   char *szNewStr = new char[nLen + 1];
   size_t nInSize, nOutSize;
 
-  char *szIn = _sz, *szOut = szNewStr;
+  const char *szIn = _sz;
+  char *szOut = szNewStr;
   iconv_t tr;
 
   nInSize = nLen;
@@ -312,7 +314,8 @@
   char *szNewStr = new char[nLen * 2];
   size_t nInSize, nOutSize;
   
-  char *szIn = _sz, *szOut = szNewStr;
+  const char *szIn = _sz;
+  char *szOut = szNewStr;
   iconv_t tr;
   
   nInSize = nLen;
@@ -339,11 +342,21 @@
   unsigned short nLen = strlen(_sz) * 3;
   char *szNewStr = new char[nLen + 1];
   size_t nInSize, nOutSize;
-  char *szOut = szNewStr, *szIn = _sz;
+  const char *szIn = _sz;
+  char *szOut = szNewStr;
   iconv_t tr;
   
   nInSize = strlen(szIn);
   nOutSize = nLen;
+  //--- deleting ' ' from _szEncoding ---
+  char *_szEnc_tmp = _szEncoding, *_szEnc_tmp2 = _szEncoding;
+  int _szflag = 0;
+  while (*_szEnc_tmp)
+  {
+    if (*_szEnc_tmp == ' ') {*_szEnc_tmp++; _szflag++;}
+    *_szEnc_tmp2++ = *_szEnc_tmp++;
+  }
+  while(_szflag--) --(*_szEnc_tmp2) = '\0';
   
   tr = iconv_open("UCS-2BE", _szEncoding);
   size_t ret = iconv(tr, &szIn, &nInSize, &szOut, &nOutSize);

