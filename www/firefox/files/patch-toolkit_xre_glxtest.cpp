--- toolkit/xre/glxtest/glxtest.cpp.orig	2023-05-28 22:08:21.663847000 +0200
+++ toolkit/xre/glxtest/glxtest.cpp	2023-05-28 22:09:33.647075000 +0200
@@ -195,9 +195,14 @@
 static void get_pci_status() {
   log("GLX_TEST: get_pci_status start\n");
 
+#if defined(__FreeBSD__)
+  if (access("/dev/pci", F_OK) != 0) {
+    record_warning("cannot access /dev/pci");
+#else
   if (access("/sys/bus/pci/", F_OK) != 0 &&
       access("/sys/bus/pci_express/", F_OK) != 0) {
     record_warning("cannot access /sys/bus/pci");
+#endif
     return;
   }
 
