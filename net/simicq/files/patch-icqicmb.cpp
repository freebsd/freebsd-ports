--- plugins/icq/icqicmb.cpp.orig	Mon Nov  3 01:18:29 2003
+++ plugins/icq/icqicmb.cpp	Mon Nov  3 02:27:56 2003
@@ -1375,7 +1375,7 @@
                         msgBuf.pack(cc[j].alias);
                     m_send.id.id_l = rand();
                     m_send.id.id_h = rand();
-                    sendType2(m_send.screen.c_str(), msgBuf, m_send.id, CAP_AIM_BUDDYLIST, false, false, false);
+                    sendType2(m_send.screen.c_str(), msgBuf, m_send.id, CAP_AIM_BUDDYLIST, false, 0);
                     return;
                 }
             case MessageUrl:{
@@ -1573,7 +1573,7 @@
             msgBuf.pack((unsigned long)(this->data.owner.Port));
             msgBuf.pack((unsigned short)8);
             msgBuf.pack((unsigned long)m_nMsgSequence);
-            sendType2(m_send.screen.c_str(), msgBuf, m_send.id, CAP_DIRECT, false, false, false);
+            sendType2(m_send.screen.c_str(), msgBuf, m_send.id, CAP_DIRECT, false, 0);
             return;
         }
         if (m_send.flags == PLUGIN_AR){
