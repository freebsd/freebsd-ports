--- ./src/widgets/MediaVideoWidget.vala.orig	2015-02-11 01:17:34.000000000 +0100
+++ ./src/widgets/MediaVideoWidget.vala	2015-02-11 01:18:59.000000000 +0100
@@ -34,7 +34,7 @@
     drawing_area.realize.connect (realize_cb);
 #if VIDEO
     this.src  = Gst.ElementFactory.make ("playbin", "video");
-    this.sink = Gst.ElementFactory.make ("vaapisink", "sink");
+    this.sink = Gst.ElementFactory.make ("xvimagesink", "sink");
     this.src.set ("video-sink", sink, null);
     var bus = src.get_bus ();
     bus.set_sync_handler (bus_sync_handler);
