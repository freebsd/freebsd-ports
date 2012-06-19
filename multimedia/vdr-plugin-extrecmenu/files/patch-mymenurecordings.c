--- a/mymenurecordings.c
+++ b/mymenurecordings.c
@@ -1031,7 +1031,11 @@ eOSState myMenuRecordings::Play()
           buffer=NULL;
         }
         golastreplayed=true;
+#if APIVERSNUM < 10728
         myReplayControl::SetRecording(recording->FileName(),recording->Title());
+#else
+        myReplayControl::SetRecording(recording->FileName());
+#endif
         cControl::Shutdown();
         isyslog("[extrecmenu] starting replay of recording");
         cControl::Launch(new myReplayControl());
