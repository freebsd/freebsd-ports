--- APIModules/QTSSReflectorModule/ReflectorStream.cpp.orig	Thu Jun 10 09:03:34 2004
+++ APIModules/QTSSReflectorModule/ReflectorStream.cpp	Fri Jan 21 10:23:11 2005
@@ -179,7 +179,7 @@
     theRRWriter++;
     *theRRWriter = htonl(theSsrc);
     theRRWriter++;
-    *theRRWriter = FOUR_CHARS_TO_INT('Q','T','S','S');
+    *theRRWriter = htonl(FOUR_CHARS_TO_INT('Q','T','S','S'));
     theRRWriter++;
     *theRRWriter = htonl(0);
     theRRWriter++;
