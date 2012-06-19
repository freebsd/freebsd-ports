--- a/cmdcontrol.c
+++ b/cmdcontrol.c
@@ -950,15 +950,15 @@ bool cCmdControl::processRECORDINGS_GetL
       }
       else
       {
-        recordingStart = recording->start;
+        recordingStart = recording->Start();
       }
     }
     LOGCONSOLE("GRI: RC: recordingStart=%lu recordingDuration=%lu", recordingStart, recordingDuration);
 
     m_resp->add_U32(recordingStart);
     m_resp->add_U32(recordingDuration);
-    m_resp->add_U32(recording->priority);
-    m_resp->add_U32(recording->lifetime);
+    m_resp->add_U32(recording->Priority());
+    m_resp->add_U32(recording->Lifetime());
     m_resp->add_String(recording->Info()->ChannelName() ? m_toUTF8.Convert(recording->Info()->ChannelName()) : "");
     const char* fullname = recording->Name();
     const char* recname = strrchr(fullname, '~');
@@ -1019,15 +1019,15 @@ bool cCmdControl::processRECORDINGS_GetI
     }
     else
     {
-      recordingStart = recording->start;
+      recordingStart = recording->Start();
     }
   }
   LOGCONSOLE("GRI: RC: recordingStart=%lu recordingDuration=%lu", recordingStart, recordingDuration);
 
   m_resp->add_U32(recordingStart);
   m_resp->add_U32(recordingDuration);
-  m_resp->add_U32(recording->priority);
-  m_resp->add_U32(recording->lifetime);
+  m_resp->add_U32(recording->Priority());
+  m_resp->add_U32(recording->Lifetime());
   m_resp->add_String(recording->Info()->ChannelName() ? m_toUTF8.Convert(recording->Info()->ChannelName()) : "");
   if (!isempty(recording->Info()->Title()))
     m_resp->add_String(m_toUTF8.Convert(recording->Info()->Title()));
@@ -1232,7 +1232,7 @@ bool cCmdControl::processRECORDINGS_Move
           return true;
         }
       }
-      else if ((statret == 0) && (! (dstat.st_mode && S_IFDIR))) // Something exists but it's not a dir
+      else if ((statret == 0) && (! (dstat.st_mode & S_IFDIR))) // Something exists but it's not a dir
       {
         delete[] dateDirName;
         delete[] titleDirName;
