--- Tcl.cc--	Mon Jun 10 16:59:27 2002
+++ Tcl.cc	Mon Jun 10 16:59:31 2002
@@ -66,6 +66,7 @@
 {
 	instance_.tcl_ = tcl;
 	instance_.application_ = application;
+	Tcl_Init(tcl);
 }
 
 void Tcl::evalf(const char* fmt, ...)
