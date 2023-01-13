--- toolkit/xre/glxtest.cpp.orig
+++ toolkit/xre/glxtest.cpp
@@ -270,9 +270,14 @@
 #define PCI_BASE_CLASS_DISPLAY 0x03
 
 static void get_pci_status() {
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
 
