--- sys/v4l/v4lsrc_calls.c.orig	2008-03-03 17:29:52.000000000 -0500
+++ sys/v4l/v4lsrc_calls.c	2008-03-20 23:50:39.000000000 -0400
@@ -26,12 +26,14 @@
 
 #include <stdlib.h>
 #include <sys/types.h>
+#include <sys/uio.h>
 #include <sys/stat.h>
 #include <fcntl.h>
 #include <sys/ioctl.h>
 #include <sys/mman.h>
 #include <string.h>
 #include <errno.h>
+#include <unistd.h>
 #include "v4lsrc_calls.h"
 #include <sys/time.h>
 
@@ -87,6 +89,51 @@
     return FALSE;
   }
 
+  if (GST_V4LELEMENT (v4lsrc)->use_read) {
+    struct video_picture vp;
+    struct video_window vw;
+
+
+    if (ioctl (GST_V4LELEMENT (v4lsrc)->video_fd, VIDIOCGPICT, &vp) == -1) {
+      GST_ELEMENT_ERROR (v4lsrc, RESOURCE, WRITE, (NULL),
+	  ("Error getting current picture info for frame (%d): %s", num, g_strerror (errno)));
+      return FALSE;
+    }
+
+    vp.palette = v4lsrc->mmap.format;
+    if (ioctl (GST_V4LELEMENT (v4lsrc)->video_fd, VIDIOCSPICT, &vp) == -1) {
+      GST_ELEMENT_ERROR (v4lsrc, RESOURCE, WRITE, (NULL),
+	  ("Error setting picture info for frame (%d): %s", num, g_strerror (errno)));
+      return FALSE;
+    }
+
+    if (ioctl (GST_V4LELEMENT (v4lsrc)->video_fd, VIDIOCGWIN, &vw) == -1) {
+      GST_ELEMENT_ERROR (v4lsrc, RESOURCE, WRITE, (NULL),
+	  ("Error getting current window properties for frame (%d): %s", num, g_strerror (errno)));
+      return FALSE;
+    }
+
+    vw.width = v4lsrc->mmap.width;
+    vw.height = v4lsrc->mmap.height;
+    if (ioctl (GST_V4LELEMENT (v4lsrc)->video_fd, VIDIOCSWIN, &vw) == -1) {
+      vw.flags &= (0x3F00 - 1);
+      vw.flags |= 15 << 16;
+      if (ioctl (GST_V4LELEMENT (v4lsrc)->video_fd, VIDIOCSWIN, &vw) == -1) {
+          GST_ELEMENT_ERROR (v4lsrc, RESOURCE, WRITE, (NULL),
+              ("Error setting window properties for frame (%d): %s", num, g_strerror (errno)));
+          return FALSE;
+      }
+    }
+
+
+    if (read(GST_V4LELEMENT (v4lsrc)->video_fd, GST_V4LELEMENT (v4lsrc)->buffer + (1024 * 768 * 3 * num), v4lsrc->mmap.width * v4lsrc->mmap.height * 3/2) < 0) {
+      GST_ELEMENT_ERROR (v4lsrc, RESOURCE, WRITE, (NULL),
+          ("Error queueing a buffer (%d): %s", num, g_strerror (errno)));
+      return FALSE;
+    }
+    goto done;
+  }
+
   /* instruct the driver to prepare capture using buffer frame num */
   v4lsrc->mmap.frame = num;
   if (ioctl (GST_V4LELEMENT (v4lsrc)->video_fd,
@@ -95,6 +142,7 @@
         ("Error queueing a buffer (%d): %s", num, g_strerror (errno)));
     return FALSE;
   }
+done:
 
   v4lsrc->frame_queue_state[num] = QUEUE_STATE_QUEUED;
   v4lsrc->num_queued++;
@@ -117,6 +165,10 @@
     return FALSE;
   }
 
+  if (GST_V4LELEMENT (v4lsrc)->use_read) {
+    goto done;
+  }
+
   while (ioctl (GST_V4LELEMENT (v4lsrc)->video_fd, VIDIOCSYNC, &num) < 0) {
     /* if the sync() got interrupted, we can retry */
     if (errno != EINTR) {
@@ -126,6 +178,7 @@
     }
     GST_DEBUG_OBJECT (v4lsrc, "Sync got interrupted");
   }
