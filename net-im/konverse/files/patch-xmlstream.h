--- konverse/xmlstream.cpp	2001/04/07 03:37:01	1.11
+++ konverse/xmlstream.cpp	2002/02/25 04:20:53	1.12
@@ -167,7 +167,7 @@
 
  	bytesWritten = write(fd, (void *)(const char *)utf, utf.length());
 
-        if ( bytesWritten != (int)s.length() )
+        if ( bytesWritten != (int)utf.length() )
 		connectionLost();
 
         return bytesWritten;

