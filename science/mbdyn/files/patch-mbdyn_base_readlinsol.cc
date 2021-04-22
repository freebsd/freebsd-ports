--- mbdyn/base/readlinsol.cc.orig	2021-04-22 19:28:15 UTC
+++ mbdyn/base/readlinsol.cc
@@ -35,6 +35,8 @@
 #include "dataman.h"
 #include "readlinsol.h"
 
+extern "C" {int get_nprocs(void);}
+
 void
 ReadLinSol(LinSol& cs, HighParser &HP, bool bAllowEmpty)
 {
