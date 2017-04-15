--- Modules/ThirdParty/VNL/src/vxl/v3p/netlib/linalg/lsqrBase.cxx.orig	2017-04-15 02:48:16 UTC
+++ Modules/ThirdParty/VNL/src/vxl/v3p/netlib/linalg/lsqrBase.cxx
@@ -562,7 +562,7 @@ Solve( unsigned int m, unsigned int n, const double * 
     // See if it is time to print something.
     //----------------------------------------------------------------
     bool prnt = false;
-    if (nout > 0)
+    if ( this->nout )
       {
       if (n     <=        40) prnt = true;
       if (this->itn   <=        10) prnt = true;
