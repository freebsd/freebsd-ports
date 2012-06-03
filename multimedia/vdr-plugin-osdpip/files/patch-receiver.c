--- receiver.c.orig
+++ receiver.c
@@ -37,11 +37,16 @@ cOsdPipReceiver::cOsdPipReceiver(const c
     cRingBufferFrame *ESBuffer):
 #if (APIVERSNUM < 10500)
     cReceiver(Channel->Ca(), 0, Channel->Vpid()),
-#else
+#elif (APIVERSNUM < 10725)
     cReceiver(Channel->GetChannelID(), 0, Channel->Vpid()),
+#else
+    cReceiver(Channel, 0),
 #endif
     cThread("osdpip_receiver")
 {
+#if (APIVERSNUM >= 10725)
+    AddPid(Channel->Vpid());
+#endif
     m_TSBuffer = new cRingBufferLinear(MEGABYTE(3), TS_SIZE * 2, true);
     m_TSBuffer->SetTimeouts(0, 100);
     m_ESBuffer = ESBuffer;
