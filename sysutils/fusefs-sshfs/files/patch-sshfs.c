--- sshfs.c.orig	Mon Aug 15 05:07:08 2005
+++ sshfs.c	Sun Oct  9 13:12:45 2005
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
@@ -970,7 +981,11 @@
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
@@ -985,21 +1000,35 @@
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
@@ -1039,7 +1068,11 @@
     err = sftp_request(SSH_FXP_LSTAT, &buf, SSH_FXP_ATTRS, &outbuf);
     if (!err) {
         if (buf_get_attrs(&outbuf, stbuf) == -1)
+#ifdef EPROTO
             err = -EPROTO;
+#else
+            err = -EPROTONOSUPPORT;
+#endif
         buf_free(&outbuf);
     }
     buf_free(&buf);
@@ -1061,7 +1094,11 @@
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
@@ -1092,7 +1129,11 @@
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
@@ -1377,7 +1418,11 @@
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
@@ -1399,7 +1444,11 @@
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
