--- tosh_hci.cpp.orig	Wed Apr 23 17:16:42 2003
+++ tosh_hci.cpp	Fri Oct  3 17:35:48 2003
@@ -132,7 +132,7 @@
 
 unsigned 
 CToshHCIVar::hci_read(HCI_FUNCTION fn,unsigned ecx,unsigned edx) 
-                              throw (runtime_error)
+                              throw (std::runtime_error)
 {
     unsigned result;
     
@@ -144,7 +144,7 @@
                                                 
 void 
 CToshHCIVar::hci_write(HCI_FUNCTION fn,unsigned ecx,unsigned edx) 
-                                throw (runtime_error)
+                              throw (std::runtime_error)
 {
     unsigned result;
     
