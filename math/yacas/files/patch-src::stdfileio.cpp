--- src/stdfileio.cpp	2003/02/10 18:53:56	1.5
+++ src/stdfileio.cpp	2004/07/03 19:32:15	1.6
@@ -99,7 +99,7 @@
     iCurrentPos = 0;
     fread(iBuffer,iNrBytes,1,iFile);
     iBuffer[iNrBytes] = '\0';
-};
+}
 
 LispChar CachedStdFileInput::Next()
 {
@@ -222,7 +222,7 @@
 {
 //printf("CachedStdUserInput:construct\n");
     Rewind();
-};
+}
 LispChar CachedStdUserInput::Next()
 {
 //printf("CachedStdUserInput:Next\n");
