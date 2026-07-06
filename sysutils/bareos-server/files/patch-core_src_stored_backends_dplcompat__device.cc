--- core/src/stored/backends/dplcompat_device.cc.orig	2026-06-24 10:18:02 UTC
+++ core/src/stored/backends/dplcompat_device.cc
@@ -342,7 +342,7 @@ bool DropletCompatibleDevice::ReadRemoteChunk(chunk_io
     return false;
   } else if (obj_stat->size > request->wbuflen) {
     Mmsg3(errmsg,
-          T_("Failed to read %s (%ld) to big to fit in chunksize of %" PRIu32
+          T_("Failed to read %s (%zu) to big to fit in chunksize of %" PRIu32
              " bytes\n"),
           obj_name.data(), obj_stat->size, request->wbuflen);
     Dmsg1(debug_info, "%s", errmsg);
