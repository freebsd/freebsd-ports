--- a/channelscan.c
+++ b/channelscan.c
@@ -37,6 +37,11 @@
 eAutoScanStat
     cPluginChannelscan::AutoScanStat = AssNone;
 
+#if APIVERSNUM > 10723
+cStringList
+    cPluginChannelscan::Nodes;
+#endif
+
 cScanSetup  ScanSetup;
 bool OnlyChannelList=false;
 
@@ -117,11 +122,51 @@ cPluginChannelscan::Initialize(void)
     return true;
 }
 
+#if APIVERSNUM > 10723
+bool
+cPluginChannelscan::GetAdapterFrontend(int CardIndex, int &Adapter, int &Frontend) {
+  Adapter = Frontend = -1;
+  if (CardIndex < 0)
+     return false;
+  if (CardIndex < Nodes.Size() &&
+      2 == sscanf(Nodes[CardIndex], "%d %d", &Adapter, &Frontend)) {
+     return true;
+  }
+  return false;
+}
+#endif
+
 bool
 cPluginChannelscan::Start(void)
 {
     // Start any background activities the plugin shall perform.
+#if (APIVERSNUM < 10507)
     RegisterI18n(Phrases);
+#endif
+#if APIVERSNUM > 10723
+    cReadDir DvbDir(DEV_DVB_BASE);
+    if (DvbDir.Ok()) {
+       struct dirent *a;
+       while ((a = DvbDir.Next()) != NULL) {
+             if (strstr(a->d_name, DEV_DVB_ADAPTER) == a->d_name) {
+                int Adapter = strtol(a->d_name + strlen(DEV_DVB_ADAPTER), NULL, 10);
+                cReadDir AdapterDir(AddDirectory(DEV_DVB_BASE, a->d_name));
+                if (AdapterDir.Ok()) {
+                   struct dirent *f;
+                   while ((f = AdapterDir.Next()) != NULL) {
+                         if (strstr(f->d_name, DEV_DVB_FRONTEND) == f->d_name) {
+                            int Frontend = strtol(f->d_name + strlen(DEV_DVB_FRONTEND), NULL, 10);
+                            Nodes.Append(strdup(cString::sprintf("%2d %2d", Adapter, Frontend)));
+                            }
+                         }
+                   }
+                }
+             }
+       }
+
+    if (Nodes.Size() > 0)
+       Nodes.Sort();
+#endif
     return true;
 }
 
