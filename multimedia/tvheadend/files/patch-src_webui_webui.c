From 411f957733222e24df4ead9fb15332dcb2c116da Mon Sep 17 00:00:00 2001
From: Jongsung Kim <jongsung.kim@gmail.com>
Date: Tue, 29 May 2018 03:42:04 +0900
Subject: [PATCH 1/2] webui: fix http_serve_file() for FreeBSD

This patch fixes two major problems of FreeBSD port of tvheadend:

1. very high CPU usage while streaming a recored program
2. unable to stream the recorded program beyond 128MB.

Unlike Linux sendfile(), FreeBSD sendfile() requires an explicit
file offset, and return value must be checked to catch any error
occurred. (i.e., closed connection)

Patch tested with the latest FreeBSD port of tvheadend-4.2.6.
---
 src/webui/webui.c | 24 +++++++++++++++++-------
 1 file changed, 17 insertions(+), 7 deletions(-)

diff --git a/src/webui/webui.c b/src/webui/webui.c
index 12b965230..331d998e9 100644
--- src/webui/webui.c
+++ src/webui/webui.c
@@ -1570,7 +1570,7 @@ http_serve_file(http_connection_t *hc, const char *fname,
 #if defined(PLATFORM_LINUX)
   ssize_t r;
 #elif defined(PLATFORM_FREEBSD) || defined(PLATFORM_DARWIN)
-  off_t r;
+  off_t o, r;
 #endif
   
   if (fconv) {
@@ -1631,11 +1631,15 @@ http_serve_file(http_connection_t *hc, const char *fname,
   sprintf(range_buf, "bytes %jd-%jd/%jd",
     file_start, file_end, (intmax_t)st.st_size);
 
+#if defined(PLATFORM_LINUX)
   if(file_start > 0)
     if (lseek(fd, file_start, SEEK_SET) != file_start) {
       close(fd);
       return HTTP_STATUS_INTERNAL;
     }
+#elif defined(PLATFORM_FREEBSD) || defined(PLATFORM_DARWIN)
+  o = file_start;
+#endif
 
   if (preop) {
     ret = preop(hc, file_start, content_len, opaque);
@@ -1656,16 +1660,22 @@ http_serve_file(http_connection_t *hc, const char *fname,
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
-- 
2.19.1

