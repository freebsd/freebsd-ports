--- Kernel/Operation_Vector.cpp.orig	2019-04-22 01:01:36 UTC
+++ Kernel/Operation_Vector.cpp
@@ -12,7 +12,9 @@
 #include "Message.h"
 #include "Cal_Quantity.h"
 
+#if defined(HAVE_PETSC)
 #include "petscvec.h"
+#endif
 
 /* TODO:
 
