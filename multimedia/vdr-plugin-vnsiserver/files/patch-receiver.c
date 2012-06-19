--- a/receiver.c
+++ b/receiver.c
@@ -56,14 +56,23 @@ protected:
   virtual void Receive(uchar *Data, int Length);
 
 public:
-  cLiveReceiver(cLiveStreamer *Streamer, tChannelID ChannelID, int Priority, const int *Pids);
+  cLiveReceiver(cLiveStreamer *Streamer, const cChannel *Channel, int Priority, const int *Pids);
   virtual ~cLiveReceiver();
 };
 
-cLiveReceiver::cLiveReceiver(cLiveStreamer *Streamer, tChannelID ChannelID, int Priority, const int *Pids)
- : cReceiver(ChannelID, Priority, 0, Pids)
+#if (APIVERSNUM < 10725)
+cLiveReceiver::cLiveReceiver(cLiveStreamer *Streamer, const cChannel *Channel, int Priority, const int *Pids)
+ : cReceiver(Channel->GetChannelID(), Priority, 0, Pids)
  , m_Streamer(Streamer)
 {
+#else
+cLiveReceiver::cLiveReceiver(cLiveStreamer *Streamer, const cChannel *Channel, int Priority, const int *Pids)
+ : cReceiver(Channel, Priority)
+ , m_Streamer(Streamer)
+{
+  AddPid(0);
+  AddPids(Pids);
+#endif
   LOGCONSOLE("Starting live receiver");
 }
 
@@ -492,7 +501,7 @@ void cLivePatFilter::Process(u_short Pid
         }
       }
 
-      m_Streamer->m_Receiver  = new cLiveReceiver(m_Streamer, m_Channel->GetChannelID(), m_Streamer->m_Priority, m_Streamer->m_Pids);
+      m_Streamer->m_Receiver  = new cLiveReceiver(m_Streamer, m_Channel, m_Streamer->m_Priority, m_Streamer->m_Pids);
       m_Streamer->m_Device->AttachReceiver(m_Streamer->m_Receiver);
       isyslog("VNSI: Currently unknown new streams found, receiver and demuxers reinited\n");
     }
@@ -785,7 +794,7 @@ bool cLiveStreamer::StreamChannel(const 
       if (m_NumStreams > 0 && m_Socket)
       {
         dsyslog("VNSI: Creating new live Receiver");
-        m_Receiver  = new cLiveReceiver(this, m_Channel->GetChannelID(), m_Priority, m_Pids);
+        m_Receiver  = new cLiveReceiver(this, m_Channel, m_Priority, m_Pids);
         m_PatFilter = new cLivePatFilter(this, m_Channel);
         m_Device->AttachReceiver(m_Receiver);
         m_Device->AttachFilter(m_PatFilter);
