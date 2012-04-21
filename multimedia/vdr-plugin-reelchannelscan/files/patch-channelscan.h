--- a/channelscan.h
+++ b/channelscan.h
@@ -68,6 +68,9 @@ class cPluginChannelscan:public cPlugin
 {
   private:
     // Add any member variables or functions you may need here.
+#if APIVERSNUM > 10723
+    static cStringList Nodes;
+#endif
   public:
     cPluginChannelscan();
     virtual ~ cPluginChannelscan();
@@ -102,6 +105,9 @@ class cPluginChannelscan:public cPlugin
     static eAutoScanStat AutoScanStat;
     ChannelScanData channelData_;
     bool channelDataPresent_;
+#if APIVERSNUM > 10723
+    static bool GetAdapterFrontend(int CardIndex, int &Adapter, int &Frontend);
+#endif
 };
 
 // --- cSetupMenu ------------------------------------------------------
