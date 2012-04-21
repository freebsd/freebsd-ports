--- status.h.orig
+++ status.h
@@ -20,8 +20,15 @@ private:
   cDevice *myFilterDevice;
   cGlobalInfosatepg *global;
 protected:
+#if VDRVERSNUM >= 10726
+  virtual void ChannelSwitch(const cDevice *Device, int ChannelNumber, bool LiveView);
+#else
   virtual void ChannelSwitch(const cDevice *Device, int ChannelNumber);
+#endif
 public:
+#if VDRVERSNUM >= 10726
+  bool m_LiveView;
+#endif
   cStatusInfosatepg(cGlobalInfosatepg *Global);
   virtual ~cStatusInfosatepg(void); 
  };
