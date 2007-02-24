--- libs/libmythtv/mpegrecorder.cpp.orig	Wed Jan 31 22:18:54 2007
+++ libs/libmythtv/mpegrecorder.cpp	Wed Jan 31 16:16:27 2007
@@ -603,7 +603,7 @@
         tv.tv_usec = 0;
         FD_ZERO(&rdset);
         FD_SET(readfd, &rdset);
-
+#ifdef _nuniet_
         switch (select(readfd + 1, &rdset, NULL, NULL, &tv))
         {
             case -1:
@@ -627,6 +627,7 @@
 
            default: break;
         }
+#endif
 
         ret = read(readfd, buffer, bufferSize);
 
