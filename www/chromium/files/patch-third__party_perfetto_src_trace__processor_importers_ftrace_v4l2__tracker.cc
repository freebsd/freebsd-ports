--- third_party/perfetto/src/trace_processor/importers/ftrace/v4l2_tracker.cc.orig	2026-01-14 08:33:23 UTC
+++ third_party/perfetto/src/trace_processor/importers/ftrace/v4l2_tracker.cc
@@ -65,7 +65,7 @@ void V4l2Tracker::ParseV4l2Event(uint64_t fld_id,
     case FtraceEvent::kV4l2QbufFieldNumber: {
       V4l2QbufFtraceEvent::Decoder pb_evt(bytes);
       BufferEvent evt;
-      evt.device_minor = pb_evt.minor();
+      evt.device_minor = pb_evt.gminor();
       evt.index = pb_evt.index();
       evt.type = pb_evt.type();
       evt.bytesused = pb_evt.bytesused();
@@ -106,7 +106,7 @@ void V4l2Tracker::ParseV4l2Event(uint64_t fld_id,
     case FtraceEvent::kV4l2DqbufFieldNumber: {
       V4l2DqbufFtraceEvent::Decoder pb_evt(bytes);
       BufferEvent evt;
-      evt.device_minor = pb_evt.minor();
+      evt.device_minor = pb_evt.gminor();
       evt.index = pb_evt.index();
       evt.type = pb_evt.type();
       evt.bytesused = pb_evt.bytesused();
@@ -152,7 +152,7 @@ void V4l2Tracker::ParseV4l2Event(uint64_t fld_id,
     case FtraceEvent::kVb2V4l2BufQueueFieldNumber: {
       Vb2V4l2BufQueueFtraceEvent::Decoder pb_evt(bytes);
       BufferEvent evt;
-      evt.device_minor = pb_evt.minor();
+      evt.device_minor = pb_evt.gminor();
       evt.index = std::nullopt;
       evt.type = std::nullopt;
       evt.bytesused = std::nullopt;
@@ -183,7 +183,7 @@ void V4l2Tracker::ParseV4l2Event(uint64_t fld_id,
     case FtraceEvent::kVb2V4l2BufDoneFieldNumber: {
       Vb2V4l2BufDoneFtraceEvent::Decoder pb_evt(bytes);
       BufferEvent evt;
-      evt.device_minor = pb_evt.minor();
+      evt.device_minor = pb_evt.gminor();
       evt.index = std::nullopt;
       evt.type = std::nullopt;
       evt.bytesused = std::nullopt;
@@ -214,7 +214,7 @@ void V4l2Tracker::ParseV4l2Event(uint64_t fld_id,
     case FtraceEvent::kVb2V4l2QbufFieldNumber: {
       Vb2V4l2QbufFtraceEvent::Decoder pb_evt(bytes);
       BufferEvent evt;
-      evt.device_minor = pb_evt.minor();
+      evt.device_minor = pb_evt.gminor();
       evt.index = std::nullopt;
       evt.type = std::nullopt;
       evt.bytesused = std::nullopt;
@@ -245,7 +245,7 @@ void V4l2Tracker::ParseV4l2Event(uint64_t fld_id,
     case FtraceEvent::kVb2V4l2DqbufFieldNumber: {
       Vb2V4l2DqbufFtraceEvent::Decoder pb_evt(bytes);
       BufferEvent evt;
-      evt.device_minor = pb_evt.minor();
+      evt.device_minor = pb_evt.gminor();
       evt.index = std::nullopt;
       evt.type = std::nullopt;
       evt.bytesused = std::nullopt;
