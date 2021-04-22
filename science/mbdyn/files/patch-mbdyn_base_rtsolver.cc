--- mbdyn/base/rtsolver.cc.orig	2021-04-22 19:28:55 UTC
+++ mbdyn/base/rtsolver.cc
@@ -38,6 +38,8 @@
 #include "rtaisolver.h"
 #include "rtposixsolver.h"
 #include "ac/sys_sysinfo.h"
+
+extern "C" {int get_nprocs(void);}
  
 /* RTSolverBase - begin */
 
