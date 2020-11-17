--- src/flb_scheduler.c.orig	2020-11-16 20:32:16 UTC
+++ src/flb_scheduler.c
@@ -44,7 +44,7 @@ static inline int consume_byte(flb_pipef
 
     /* We need to consume the byte */
     ret = flb_pipe_r(fd, &val, sizeof(val));
-#ifdef __APPLE__
+#if defined(__APPLE__) || __FreeBSD__ >= 12
     if (ret < 0) {
 #else
     if (ret <= 0) {
