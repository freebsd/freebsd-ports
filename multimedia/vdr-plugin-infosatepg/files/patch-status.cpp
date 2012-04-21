--- status.cpp.orig
+++ status.cpp
@@ -21,11 +21,18 @@ cStatusInfosatepg::~cStatusInfosatepg(vo
     if (myFilter) delete myFilter;
 }
 
+#if VDRVERSNUM >= 10726
+void cStatusInfosatepg::ChannelSwitch(const cDevice *Device, int ChannelNumber, bool LiveView)
+#else
 void cStatusInfosatepg::ChannelSwitch(const cDevice *Device, int ChannelNumber)
+#endif
 {
     if (!ChannelNumber) return;
     if (!Device) return; // just to be safe
 
+#if VDRVERSNUM >= 10726
+    m_LiveView = LiveView;
+#endif
     bool bAddFilter=false;
 
     // just add filter if we aren't locked
