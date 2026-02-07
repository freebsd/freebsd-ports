--- generic/tclXchmod.c.orig	2014-07-30 17:45:54.000000000 +0200
+++ generic/tclXchmod.c	2014-07-30 17:48:09.000000000 +0200
@@ -353,6 +353,7 @@
 	modeInfo.absMode = modeBits;
         modeInfo.symMode = NULL;
     } else {
+        modeInfo.absMode = 0; // not used, but keeps compilers happy
         modeInfo.symMode = modeString;
     }
 