+done:
   GST_LOG_OBJECT (v4lsrc, "VIOIOCSYNC on frame %d done", num);
 
   v4lsrc->frame_queue_state[num] = QUEUE_STATE_SYNCED;
@@ -168,13 +221,28 @@
   GST_V4L_CHECK_OPEN (GST_V4LELEMENT (v4lsrc));
   GST_V4L_CHECK_NOT_ACTIVE (GST_V4LELEMENT (v4lsrc));
 
+  GST_V4LELEMENT (v4lsrc)->use_read = FALSE;
+
   /* request the mmap buffer info:
    * total size of mmap buffer, number of frames, offsets of frames */
   if (ioctl (GST_V4LELEMENT (v4lsrc)->video_fd, VIDIOCGMBUF,
           &(v4lsrc->mbuf)) < 0) {
-    GST_ELEMENT_ERROR (v4lsrc, RESOURCE, READ, (NULL),
-        ("Error getting buffer information: %s", g_strerror (errno)));
-    return FALSE;
+    int i;
+
+    GST_V4LELEMENT (v4lsrc)->buffer = (guint8 *) g_malloc0 (sizeof (guint8) * 1024 * 768 * 3 * MIN_BUFFERS_QUEUED);
+    GST_V4LELEMENT (v4lsrc)->use_read = TRUE;
+
+    v4lsrc->frame_queue_state = (gint8 *) g_malloc (sizeof (gint8) * MIN_BUFFERS_QUEUED);
+
+    v4lsrc->mbuf.frames = MIN_BUFFERS_QUEUED;
+    for (i = 0; i < MIN_BUFFERS_QUEUED; i++) {
+      v4lsrc->mbuf.offsets[i] = (1024 * 768 * 3 * i);
+    }
+
+    /* lock for the frame_state */
+    v4lsrc->mutex_queue_state = g_mutex_new ();
+    v4lsrc->cond_queue_state = g_cond_new ();
+    goto done;
   }
 
   if (v4lsrc->mbuf.frames < MIN_BUFFERS_QUEUED) {
@@ -205,6 +273,7 @@
     GST_V4LELEMENT (v4lsrc)->buffer = NULL;
     return FALSE;
   }
+done:
 
   return TRUE;
 }
@@ -413,10 +482,14 @@
   v4lsrc->frame_queue_state = NULL;
 
   /* unmap the buffer */
-  if (munmap (GST_V4LELEMENT (v4lsrc)->buffer, v4lsrc->mbuf.size) == -1) {
-    GST_ELEMENT_ERROR (v4lsrc, RESOURCE, CLOSE, (NULL),
-        ("error munmap'ing capture buffer: %s", g_strerror (errno)));
-    return FALSE;
+  if (GST_V4LELEMENT (v4lsrc)->use_read) {
+    g_free (GST_V4LELEMENT (v4lsrc)->buffer);
+  } else {
+    if (munmap (GST_V4LELEMENT (v4lsrc)->buffer, v4lsrc->mbuf.size) == -1) {
+      GST_ELEMENT_ERROR (v4lsrc, RESOURCE, CLOSE, (NULL),
+          ("error munmap'ing capture buffer: %s", g_strerror (errno)));
+      return FALSE;
+    }
   }
   GST_V4LELEMENT (v4lsrc)->buffer = NULL;
 
@@ -446,6 +519,7 @@
   /* so, we need a buffer and some more stuff */
   int frame = 0;
   guint8 *buffer;
+  gboolean use_read = FALSE;
   struct video_mbuf vmbuf;
   struct video_mmap vmmap;
 
@@ -456,24 +530,72 @@
 
   /* let's start by requesting a buffer and mmap()'ing it */
   if (ioctl (GST_V4LELEMENT (v4lsrc)->video_fd, VIDIOCGMBUF, &vmbuf) < 0) {
-    GST_ELEMENT_ERROR (v4lsrc, RESOURCE, READ, (NULL),
-        ("Error getting buffer information: %s", g_strerror (errno)));
-    return FALSE;
-  }
-  /* Map the buffers */
-  buffer = mmap (NULL, vmbuf.size, PROT_READ | PROT_WRITE,
-      MAP_SHARED, GST_V4LELEMENT (v4lsrc)->video_fd, 0);
-  if (buffer == MAP_FAILED) {
-    GST_ELEMENT_ERROR (v4lsrc, RESOURCE, OPEN_READ_WRITE, (NULL),
-        ("Error mapping our try-out buffer: %s", g_strerror (errno)));
-    return FALSE;
-  }
+     buffer = (gint8 *) g_malloc0 (sizeof (gint8) * 1024 * 768 * 3);
+     use_read = TRUE;
+   } else {
+     /* Map the buffers */
+     buffer = mmap (0, vmbuf.size, PROT_READ | PROT_WRITE,
+         MAP_SHARED, GST_V4LELEMENT (v4lsrc)->video_fd, 0);
+     if (buffer == MAP_FAILED) {
+       GST_ELEMENT_ERROR (v4lsrc, RESOURCE, OPEN_READ_WRITE, (NULL),
+           ("Error mapping our try-out buffer: %s", g_strerror (errno)));
+       return FALSE;
+     }
+   }
 
   /* now that we have a buffer, let's try out our format */
   vmmap.width = width;
   vmmap.height = height;
   vmmap.format = palette;
   vmmap.frame = frame;
