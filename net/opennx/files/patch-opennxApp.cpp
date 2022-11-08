--- opennxApp.cpp.orig	2022-11-07 09:51:49 UTC
+++ opennxApp.cpp
@@ -759,7 +759,7 @@ void opennxApp::checkNxSmartCardSupport()
 #endif
     if (!fn.FileExists())
         return;
-    time_t last_mtime;
+    long last_mtime;
     long last_size;
     time_t mtime = fn.GetModificationTime().GetTicks();
     long size = fn.GetSize().ToULong();
@@ -767,8 +767,8 @@ void opennxApp::checkNxSmartCardSupport()
     wxConfigBase::Get()->Read(wxT("Config/NxSshSize"), &last_size, 0);
     wxConfigBase::Get()->Read(wxT("Config/NxSshSmartCardSupport"), &m_bNxSmartCardSupport, false);
 
-    if ((mtime != last_mtime) || (size != last_size)) {
-        wxConfigBase::Get()->Write(wxT("Config/NxSshStamp"), mtime);
+    if ((mtime != (time_t)last_mtime) || (size != last_size)) {
+        wxConfigBase::Get()->Write(wxT("Config/NxSshStamp"), (long)mtime);
         wxConfigBase::Get()->Write(wxT("Config/NxSshSize"), size);
         wxString nxsshcmd = fn.GetShortPath();
         nxsshcmd << wxT(" -I 0 -V");
