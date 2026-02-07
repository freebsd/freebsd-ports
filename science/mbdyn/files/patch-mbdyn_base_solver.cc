--- mbdyn/base/solver.cc.orig	2021-04-22 19:30:51 UTC
+++ mbdyn/base/solver.cc
@@ -85,6 +85,7 @@
 #include "ac/arpack.h"
 #include "eigjdqz.h"
 
+extern "C" {int get_nprocs(void);}
 
 #ifdef HAVE_SIGNAL
 /*
