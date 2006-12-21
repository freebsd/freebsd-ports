--- fltk/wstring.h.orig	Thu Dec 21 17:03:29 2006
+++ fltk/wstring.h	Thu Dec 21 17:03:41 2006
@@ -88,7 +88,7 @@
 		long     operator>(const char *str) const { return (strcmp(buffer,str) > 0); };
 		long     operator==(const char *str) const  { return (strcmp(buffer,str) == 0); };
         wString& operator=(const char *str)	{ SSet(str);  return (*this); };
-        RCLDLL wString& wString::operator=(const wString& str) { SSet(str.buffer); return (*this); }
+        RCLDLL wString& operator=(const wString& str) { SSet(str.buffer); return (*this); }
         wString& operator=(const unsigned char *str)    { SSet((const char *)str); return *this; };
 		operator const char *() const       { return Get(); };
 		wString& ToUpper()	{ strupr(buffer);  return *this; };
