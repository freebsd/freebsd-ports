--- bicon/pty_spawn.c.orig	2015-08-20 10:07:00 UTC
+++ bicon/pty_spawn.c
@@ -13,7 +13,13 @@ namely the PSF License Agreement For Python 2.2.3
 #include <string.h>
 #include <unistd.h>
 #include <errno.h>
+#ifdef __linux__
 #include <pty.h>
+#endif
+#ifdef __FreeBSD__
+#include <termios.h>
+#include <sys/ioctl.h>
+#endif
 #include <sys/time.h>
 #include <sys/types.h>
 #include <sys/select.h>
@@ -119,7 +125,7 @@ _copy (
       {
 	if (errno == EINTR && !done)
 	  continue;
-	return;
+	return 0;
       }
       if (0 == ret)
       {
@@ -150,14 +156,14 @@ _copy (
 	{
 	  count = _xread (master_read, master_fd, buf, sizeof (buf));
 	  if (count == -1)
-	    return;
+	    return 0;
 	  _xwrite (1, buf, count);
 	}
       if (FD_ISSET (0, &rfds))
 	{
 	  count = _xread (stdin_read, 0, buf, sizeof (buf));
 	  if (count == -1)
-	    return;
+	    return 0;
 	  _xwrite (master_fd, buf, count);
 	}
       /* Set timeout, such that if things are steady, we update cwd
