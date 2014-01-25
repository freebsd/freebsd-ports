--- src/mpeg2/kdecmpeg2.cpp.orig	2009-12-06 10:13:36.000000000 +0000
+++ src/mpeg2/kdecmpeg2.cpp	2013-12-06 15:00:15.000000000 +0000
@@ -286,6 +286,7 @@
 	      }
     	}
     }
+    return 0;
 }
 
 void kDecMPEG2::sync() {
