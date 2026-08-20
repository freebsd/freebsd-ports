--- src/rshim_pcie.c.orig	2026-08-16 14:25:19 UTC
+++ src/rshim_pcie.c
@@ -1585,7 +1585,11 @@ int rshim_pcie_init(void)
      * If DROP mode is set and this device got auto-bound during ID
      * registration, unbind it now.
      */
-    if (rshim_drop_mode > 0 && rshim_sys_pci_path) {
+    if (rshim_drop_mode > 0
+#ifdef __linux__
+        && rshim_sys_pci_path
+#endif /* __linux__ */
+    ) {
       char pci_addr[32];
       char cmd[RSHIM_CMD_MAX];
       snprintf(pci_addr, sizeof(pci_addr), "%04x:%02x:%02x.%x",
