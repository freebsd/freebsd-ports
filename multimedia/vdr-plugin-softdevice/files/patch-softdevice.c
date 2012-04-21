--- softdevice.c.orig
+++ softdevice.c
@@ -1254,7 +1254,9 @@ bool cPluginSoftDevice::Service(const ch
 bool cPluginSoftDevice::Start(void)
 {
   // Start any background activities the plugin shall perform.
+#if (APIVERSNUM < 10507)
   RegisterI18n(Phrases);
+#endif
   return true;
 }
 
