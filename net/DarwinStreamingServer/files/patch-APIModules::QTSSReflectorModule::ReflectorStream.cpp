--- APIModules/QTSSReflectorModule/ReflectorStream.cpp.orig	Sat Aug 16 08:52:46 2003
+++ APIModules/QTSSReflectorModule/ReflectorStream.cpp	Thu Dec 16 23:29:41 2004
@@ -173,7 +173,7 @@
     theRRWriter++;
     *theRRWriter = htonl(theSsrc);
     theRRWriter++;
-    *theRRWriter = FOUR_CHARS_TO_INT('Q','T','S','S');
+    *theRRWriter = htonl(FOUR_CHARS_TO_INT('Q','T','S','S'));
     theRRWriter++;
     *theRRWriter = htonl(0);
     theRRWriter++;
