--- third_party/perfetto/src/trace_processor/importers/ftrace/v4l2_tracker.cc.orig	2025-09-06 10:01:20 UTC
+++ third_party/perfetto/src/trace_processor/importers/ftrace/v4l2_tracker.cc
@@ -59,7 +59,7 @@ void V4l2Tracker::ParseV4l2Event(uint64_t fld_id,
     case FtraceEvent::kV4l2QbufFieldNumber: {
       V4l2QbufFtraceEvent::Decoder pb_evt(bytes);
       BufferEvent evt;
-      evt.device_minor = pb_evt.minor();
+      evt.device_minor = pb_evt.gminor();
       evt.index = pb_evt.index();
       evt.type = pb_evt.type();
       evt.bytesused = pb_evt.bytesused();
@@ -100,7 +100,7 @@ void V4l2Tracker::ParseV4l2Event(uint64_t fld_id,
     case FtraceEvent::kV4l2DqbufFieldNumber: {
       V4l2DqbufFtraceEvent::Decoder pb_evt(bytes);
       BufferEvent evt;
-      evt.device_minor = pb_evt.minor();
+      evt.device_minor = pb_evt.gminor();
       evt.index = pb_evt.index();
       evt.type = pb_evt.type();
       evt.bytesused = pb_evt.bytesused();
@@ -146,7 +146,7 @@ void V4l2Tracker::ParseV4l2Event(uint64_t fld_id,
     case FtraceEvent::kVb2V4l2BufQueueFieldNumber: {
       Vb2V4l2BufQueueFtraceEvent::Decoder pb_evt(bytes);
       BufferEvent evt;
-      evt.device_minor = pb_evt.minor();
+      evt.device_minor = pb_evt.gminor();
       evt.index = std::nullopt;
       evt.type = std::nullopt;
       evt.bytesused = std::nullopt;
@@ -177,7 +177,7 @@ void V4l2Tracker::ParseV4l2Event(uint64_t fld_id,
     case FtraceEvent::kVb2V4l2BufDoneFieldNumber: {
       Vb2V4l2BufDoneFtraceEvent::Decoder pb_evt(bytes);
       BufferEvent evt;
-      evt.device_minor = pb_evt.minor();
+      evt.device_minor = pb_evt.gminor();
       evt.index = std::nullopt;
       evt.type = std::nullopt;
       evt.bytesused = std::nullopt;
@@ -208,7 +208,7 @@ void V4l2Tracker::ParseV4l2Event(uint64_t fld_id,
     case FtraceEvent::kVb2V4l2QbufFieldNumber: {
       Vb2V4l2QbufFtraceEvent::Decoder pb_evt(bytes);
       BufferEvent evt;
-      evt.device_minor = pb_evt.minor();
+      evt.device_minor = pb_evt.gminor();
       evt.index = std::nullopt;
       evt.type = std::nullopt;
       evt.bytesused = std::nullopt;
@@ -239,7 +239,7 @@ void V4l2Tracker::ParseV4l2Event(uint64_t fld_id,
     case FtraceEvent::kVb2V4l2DqbufFieldNumber: {
       Vb2V4l2DqbufFtraceEvent::Decoder pb_evt(bytes);
       BufferEvent evt;
-      evt.device_minor = pb_evt.minor();
+      evt.device_minor = pb_evt.gminor();
       evt.index = std::nullopt;
       evt.type = std::nullopt;
       evt.bytesused = std::nullopt;
