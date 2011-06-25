--- server/connectionVTP.c.orig
+++ server/connectionVTP.c
@@ -245,12 +245,14 @@ bool cLSTEHandler::Next(bool &Last)
 		if (m_Event != NULL) {
 			m_State = Title;
 #ifdef __FreeBSD__
-			return m_Client->Respond(-215, "E %u %d %d %X", m_Event->EventID(),
+			return m_Client->Respond(-215, "E %u " PRId64 " %d %X", m_Event->EventID(),
+			                         (int64_t)m_Event->StartTime(), m_Event->Duration(), 
+			                         m_Event->TableID());
 #else
 			return m_Client->Respond(-215, "E %u %ld %d %X", m_Event->EventID(),
-#endif
 			                         m_Event->StartTime(), m_Event->Duration(), 
 			                         m_Event->TableID());
+#endif
 		} else {
 			m_State = EndChannel;
 			return Next(Last);
@@ -292,7 +294,7 @@ bool cLSTEHandler::Next(bool &Last)
 #endif /* PARENTALRATING */
 		if (m_Event->Vps())
 #ifdef __FreeBSD__
-			return m_Client->Respond(-215, "V %d", m_Event->Vps());
+			return m_Client->Respond(-215, "V " PRId64, (int64_t)m_Event->Vps());
 #else
 			return m_Client->Respond(-215, "V %ld", m_Event->Vps());
 #endif
