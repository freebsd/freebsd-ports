--- SPQR/Source/spqr_factorize.cpp~	2008-09-22 06:10:37.000000000 +0900
+++ SPQR/Source/spqr_factorize.cpp	2009-02-16 15:47:49.000000000 +0900
@@ -31,6 +31,7 @@
 // =============================================================================
 
 #include "spqr.hpp"
+#include <string.h>
 
 #define FCHUNK 32        // FUTURE: make a parameter; Householder block size
 
