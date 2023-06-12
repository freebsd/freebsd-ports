--- if_ice_iflib.c.orig	2023-06-12 15:11:11 UTC
+++ if_ice_iflib.c
@@ -287,8 +287,12 @@ static struct if_shared_ctx ice_sctx = {
  *
  * device class used to setup the ice driver module kobject class.
  */
+#if __FreeBSD_version >= 1400058
+DRIVER_MODULE(ice, pci, ice_driver, ice_module_event_handler, 0);
+#else
 devclass_t ice_devclass;
 DRIVER_MODULE(ice, pci, ice_driver, ice_devclass, ice_module_event_handler, 0);
+#endif
 
 MODULE_VERSION(ice, 1);
 MODULE_DEPEND(ice, pci, 1, 1, 1);
