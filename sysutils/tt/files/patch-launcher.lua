--- cli/running/lua/launcher.orig	2024-02-07 21:26:29.143544000 +0300
+++ cli/running/lua/launcher.lua	2024-02-07 21:26:51.277954000 +0300
@@ -247,7 +247,7 @@
         void setlinebuf(FILE *stream);
     ]])
 
-    if jit.os == 'OSX' then
+    if jit.os == 'OSX' or jit.os == 'BSD' then
         ffi.cdef([[
             FILE *__stdoutp;
         ]])
