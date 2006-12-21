--- FL/wstring.h.orig	Thu Dec 21 16:56:48 2006
+++ FL/wstring.h	Thu Dec 21 16:57:03 2006
@@ -88,7 +88,7 @@
 		long     operator>(const char *str) const { return (strcmp(buffer,str) > 0); };
 		long     operator==(const char *str) const  { return (strcmp(buffer,str) == 0); };
         wString& operator=(const char *str)	{ SSet(str);  return (*this); };
-        RCLDLL wString& wString::operator=(const wString& str) { SSet(str.buffer); return (*this); }
+        RCLDLL wString& operator=(const wString& str) { SSet(str.buffer); return (*this); }
         wString& operator=(const unsigned char *str)    { SSet((const char *)str); return *this; };
 		operator const char *() const       { return Get(); };
 		wString& ToUpper()	{ strupr(buffer);  return *this; };
