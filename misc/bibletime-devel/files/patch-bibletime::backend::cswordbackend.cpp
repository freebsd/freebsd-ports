--- bibletime/backend/cswordbackend.cpp	Thu Jan 29 01:37:40 2004
+++ bibletime/backend/cswordbackend.cpp	Sat Aug 21 15:12:25 2004
@@ -66,7 +67,7 @@
 }
 
 CSwordBackend::CSwordBackend(const QString& path)
-	: sword::SWMgr((!path.isEmpty() ? path.local8Bit() : 0), false, new sword::EncodingFilterMgr( sword::ENC_UTF8 ))
+        : sword::SWMgr((!path.isEmpty() ? (const char*)path.local8Bit() : 0), false, new sword::EncodingFilterMgr( sword::ENC_UTF8 ))
 {
   qWarning("backend constructed with a path argument! %s", path.latin1());
 	m_displays.entry = 0;
