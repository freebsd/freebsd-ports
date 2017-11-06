--- base64.cpp.orig	2017-02-01 19:29:59 UTC
+++ base64.cpp
@@ -114,6 +114,7 @@ uchar   pBase64[]   =   {               
 char *b64decode(const char *s)
 {
     int     l = strlen(s);                  // Get length of Base64 string.
+    const char *p;                          // Separator position
     char   *b;                              // Decoding buffer pointers.
     uchar   c = 0;                          // Character to decode.
     int     x = 0;                          // General purpose integers.
@@ -126,12 +127,12 @@ char *b64decode(const char *s)
     if  (l % 4)                             // If it's not modulo 4, then it...
         return b64isnot(NULL);              // ...can't be a Base64 string.
 
-    if  ((b = strchr(s, pPad[0])) != NULL)  // Only one, two or three equal...
+    if  ((p = strchr(s, pPad[0])) != NULL)  // Only one, two or three equal...
     {                                       // ...'=' signs are allowed at...
-        if  ((b - s) < (l - 3))             // ...the end of the Base64 string.
+        if  ((p - s) < (l - 3))             // ...the end of the Base64 string.
             return b64isnot(NULL);          // Any other equal '=' signs are...
         else                                // ...invalid.
-            if  (strncmp(b, (const char *) pPad + 3 - (s + l - b), s + l - b))
+            if  (strncmp(p, (const char *) pPad + 3 - (s + l - p), s + l - p))
                 return b64isnot(NULL);
     }
 
