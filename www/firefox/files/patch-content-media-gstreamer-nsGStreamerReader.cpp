commit f0a73aa
Author: Paul Adenot <paul@paul.cx>
Date:   Thu Jun 21 20:44:39 2012 -0400

    Bug 761419 - Build failure in content/media/gstreamer/nsGStreamerReader.cpp when using clang r=kinetik
---
 content/media/gstreamer/nsGStreamerReader.cpp | 2 +-
 1 file changed, 1 insertion(+), 1 deletion(-)

diff --git content/media/gstreamer/nsGStreamerReader.cpp content/media/gstreamer/nsGStreamerReader.cpp
index 06a09b5..c48f92e 100644
--- content/media/gstreamer/nsGStreamerReader.cpp
+++ content/media/gstreamer/nsGStreamerReader.cpp
@@ -191,7 +191,7 @@ nsresult nsGStreamerReader::ReadMetadata(nsVideoInfo* aInfo)
    * stream but that are otherwise decodeable.
    */
   guint flags[3] = {GST_PLAY_FLAG_VIDEO|GST_PLAY_FLAG_AUDIO,
-    ~GST_PLAY_FLAG_AUDIO, ~GST_PLAY_FLAG_VIDEO};
+    static_cast<guint>(~GST_PLAY_FLAG_AUDIO), static_cast<guint>(~GST_PLAY_FLAG_VIDEO)};
   guint default_flags, current_flags;
   g_object_get(mPlayBin, "flags", &default_flags, NULL);
 
commit 667daed
Author: Stephen Moehle <stephen.moehle@gmail.com>
Date:   Tue Jun 5 11:32:36 2012 +1200

    Bug 760899 - Fix debug builds with gstreamer enabled - r=kinetik
    
    --HG--
    extra : rebase_source : 22598bc470d35d94991ea9f1b14df11ba19a461a
---
 content/media/gstreamer/nsGStreamerReader.cpp | 10 +++++-----
 1 file changed, 5 insertions(+), 5 deletions(-)

diff --git content/media/gstreamer/nsGStreamerReader.cpp content/media/gstreamer/nsGStreamerReader.cpp
index 6a50e09..164fb2e 100644
--- content/media/gstreamer/nsGStreamerReader.cpp
+++ content/media/gstreamer/nsGStreamerReader.cpp
@@ -278,7 +278,7 @@ nsresult nsGStreamerReader::ReadMetadata(nsVideoInfo* aInfo)
   if (gst_element_query_duration(GST_ELEMENT(mPlayBin),
       &format, &duration) && format == GST_FORMAT_TIME) {
     ReentrantMonitorAutoEnter mon(mDecoder->GetReentrantMonitor());
-    LOG(PR_LOG_DEBUG, ("returning duration %"GST_TIME_FORMAT,
+    LOG(PR_LOG_DEBUG, ("returning duration %" GST_TIME_FORMAT,
           GST_TIME_ARGS (duration)));
     duration = GST_TIME_AS_USECONDS (duration);
     mDecoder->GetStateMachine()->SetDuration(duration);
@@ -422,8 +422,8 @@ bool nsGStreamerReader::DecodeVideoFrame(bool &aKeyFrameSkip,
       nextTimestamp += gst_util_uint64_scale(GST_USECOND, fpsNum, fpsDen);
 
     if (timestamp < aTimeThreshold) {
-      LOG(PR_LOG_DEBUG, ("skipping frame %"GST_TIME_FORMAT
-            " threshold %"GST_TIME_FORMAT,
+      LOG(PR_LOG_DEBUG, ("skipping frame %" GST_TIME_FORMAT
+            " threshold %" GST_TIME_FORMAT,
             GST_TIME_ARGS(timestamp), GST_TIME_ARGS(aTimeThreshold)));
       gst_buffer_unref(buffer);
       buffer = NULL;
@@ -489,7 +489,7 @@ nsresult nsGStreamerReader::Seek(PRInt64 aTarget,
   NS_ASSERTION(mDecoder->OnDecodeThread(), "Should be on decode thread.");
 
   gint64 seekPos = aTarget * GST_USECOND;
-  LOG(PR_LOG_DEBUG, ("%p About to seek to %"GST_TIME_FORMAT,
+  LOG(PR_LOG_DEBUG, ("%p About to seek to %" GST_TIME_FORMAT,
         mDecoder, GST_TIME_ARGS(seekPos)));
 
   if (!gst_element_seek_simple(mPlayBin, GST_FORMAT_TIME,
@@ -592,7 +592,7 @@ PRInt64 nsGStreamerReader::QueryDuration()
   if (gst_element_query_duration(GST_ELEMENT(mPlayBin),
       &format, &duration)) {
     if (format == GST_FORMAT_TIME) {
-      LOG(PR_LOG_DEBUG, ("pipeline duration %"GST_TIME_FORMAT,
+      LOG(PR_LOG_DEBUG, ("pipeline duration %" GST_TIME_FORMAT,
             GST_TIME_ARGS (duration)));
       duration = GST_TIME_AS_USECONDS (duration);
     }
