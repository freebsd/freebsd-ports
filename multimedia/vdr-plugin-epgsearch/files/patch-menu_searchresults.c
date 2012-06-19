--- menu_searchresults.c.orig
+++ menu_searchresults.c
@@ -815,7 +815,11 @@ eOSState cMenuSearchResultsForRecs::Play
    {
       cRecording *recording = GetRecording(ri);
       if (recording) {
+#if APIVERSNUM < 10728
          cReplayControl::SetRecording(recording->FileName(), recording->Title());
+#else
+         cReplayControl::SetRecording(recording->FileName());
+#endif
          return osReplay;
       }
    }
