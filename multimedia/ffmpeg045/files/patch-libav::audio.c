--- libav/audio.c.orig	Wed Feb  5 20:49:08 2003
+++ libav/audio.c	Wed Feb  5 20:50:36 2003
@@ -243,6 +243,14 @@
     if (av_new_packet(pkt, s->frame_size) < 0)
         return -EIO;
     for(;;) {
+        struct timeval tv;
+        fd_set fds;
+        tv.tv_sec = 0;
+        tv.tv_usec = 30 * 1000; /* 30 msecs -- a bit shorter than 1 frame at 30fps */
+        FD_ZERO(&fds);
+        FD_SET(s->fd, &fds);    /* This will block until data is available or we get a timeout */
+        (void) select(s->fd + 1, &fds, 0, 0, &tv);
+
         ret = read(s->fd, pkt->data, pkt->size);
         if (ret > 0)
             break;
