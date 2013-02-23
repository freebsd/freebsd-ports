--- httpfs2.c.orig	2013-02-19 15:45:06.000000000 +0100
+++ httpfs2.c	2013-02-19 15:48:43.000000000 +0100
@@ -35,7 +35,7 @@
 #include <assert.h>
 #include <ctype.h>
 #include <sys/stat.h>
-#include <sys/dir.h>
+#include <dirent.h>
 #include <sys/types.h>
 #include <sys/time.h>
 #include <sys/socket.h>
@@ -188,7 +188,7 @@
 
 static int httpfs_stat(fuse_ino_t ino, struct stat *stbuf)
 {
-    stbuf->st_ino = ino;
+    stbuf->st_ino = (uint32_t)ino;
     switch (ino) {
         case 1:
             stbuf->st_mode = S_IFDIR | 0755;
@@ -257,7 +257,7 @@
     b->size += fuse_add_direntry(req, NULL, 0, name, NULL, 0);
     b->p = (char *) realloc(b->p, b->size);
     memset(&stbuf, 0, sizeof(stbuf));
-    stbuf.st_ino = ino;
+    stbuf.st_ino = (uint32_t)ino;
     fuse_add_direntry(req, b->p + oldsize, b->size - oldsize, name, &stbuf,
             (off_t) b->size);
 }
@@ -667,7 +667,7 @@
 
 static int init_url(struct_url* url)
 {
-    memset(url, 0, sizeof(url));
+    memset(url, 0, sizeof(*url));
     url->sock_type = SOCK_CLOSED;
     url->timeout = TIMEOUT;
 #ifdef USE_SSL
