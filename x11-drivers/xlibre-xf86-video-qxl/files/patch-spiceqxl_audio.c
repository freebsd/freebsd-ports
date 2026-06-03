--- src/spiceqxl_audio.c.bak	2017-09-12 12:00:11 UTC
+++ src/spiceqxl_audio.c
@@ -410,7 +410,10 @@
         strcat(fname, "/");
         strcat(fname, e->name);
 
-        f->fd = open(fname, O_RDONLY | O_RSYNC | O_NONBLOCK);
+//        f->fd = open(fname, O_RDONLY | O_RSYNC | O_NONBLOCK);
+        // POSIX specifies three different flavors for synchronous I/O: O_SYNC, O_DSYNC, and O_RSYNC.
+        // In BSD, these are all equivalent.
+        f->fd = open(fname, O_RDONLY | O_SYNC | O_NONBLOCK);
         free(fname);
         if (f->fd < 0) {
             ErrorF("playback: open FIFO '%s' failed: %s\n", e->name, strerror(errno));
