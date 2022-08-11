--- httpfs2.c.orig	2012-09-03 14:58:02 UTC
+++ httpfs2.c
@@ -35,7 +35,7 @@
 #include <assert.h>
 #include <ctype.h>
 #include <sys/stat.h>
-#include <sys/dir.h>
+#include <dirent.h>
 #include <sys/types.h>
 #include <sys/time.h>
 #include <sys/socket.h>
@@ -188,7 +188,7 @@ static char * b64_encode(unsigned const char* ptr, lon
 
 static int httpfs_stat(fuse_ino_t ino, struct stat *stbuf)
 {
-    stbuf->st_ino = ino;
+    stbuf->st_ino = (uint32_t)ino;
     switch (ino) {
         case 1:
             stbuf->st_mode = S_IFDIR | 0755;
@@ -257,7 +257,7 @@ static void dirbuf_add(fuse_req_t req, struct dirbuf *
     b->size += fuse_add_direntry(req, NULL, 0, name, NULL, 0);
     b->p = (char *) realloc(b->p, b->size);
     memset(&stbuf, 0, sizeof(stbuf));
-    stbuf.st_ino = ino;
+    stbuf.st_ino = (uint32_t)ino;
     fuse_add_direntry(req, b->p + oldsize, b->size - oldsize, name, &stbuf,
             (off_t) b->size);
 }
@@ -667,11 +667,12 @@ static char * url_encode(char * path) {
 
 static int init_url(struct_url* url)
 {
-    memset(url, 0, sizeof(url));
+    memset(url, 0, sizeof(*url));
     url->sock_type = SOCK_CLOSED;
     url->timeout = TIMEOUT;
 #ifdef USE_SSL
-    url->cafile = CERT_STORE;
+    if ((url->cafile = getenv("CERT_STORE")) == NULL)
+	url->cafile = CERT_STORE;
 #endif
     return 0;
 }
@@ -911,7 +912,7 @@ int main(int argc, char *argv[])
         return 3;
     }
 #ifdef USE_SSL
-    else {
+    else if(main_url.ss != NULL) {
         print_ssl_info(main_url.ss);
     }
 #endif
