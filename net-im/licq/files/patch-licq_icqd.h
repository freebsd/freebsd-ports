diff -ru licq-1.3.2/include/licq_icqd.h include/licq_icqd.h
--- licq-1.3.2/include/licq_icqd.h	Fri Sep  9 18:13:53 2005
+++ include/licq_icqd.h	Sun Sep  3 20:00:07 2006
@@ -6,6 +6,11 @@
 #ifndef ICQD_H
 #define ICQD_H
 
+#include <sys/select.h>
+#include <sys/time.h>
+#include <sys/types.h>
+#include <unistd.h>
+
 #include <vector>
 #include <list>
 #include <deque>
@@ -39,6 +44,28 @@
 class CReverseConnectToUserData;
 class CMSN;
 
+#define FOR_EACH_PROTO_PLUGIN_START(d)                             \
+    {                                                              \
+      ProtoPluginsList _pl_;                                       \
+      ProtoPluginsListIter _ppit;                                  \
+      d->ProtoPluginList(_pl_);                                    \
+      for (_ppit = _pl_.begin(); _ppit != _pl_.end(); _ppit++)     \
+      { 
+
+#define FOR_EACH_PROTO_PLUGIN_END                                  \
+      }                                                            \
+    }
+
+/* Forward declarations for friend functions */
+void *Ping_tep(void *p);
+void *UpdateUsers_tep(void *p);
+void *MonitorSockets_tep(void *p);
+void *ReverseConnectToUser_tep(void *p);
+void *ProcessRunningEvent_Client_tep(void *p);
+void *ProcessRunningEvent_Server_tep(void *p);
+void *Shutdown_tep(void *p);
+void *ConnectToServer_tep(void *s);
+
 const unsigned short IGNORE_MASSMSG    = 1;
 const unsigned short IGNORE_NEWUSERS   = 2;
 const unsigned short IGNORE_EMAILPAGER = 4;
@@ -577,9 +604,12 @@
   ICQEvent *PopPluginEvent();
   CSignal *PopProtoSignal();
 
-  // Server Side List functions
+  // ICQ options
   bool UseServerContactList()         { return m_bUseSS; }
-  void SetUseServerContactList(bool b)  { m_bUseSS = b; }
+  bool SendTypingNotification()       { return m_bSendTN; }
+
+  void SetUseServerContactList(bool b)   { m_bUseSS = b; }
+  void SetSendTypingNotification(bool b) { m_bSendTN = b; }
 
   // Misc functions
   bool ReconnectAfterUinClash()              { return m_bReconnectAfterUinClash; }
@@ -669,6 +699,7 @@
 
   // Misc
   bool m_bUseSS; // server side list
+  bool m_bSendTN; // Send typing notifications
   bool m_bReconnectAfterUinClash; // reconnect after uin has been used from another location?
   
   // Statistics
@@ -726,6 +757,7 @@
   ICQEvent *DoneExtendedServerEvent(const unsigned short, EventResult);
   ICQEvent *DoneExtendedEvent(ICQEvent *, EventResult);
   ICQEvent *DoneExtendedEvent(unsigned long tag, EventResult _eResult);
+  bool hasServerEvent(unsigned long);
   void ProcessDoneEvent(ICQEvent *);
   void PushExtendedEvent(ICQEvent *);
   void PushPluginSignal(CICQSignal *);
