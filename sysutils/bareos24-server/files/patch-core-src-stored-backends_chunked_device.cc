--- core/src/stored/backends/chunked_device.cc	2025-12-04 05:21:37.000000000 -0800
+++ core/src/stored/backends/chunked_device.cc	2026-02-02 17:56:28.052130000 -0800
@@ -103,7 +103,7 @@
 {
   char* buffer = (char*)malloc(current_chunk_->chunk_size);
 
-  Dmsg2(100, "New allocated buffer of %d bytes at %p\n",
+  Dmsg2(100, "New allocated buffer of %" PRIuz " bytes at %p\n",
         current_chunk_->chunk_size, buffer);
 
   return buffer;
@@ -112,7 +112,7 @@
 // Free a chunk buffer.
 void ChunkedDevice::FreeChunkbuffer(char* buffer)
 {
-  Dmsg2(100, "Freeing buffer of %d bytes at %p\n", current_chunk_->chunk_size,
+  Dmsg2(100, "Freeing buffer of %" PRIuz " bytes at %p\n", current_chunk_->chunk_size,
         buffer);
 
   free(buffer);
@@ -121,7 +121,7 @@
 // Free a chunk_io_request.
 void ChunkedDevice::FreeChunkIoRequest(chunk_io_request* request)
 {
-  Dmsg2(100, "Freeing chunk io request of %d bytes at %p\n",
+  Dmsg2(100, "Freeing chunk io request of %" PRIuz " bytes at %p\n",
         sizeof(chunk_io_request), request);
 
   if (request->release) { FreeChunkbuffer(request->buffer); }
@@ -358,7 +358,7 @@
   new_request->tries = 0;
   new_request->release = request->release;
 
-  Dmsg2(100, "Allocated chunk io request of %d bytes at %p\n",
+  Dmsg2(100, "Allocated chunk io request of %" PRIuz " bytes at %p\n",
         sizeof(chunk_io_request), new_request);
 
   /* Enqueue the item onto the ordered circular buffer.
@@ -433,7 +433,7 @@
                  "%d tries, setting device %s readonly\n"),
               new_request->chunk, new_request->volname, new_request->tries,
               print_name());
-        Emsg0(M_ERROR, 0, errmsg);
+        Emsg0(M_ERROR, 0, "%s", errmsg);
         readonly_ = true;
         goto bail_out;
       }
@@ -682,8 +682,8 @@
       wanted_offset = (offset_ % current_chunk_->chunk_size);
 
       bytes_left
-          = MIN((ssize_t)count, (current_chunk_->buflen - wanted_offset));
-      Dmsg2(200, "Reading complete %d byte read-request from chunk offset %d\n",
+          = MIN((ssize_t)count, ((ssize_t)current_chunk_->buflen - wanted_offset));
+      Dmsg2(200, "Reading complete %" PRIuz " byte read-request from chunk offset %" PRIuz "\n",
             bytes_left, wanted_offset);
 
       if (bytes_left < 0) {
@@ -709,13 +709,13 @@
         // See how much is left in this chunk.
         if (offset_ <= current_chunk_->end_offset) {
           wanted_offset = (offset_ % current_chunk_->chunk_size);
-          bytes_left = MIN((ssize_t)(count - offset),
-                           (ssize_t)(current_chunk_->buflen - wanted_offset));
+          bytes_left = MIN(((ssize_t)count - offset),
+                           ((ssize_t)current_chunk_->buflen - wanted_offset));
 
           if (bytes_left > 0) {
             Dmsg2(200,
-                  "Reading %d bytes of %d byte read-request from end of chunk "
-                  "at offset %d\n",
+                  "Reading %" PRIuz " bytes of %" PRIuz " byte read-request from end of chunk "
+                  "at offset %" PRIuz "\n",
                   bytes_left, count, wanted_offset);
 
             memcpy(((char*)buffer + offset),
@@ -743,12 +743,12 @@
         } else {
           /* Calculate how much data we can read from the just freshly read
            * chunk. */
-          bytes_left = MIN((ssize_t)(count - offset),
-                           (ssize_t)(current_chunk_->buflen));
+          bytes_left = MIN(((ssize_t)count - offset),
+                           (ssize_t)current_chunk_->buflen);
 
           if (bytes_left > 0) {
             Dmsg2(200,
-                  "Reading %d bytes of %d byte read-request from next chunk\n",
+                  "Reading %" PRIuz " bytes of %" PRIuz " byte read-request from next chunk\n",
                   bytes_left, count);
 
             memcpy(((char*)buffer + offset), current_chunk_->buffer,
@@ -805,7 +805,7 @@
         && current_chunk_->end_offset >= (boffset_t)((offset_ + count) - 1)) {
       wanted_offset = (offset_ % current_chunk_->chunk_size);
 
-      Dmsg2(200, "Writing complete %d byte write-request to chunk offset %d\n",
+      Dmsg2(200, "Writing complete %" PRIuz " byte write-request to chunk offset %" PRIuz "\n",
             count, wanted_offset);
 
       memcpy(current_chunk_->buffer + wanted_offset, buffer, count);
@@ -836,14 +836,14 @@
 
           if (bytes_left > 0) {
             Dmsg2(200,
-                  "Writing %d bytes of %d byte write-request to end of chunk "
-                  "at offset %d\n",
+                  "Writing %" PRIuz " bytes of %" PRIuz " byte write-request to end of chunk "
+                  "at offset %" PRIuz "\n",
                   bytes_left, count, wanted_offset);
 
             memcpy(current_chunk_->buffer + wanted_offset,
                    ((char*)buffer + offset), bytes_left);
             offset_ += bytes_left;
-            if ((wanted_offset + bytes_left) > current_chunk_->buflen) {
+            if ((wanted_offset + bytes_left) > (ssize_t)current_chunk_->buflen) {
               current_chunk_->buflen = wanted_offset + bytes_left;
             }
             current_chunk_->need_flushing = true;
@@ -860,13 +860,13 @@
 
         /* Calculate how much data we can fit into the just freshly created
          * chunk. */
-        bytes_left = MIN((ssize_t)(count - offset),
+        bytes_left = MIN(((ssize_t)count - offset),
                          (ssize_t)((current_chunk_->end_offset
                                     - current_chunk_->start_offset)
                                    + 1));
         if (bytes_left > 0) {
           Dmsg2(200,
-                "Writing %d bytes of %d byte write-request to next chunk\n",
+                "Writing %" PRIuz " bytes of %" PRIuz " byte write-request to next chunk\n",
                 bytes_left, count);
 
           memcpy(current_chunk_->buffer, ((char*)buffer + offset), bytes_left);
@@ -1089,14 +1089,14 @@
   /* compare expected to written volume size */
   size_t remote_volume_size = RemoteVolumeSize();
   Dmsg3(100,
-        "volume: %s, RemoteVolumeSize = %lld, VolCatInfo.VolCatBytes "
-        "= %lld\n",
+        "volume: %s, RemoteVolumeSize = %" PRIuz ", VolCatInfo.VolCatBytes "
+        "= %" PRIuz "\n",
         current_volname_, remote_volume_size, VolCatInfo.VolCatBytes);
 
   if (remote_volume_size < VolCatInfo.VolCatBytes) {
     Dmsg3(100,
-          "volume %s is pending, as 'remote volume size' = %lld < 'catalog "
-          "volume size' = %lld\n",
+          "volume %s is pending, as 'remote volume size' = %" PRIuz " < 'catalog "
+          "volume size' = %" PRIuz "\n",
           current_volname_, remote_volume_size, VolCatInfo.VolCatBytes);
     return false;
   }
@@ -1248,7 +1248,7 @@
   DeviceStatusInformation* dst = (DeviceStatusInformation*)data;
   PoolMem status(PM_MESSAGE);
 
-  status.bsprintf("   /%s/%04d - %ld (try=%d)\n", io_request->volname,
+  status.bsprintf("   /%s/%04d - %" PRIuz " (try=%d)\n", io_request->volname,
                   io_request->chunk, io_request->wbuflen, io_request->tries);
   dst->status_length = PmStrcat(dst->status, status.c_str());
 
