
$FreeBSD$

--- libs/uti/sge_pty.c.orig
+++ libs/uti/sge_pty.c
@@ -40,7 +40,7 @@
 #include <string.h>
 #include <pwd.h>
 
-#if defined(DARWIN) || defined(INTERIX)
+#if defined(DARWIN) || defined(FREEBSD) || defined(INTERIX)
 #  include <termios.h>
 #  include <sys/ioctl.h>
 #  include <grp.h>
@@ -58,6 +58,10 @@
 #  include <termio.h>
 #endif
 
+#if defined(FREEBSD)
+#  include <libutil.h>
+#endif
+
 #include "sgermon.h"
 #include "sge_unistd.h"
 #include "sge_uidgid.h"
@@ -125,7 +129,7 @@
    }
    return -1;  /* out of pty devices */
 }
-#else
+#elif !defined(FREEBSD)
 int ptym_open(char *pts_name)
 {
    char *ptr;
@@ -205,7 +209,7 @@
    }
    return fds;
 }
-#else
+#elif !defined(FREEBSD)
 int ptys_open(int fdm, char *pts_name)
 {
    int      fds;
@@ -271,6 +275,31 @@
 *  SEE ALSO
 *     pty/fork_no_pty
 *******************************************************************************/
+#if defined(FREEBSD)
+pid_t fork_pty(int *ptrfdm, int *fd_pipe_err, dstring *err_msg)
+{
+   pid_t pid;
+   uid_t old_euid;
+
+   /* 
+    * We run this either as root with euid="sge admin user" or as an unprivileged 
+    * user.  If we are root with euid="sge admin user", we must change our
+    * euid back to root for this function.
+    */
+   old_euid = geteuid();
+   if (getuid() == SGE_SUPERUSER_UID) {
+      seteuid(SGE_SUPERUSER_UID);
+   }
+
+   if((pid = forkpty(*ptrfdm, NULL, NULL, NULL)) < 0) {
+      sge_dstring_sprintf(err_msg, "error in forkpty(): %d, %s",
+                          errno, strerror(errno));
+   }
+   seteuid(old_euid);
+
+   return pid;
+}
+#else
 pid_t fork_pty(int *ptrfdm, int *fd_pipe_err, dstring *err_msg)
 {
    pid_t pid;
@@ -364,6 +393,7 @@
       return pid;    /* parent returns pid of child */
    }
 }
+#endif
 
 /****** sge_pty/fork_no_pty() **************************************************
 *  NAME
