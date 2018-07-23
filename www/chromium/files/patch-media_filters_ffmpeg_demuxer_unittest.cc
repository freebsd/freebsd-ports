--- media/filters/ffmpeg_demuxer_unittest.cc.orig	2018-07-20 03:38:14.345859000 +0200
+++ media/filters/ffmpeg_demuxer_unittest.cc	2018-07-20 03:43:52.359278000 +0200
@@ -724,12 +724,9 @@
   ReadUntilEndOfStream(GetStream(DemuxerStream::AUDIO));
 }
 
-// TODO(dalecurtis): Test is disabled since FFmpeg does not currently guarantee
-// the order of demuxed packets in OGG containers.  Re-enable and fix key frame
-// expectations once we decide to either workaround it or attempt a fix
-// upstream.  See http://crbug.com/387996.
-TEST_F(FFmpegDemuxerTest,
-       DISABLED_Read_AudioNegativeStartTimeAndOggDiscard_Bear) {
+// Android has no Theora support, so these tests doesn't work.
+#if !defined(OS_ANDROID)
+TEST_F(FFmpegDemuxerTest, Read_AudioNegativeStartTimeAndOggDiscard_Bear) {
   // Many ogg files have negative starting timestamps, so ensure demuxing and
   // seeking work correctly with a negative start time.
   CreateDemuxer("bear.ogv");
@@ -739,8 +736,12 @@
   DemuxerStream* video = GetStream(DemuxerStream::VIDEO);
   DemuxerStream* audio = GetStream(DemuxerStream::AUDIO);
 
-  // Run the test twice with a seek in between.
-  for (int i = 0; i < 2; ++i) {
+  // Run the test once (should be twice..., see note) with a seek in between.
+  //
+  // TODO(dalecurtis): We only run the test once since FFmpeg does not currently
+  // guarantee the order of demuxed packets in OGG containers. See
+  // http://crbug.com/387996
+  for (int i = 0; i < 1; ++i) {
     audio->Read(
         NewReadCBWithCheckedDiscard(FROM_HERE, 40, 0, kInfiniteDuration, true));
     base::RunLoop().Run();
@@ -759,10 +760,10 @@
     video->Read(NewReadCB(FROM_HERE, 5751, 0, true));
     base::RunLoop().Run();
 
-    video->Read(NewReadCB(FROM_HERE, 846, 33367, true));
+    video->Read(NewReadCB(FROM_HERE, 846, 33367, false));
     base::RunLoop().Run();
 
-    video->Read(NewReadCB(FROM_HERE, 1255, 66733, true));
+    video->Read(NewReadCB(FROM_HERE, 1255, 66733, false));
     base::RunLoop().Run();
 
     // Seek back to the beginning and repeat the test.
@@ -775,9 +776,6 @@
 // Same test above, but using sync2.ogv which has video stream muxed before the
 // audio stream, so seeking based only on start time will fail since ffmpeg is
 // essentially just seeking based on file position.
-//
-// Android has no Theora support, so this test doesn't work.
-#if !defined(OS_ANDROID)
 TEST_F(FFmpegDemuxerTest, Read_AudioNegativeStartTimeAndOggDiscard_Sync) {
   // Many ogg files have negative starting timestamps, so ensure demuxing and
   // seeking work correctly with a negative start time.
