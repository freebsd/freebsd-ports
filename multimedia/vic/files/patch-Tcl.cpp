--- Tcl.cpp.org	Mon May  7 15:55:17 2001
+++ Tcl.cpp	Mon May  7 15:55:34 2001
@@ -66,6 +66,7 @@
 {
 	instance_.tcl_ = tcl;
 	instance_.application_ = application;
+	Tcl_Init(tcl);
 }
 
 void Tcl::evalc(const char* s)
