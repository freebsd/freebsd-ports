--- src/gp_socket.c.orig	2026-07-21 10:43:49 UTC
+++ src/gp_socket.c
@@ -14,6 +14,11 @@
 #include <sys/socket.h>
 #include <sys/stat.h>
 #include <sys/types.h>
+#ifdef __FreeBSD__
+#include <limits.h>
+#include <sys/sysctl.h>
+#include <sys/ucred.h>
+#endif
 #include <sys/uio.h>
 #include <sys/un.h>
 #include <unistd.h>
@@ -309,17 +314,48 @@ static int get_peercred(int fd, struct gp_conn *conn)
     socklen_t len;
     int ret;
 
-    len = sizeof(struct ucred);
-    ret = getsockopt(fd, SOL_SOCKET, SO_PEERCRED, &conn->creds.ucred, &len);
-    if (ret == -1) {
-        ret = errno;
-        GPDEBUG("Failed to get SO_PEERCRED options! (%d:%s)\n",
-                ret, gp_strerror(ret));
-        return ret;
+#ifdef __FreeBSD__
+    {
+        struct xucred xucred;
+
+        len = sizeof(xucred);
+        ret = getsockopt(fd, SOL_LOCAL, LOCAL_PEERCRED, &xucred, &len);
+        if (ret == -1) {
+            ret = errno;
+            GPDEBUG("Failed to get LOCAL_PEERCRED options! (%d:%s)\n",
+                    ret, gp_strerror(ret));
+            return ret;
+        }
+        if (len != sizeof(xucred) ||
+            xucred.cr_version != XUCRED_VERSION) {
+            return EIO;
+        }
+
+        conn->creds.ucred.pid = xucred.cr_pid;
+        conn->creds.ucred.uid = xucred.cr_uid;
+        conn->creds.ucred.gid = xucred.cr_gid;
     }
-    if (len != sizeof(struct ucred)) {
-        return EIO;
+#else
+    {
+        struct ucred ucred;
+
+        len = sizeof(ucred);
+        ret = getsockopt(fd, SOL_SOCKET, SO_PEERCRED, &ucred, &len);
+        if (ret == -1) {
+            ret = errno;
+            GPDEBUG("Failed to get SO_PEERCRED options! (%d:%s)\n",
+                    ret, gp_strerror(ret));
+            return ret;
+        }
+        if (len != sizeof(ucred)) {
+            return EIO;
+        }
+
+        conn->creds.ucred.pid = ucred.pid;
+        conn->creds.ucred.uid = ucred.uid;
+        conn->creds.ucred.gid = ucred.gid;
     }
+#endif
 
     conn->creds.type |= CRED_TYPE_UNIX;
 
@@ -338,8 +374,34 @@ static int get_peercred(int fd, struct gp_conn *conn)
     return 0;
 }
 
+#ifdef __FreeBSD__
 static char *get_program(pid_t pid)
 {
+    int mib[4] = { CTL_KERN, KERN_PROC, KERN_PROC_PATHNAME, pid };
+    char path[PATH_MAX];
+    size_t len = sizeof(path);
+    int e;
+
+    if (sysctl(mib, 4, path, &len, NULL, 0) == -1) {
+        e = errno;
+        if (e == ESRCH || e == ENOENT) {
+            return NULL;
+        }
+        GPERROR("Unable to read program path: %d (%s)",
+                e, gp_strerror(e));
+        return NULL;
+    }
+
+    if (len == 0) {
+        return NULL;
+    }
+
+    path[sizeof(path) - 1] = 0;
+    return strdup(path);
+}
+#else
+static char *get_program(pid_t pid)
+{
     char procfile[21];
     char *program;
     int ret, e;
@@ -377,6 +439,8 @@ static char *get_program(pid_t pid)
             e, strerror(e));
     return NULL;
 }
+
+#endif
 
 static void gp_socket_read(verto_ctx *vctx, verto_ev *ev);
 
