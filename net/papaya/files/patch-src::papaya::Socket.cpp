--- src/papaya/Socket.cpp.orig	Fri Jan  9 15:13:24 2004
+++ src/papaya/Socket.cpp	Fri Jan  9 15:13:34 2004
@@ -428,7 +428,7 @@
       c = inbuf.getLength();
     }
 
-    return read(min(b, c), dest);
+    return read(std::min(b, c), dest);
 }
 
 /**