+  if (use_read) {
+    struct video_picture vp;
+    struct video_window vw;
+
+    if (ioctl (GST_V4LELEMENT (v4lsrc)->video_fd, VIDIOCGWIN, &vw) == -1) {
+      GST_ERROR_OBJECT (v4lsrc,
+           "Error getting current window properties: %s", g_strerror (errno));
+      g_free (buffer);
+      return FALSE;
+    }
+
+    vw.width = width;
+    vw.height = height;
+    if (ioctl (GST_V4LELEMENT (v4lsrc)->video_fd, VIDIOCSWIN, &vw) == -1) {
+      vw.flags &= (0x3F00 - 1);
+      vw.flags |= 15 << 16;
+      if (ioctl (GST_V4LELEMENT (v4lsrc)->video_fd, VIDIOCSWIN, &vw) == -1) {
+          GST_ERROR_OBJECT (v4lsrc,
+               "Error setting window properties: %s", g_strerror (errno));
+          g_free (buffer);
+          return FALSE;
+      }
+    }
+
+    if (ioctl (GST_V4LELEMENT (v4lsrc)->video_fd, VIDIOCGPICT, &vp) == -1) {
+      GST_ERROR_OBJECT (v4lsrc,
+           "Error getting current picture info: %s", g_strerror (errno));
+      g_free (buffer);
+      return FALSE;
+    }
+
+    vp.palette = palette;
+    if (ioctl (GST_V4LELEMENT (v4lsrc)->video_fd, VIDIOCSPICT, &vp) == -1) {
+      GST_ERROR_OBJECT (v4lsrc,
+           "Error setting picture info: %s", g_strerror (errno));
+      g_free (buffer);
+      return FALSE;
+    }
+
+
+    if (read (GST_V4LELEMENT (v4lsrc)->video_fd, buffer, width * height * 3/2) < 0) {
+      GST_ERROR_OBJECT (v4lsrc,
+           "Error reading into our try-out buffer: %s", g_strerror (errno));
+      g_free (buffer);
+      return FALSE;
+    }
+    goto done;
+  }
   if (ioctl (GST_V4LELEMENT (v4lsrc)->video_fd, VIDIOCMCAPTURE, &vmmap) < 0) {
     if (errno != EINVAL)        /* our format failed! */
       GST_ERROR_OBJECT (v4lsrc,
@@ -488,7 +610,11 @@
     return FALSE;
   }
 
-  munmap (buffer, vmbuf.size);
+done:
+  if (use_read)
+    g_free (buffer);
+  else
+    munmap (buffer, vmbuf.size);
 
   /* if we got here, it worked! woohoo, the format is supported! */
   return TRUE;
