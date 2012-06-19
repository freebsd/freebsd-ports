--- a/tasks.cpp
+++ b/tasks.cpp
@@ -60,9 +60,15 @@ void PlayRecordingTask::Action()
 
 	const char *current = NowReplaying();
 	if (!current || (0 != strcmp(current, recording->FileName()))) {
+#if APIVERSNUM < 10728
 		cReplayControl::SetRecording( 0, 0 );
 		cControl::Shutdown();
 		cReplayControl::SetRecording( recording->FileName(), recording->Title() );
+#else
+		cReplayControl::SetRecording( 0 );
+		cControl::Shutdown();
+		cReplayControl::SetRecording( recording->FileName() );
+#endif
 		cControl::Launch( new cReplayControl );
 		cControl::Attach();
 	}
@@ -122,7 +128,11 @@ void StopRecordingTask::Action()
 		return;
 	}
 
+#if APIVERSNUM < 10728
 	cReplayControl::SetRecording( 0, 0 );
+#else
+	cReplayControl::SetRecording( 0 );
+#endif
 	cControl::Shutdown();
 }
 
