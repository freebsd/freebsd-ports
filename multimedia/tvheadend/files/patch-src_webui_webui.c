From d19ee83aba20e5a64a6cef6dd528191a71f9aa31 Mon Sep 17 00:00:00 2001
From: Jongsung Kim <jongsung.kim@gmail.com>
Date: Tue, 29 May 2018 03:42:04 +0900
Subject: [PATCH] webui: fix http_serve_file() for FreeBSD

This patch fixes two major problems of FreeBSD port of tvheadend:

1. very high CPU usage while streaming a recored program
2. unable to stream the recorded program beyond 128MB.

Unlike Linux sendfile(), FreeBSD sendfile() requires an explicit
file offset, and return value must be checked to catch any error
occurred. (i.e., closed connection)

Patch tested with the latest FreeBSD port of tvheadend-4.2.6.

--- src/webui/webui.c.orig	2018-03-26 10:19:37.000000000 +0200
+++ src/webui/webui.c	2018-06-13 14:47:58.627430000 +0200
@@ -1570,7 +1570,7 @@
 #if defined(PLATFORM_LINUX)
   ssize_t r;
 #elif defined(PLATFORM_FREEBSD) || defined(PLATFORM_DARWIN)
-  off_t r;
+  off_t o, r;
 #endif
   
   if (fconv) {
@@ -1631,6 +1631,7 @@
   sprintf(range_buf, "bytes %jd-%jd/%jd",
     file_start, file_end, (intmax_t)st.st_size);
 
+#if defined(PLATFORM_LINUX)
   if(file_start > 0)
     if (lseek(fd, file_start, SEEK_SET) != file_start) {
       close(fd);
@@ -1644,6 +1645,9 @@
       return ret;
     }
   }
+#elif defined(PLATFORM_FREEBSD) || defined(PLATFORM_DARWIN)
+  o = file_start;
+#endif
 
   http_send_begin(hc);
   http_send_header(hc, range ? HTTP_STATUS_PARTIAL_CONTENT : HTTP_STATUS_OK,
@@ -1656,16 +1660,22 @@
       chunk = MIN(1024 * ((stats ? 128 : 1024) * 1024), content_len);
 #if defined(PLATFORM_LINUX)
       r = sendfile(hc->hc_fd, fd, NULL, chunk);
+      if (r < 0) {
+        ret = -1;
+        break;
+      }
 #elif defined(PLATFORM_FREEBSD)
-      sendfile(fd, hc->hc_fd, 0, chunk, NULL, &r, 0);
+      ret = sendfile(fd, hc->hc_fd, o, chunk, NULL, &r, 0);
+      if (ret < 0)
+        break;
+      o += r;
 #elif defined(PLATFORM_DARWIN)
       r = chunk;
-      sendfile(fd, hc->hc_fd, 0, &r, NULL, 0);
-#endif
-      if(r < 0) {
-        ret = -1;
+      ret = sendfile(fd, hc->hc_fd, o, &r, NULL, 0);
+      if (ret < 0)
         break;
-      }
+      o += r;
+#endif
       content_len -= r;
       if (stats)
         stats(hc, r, opaque);
