--- src/MPEG2Parser.cpp.orig	Thu Sep 30 17:15:58 2004
+++ src/MPEG2Parser.cpp	Thu Sep 30 17:22:57 2004
@@ -194,7 +194,7 @@
     off_t pes_loc;
 
     pes_loc = location;
-    if (!((void *) header = attach(sizeof(*header))))
+    if (!(header = (PES_packet_header_t *) attach(sizeof(*header))))
     {
         ATTACH_FAILED(_("header"), sizeof(*header));
         return;
@@ -225,7 +225,7 @@
             SKIP_BYTES(length);
             break;
 
-            if (!((void *) data = attach(length)))
+            if (!(data = (uint8_t *) attach(length)))
             {
                 ATTACH_FAILED(_("stream data"), length);
                 return;
@@ -242,7 +242,7 @@
             SKIP_BYTES(length);
             break;
 
-            if (!((void *) data = attach(length)))
+            if (!(data = (uint8_t *) attach(length)))
             {
                 ATTACH_FAILED(_("padding data"), length);
                 return;
@@ -297,7 +297,7 @@
                 break;
             }
 
-            if (!((void *) internals_area = attach(sizeof(internals))))
+            if (!(internals_area = (PES_packet_internals_t *) attach(sizeof(internals))))
             {
                 ATTACH_FAILED(_("flag data"), sizeof(internals));
                 return;
@@ -317,7 +317,7 @@
 
             if (CheckMaskValue(internals.bits[1], 0xC0, 0x80))
             {
-                if (!((void *) PTS_data = attach(5)))
+                if (!(PTS_data = (uint8_t *) attach(5)))
                 {
                     ATTACH_FAILED(_("PTS data"), 5);
                     return;
@@ -329,7 +329,7 @@
             }
             if (CheckMaskValue(internals.bits[1], 0xC0, 0xC0))
             {
-                if (!((void *) PTS_data = attach(5)))
+                if (!(PTS_data = (uint8_t *) attach(5)))
                 {
                     ATTACH_FAILED(_("PTS data"), 5);
                     return;
@@ -338,7 +338,7 @@
                 /*
                    if (debug) Report("has PTS");
                  */
-                if (!((void *) DTS_data = attach(5)))
+                if (!(DTS_data = (uint8_t *) attach(5)))
                 {
                     ATTACH_FAILED(_("DTS data"), 5);
                     return;
@@ -366,7 +366,7 @@
             if (CheckMaskValue(internals.bits[1], 0x4, 0x4))
             {
                 if (!
-                    ((void *) additional_copy_info =
+                    (additional_copy_info = (PES_packet_additional_copy_info_t *)
                      attach(sizeof(*additional_copy_info))))
                 {
                     ATTACH_FAILED(_("additional copy info"),
@@ -390,7 +390,7 @@
             {
                 PES_packet_extension_t *extension;
 
-                if (!((void *) extension = attach(sizeof(*extension))))
+                if (!(extension = (PES_packet_extension_t *) attach(sizeof(*extension))))
                 {
                     ATTACH_FAILED(_("extension data"), sizeof(*extension));
                     return;
@@ -398,7 +398,7 @@
 
                 if (PPE_PES_private_data_flag(extension->bits[0]))
                 {
-                    if (!((void *) PES_private_data = attach(16)))
+                    if (!(PES_private_data = (uint8_t *) attach(16)))
                     {
                         ATTACH_FAILED(_("PES private data"), 16);
                         return;
@@ -407,7 +407,7 @@
                 if (PPE_pack_header_field_flag(extension->bits[0]))
                 {
                     uint8_t *pack_field_length;
-                    if (!((void *) pack_field_length = attach(1)))
+                    if (!(pack_field_length = (uint8_t *) attach(1)))
                     {
                         ATTACH_FAILED(_("PES extension pack field length"),
                                       1);
@@ -480,7 +480,7 @@
             length -= (internals.PES_header_data_length + 3);
 
             data_loc = location;
-            if (!((void *) data = attach(length)))
+            if (!(data = (uint8_t *) attach(length)))
             {
                 ATTACH_FAILED(_("ES data"), length);
                 return;
@@ -519,7 +519,7 @@
     fprintf(stderr, "System @ %llu?\n", location);
 #endif
 
-    if (!((void *) header = attach(sizeof(*header))))
+    if (!(header = (system_header_t *) attach(sizeof(*header))))
     {
         ATTACH_FAILED(_("header"), sizeof(*header));
         return;
@@ -547,7 +547,7 @@
 
     while (forwardBitMatch(1, 0x1))
     {
-        if (!((void *) stream = attach(sizeof(*stream))))
+        if (!(stream = (stream_id_t *) attach(sizeof(*stream))))
         {
             ATTACH_FAILED(_("stream header"), sizeof(*stream));
             return;
@@ -574,7 +574,7 @@
 
     pack_start = location;
 
-    if (!((void *) header = attach(sizeof(*header))))
+    if (!(header = (pack_header_t *) attach(sizeof(*header))))
     {
         ATTACH_FAILED(_("header"), sizeof(*header));
         return;
@@ -749,7 +749,7 @@
 
     while (tosearch > 0)
     {
-        if (((void *) ptr = memchr(buf, 0x00, tosearch)))
+        if ((ptr = (uint8_t *) memchr(buf, 0x00, tosearch)))
         {
             if (verify(ptr, 4, code))
             {
