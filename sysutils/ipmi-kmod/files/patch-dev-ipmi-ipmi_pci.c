--- dev/ipmi/ipmi_pci.c.orig	Fri Feb 17 19:25:42 2006
+++ dev/ipmi/ipmi_pci.c	Fri Feb 17 19:52:45 2006
@@ -50,6 +50,10 @@
 #include <dev/ipmi/ipmivars.h>
 #endif
 
+#ifndef BUS_PROBE_DEFAULT
+#define BUS_PROBE_DEFAULT	0
+#endif
+
 static int ipmi_pci_probe(device_t dev);
 static int ipmi_pci_attach(device_t dev);
 static int ipmi_pci_detach(device_t dev);
