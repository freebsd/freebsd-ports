--- src/user.cpp.orig	Mon Jun 16 19:09:46 2003
+++ src/user.cpp	Fri Jul 30 20:10:16 2004
@@ -3184,7 +3184,7 @@
   m_fConf.ReadBool("HideIP", m_bHideIp, false);
   m_fConf.ReadNum("RCG", m_nRandomChatGroup, ICQ_RANDOMxCHATxGROUP_NONE);
   m_fConf.ReadStr("AutoResponse", szTemp, "");
-  m_fConf.ReadNum("SSTime", (unsigned long)m_nSSTime, 0L);
+  m_fConf.ReadNum("SSTime", (unsigned long&)m_nSSTime, 0L);
   m_fConf.ReadNum("SSCount", m_nSSCount, 0);
   SetAutoResponse(szTemp);
 
