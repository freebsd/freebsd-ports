--- Tcl.cpp	Thu Sep  9 08:21:53 1999
+++ Tcl.cpp	Thu Sep 23 18:59:59 2004
@@ -66,6 +66,7 @@
 {
 	instance_.tcl_ = tcl;
 	instance_.application_ = application;
+	Tcl_Init(tcl);
 }
 
 void Tcl::evalc(const char* s)
@@ -214,7 +215,7 @@
 	}
 }
 
-int TclObject::callback(ClientData cd, Tcl_Interp*, int ac, char** av)
+int TclObject::callback(ClientData cd, Tcl_Interp*, int ac, const char** av)
 {
 	TclObject* tc = (TclObject*)cd;
 	return (tc->command(ac, (const char*const*)av));
