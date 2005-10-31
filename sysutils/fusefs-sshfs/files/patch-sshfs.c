--- sshfs.c.orig	Fri Oct 28 08:15:35 2005
+++ sshfs.c	Mon Oct 31 02:59:33 2005
@@ -14,7 +14,11 @@
 #include <unistd.h>
 #include <fcntl.h>
 #include <string.h>
-#include <stdint.h>
+#ifdef HAVE_STDINT_H
+	#include <stdint.h>
+#elif defined(HAVE_INTTYPES_H)
+	#include <inttypes.h>
+#endif
 #include <errno.h>
 #include <semaphore.h>
 #include <pthread.h>
@@ -24,6 +28,13 @@
 #include <sys/wait.h>
 #include <netinet/in.h>
 #include <glib.h>
+#ifdef __FreeBSD__
+	#include <sys/socket.h>
+	#include <sys/param.h>
+	#if (__FreeBSD_version < 600034)
+		#define	EPROTONOSUPPORT	43
+	#endif
+#endif
 
 #include "cache.h"
 #include "opts.h"
@@ -1070,7 +1081,11 @@
         err = req->error;
         goto out;
     }
+#ifdef EPROTO
     err = -EPROTO;
+#else
+    err = -EPROTONOSUPPORT;
+#endif
     if (req->reply_type != expect_type && req->reply_type != SSH_FXP_STATUS) {
         fprintf(stderr, "protocol error\n");
         goto out;
@@ -1085,21 +1100,35 @@
             if (expect_type == SSH_FXP_STATUS)
                 err = 0;
             else
+#ifdef EPROTO
                 err = -EPROTO;
+#else
+                err = -EPROTONOSUPPORT;
+#endif
             break;
 
         case SSH_FX_EOF:
             if (type == SSH_FXP_READ || type == SSH_FXP_READDIR)
                 err = MY_EOF;
             else
+#ifdef EPROTO
                 err = -EPROTO;
+#else
+                err = -EPROTONOSUPPORT;
+#endif
             break;
 
         case SSH_FX_NO_SUCH_FILE:      err = -ENOENT; break;
         case SSH_FX_PERMISSION_DENIED: err = -EACCES; break;
         case SSH_FX_FAILURE:           err = -EPERM;  break;
         case SSH_FX_BAD_MESSAGE:
-        default:                       err = -EPROTO; break;
+        default:
+#ifdef EPROTO
+                err = -EPROTO;
+#else
+                err = -EPROTONOSUPPORT;
+#endif
+                break;
         }
     } else {
         buf_init(outbuf, req->reply.size - req->reply.len);
@@ -1142,7 +1171,11 @@
     err = sftp_request(SSH_FXP_LSTAT, &buf, SSH_FXP_ATTRS, &outbuf);
     if (!err) {
         if (buf_get_attrs(&outbuf, stbuf, NULL) == -1)
+#ifdef EPROTO
             err = -EPROTO;
+#else
+             err = -EPROTONOSUPPORT;
+#endif
         buf_free(&outbuf);
     }
     buf_free(&buf);
@@ -1164,7 +1197,11 @@
     if (!err) {
         uint32_t count;
         char *link;
+#ifdef EPROTO
         err = -EPROTO;
+#else
+        err = -EPROTONOSUPPORT;
+#endif
         if(buf_get_uint32(&name, &count) != -1 && count == 1 &&
            buf_get_string(&name, &link) != -1) {
             strncpy(linkbuf, link, size-1);
@@ -1195,7 +1232,11 @@
             err = sftp_request(SSH_FXP_READDIR, &handle, SSH_FXP_NAME, &name);
             if (!err) {
                 if (buf_get_entries(&name, h, filler) == -1)
+#ifdef EPROTO
                     err = -EPROTO;
+#else
+                    err = -EPROTONOSUPPORT;
+#endif
                 buf_free(&name);
             }
         } while (!err);
@@ -1528,7 +1569,11 @@
     err = sftp_request(SSH_FXP_READ, &buf, SSH_FXP_DATA, &data);
     if (!err) {
         uint32_t retsize;
+#ifdef EPROTO
         err = -EPROTO;
+#else
+        err = -EPROTONOSUPPORT;
+#endif
         if (buf_get_uint32(&data, &retsize) != -1) {
             if (retsize > size)
                 fprintf(stderr, "long read\n");
@@ -1550,7 +1595,11 @@
     if (req->error)
         chunk->res = req->error;
     else if (req->replied) {
+#ifdef EPROTO
         chunk->res = -EPROTO;
+#else
+        chunk->res = -EPROTONOSUPPORT;
+#endif
 
         if (req->reply_type == SSH_FXP_STATUS) {
             uint32_t serr;
@@ -1771,7 +1820,7 @@
 {
     (void) path;
 
-    buf->f_namelen = 255;
+    buf->f_namemax = 255;
     buf->f_bsize = 512;
     buf->f_blocks = 999999999 * 2;
     buf->f_bfree =  999999999 * 2;
