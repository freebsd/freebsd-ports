--- src/genmd.cc.orig
+++ src/genmd.cc
@@ -65,7 +65,6 @@
 }
 
 #if !(defined(OS_WIN32) || LAPACK_OS_WIN32)
-extern "C" double drand48(void) throw ();
 #endif
 
 LaGenMatDouble& LaRandUniform(LaGenMatDouble &A, 
