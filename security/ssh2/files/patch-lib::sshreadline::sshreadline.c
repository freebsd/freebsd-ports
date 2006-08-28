--- lib/sshreadline/sshreadline.c.orig	Wed Dec  3 14:17:20 2003
+++ lib/sshreadline/sshreadline.c	Fri Aug 18 20:58:55 2006
@@ -500,8 +500,13 @@
   new_term.c_lflag &= ~(ECHO | ICANON);
   new_term.c_cc[VMIN] = 1;
   new_term.c_cc[VTIME] = 1;
-  if (tcsetattr(fd, TCSAFLUSH, &new_term) < 0)
+  while (tcsetattr(fd, TCSAFLUSH, &new_term) < 0)
     {
+      if (errno == EINTR)
+        {
+          errno = 0; /* For Solaris; just to make sure. */
+          continue;
+        }
       ssh_warning("tcsetattr failed in ssh_rl_set_tty_modes_for_fd: "
                   "fd %d: %.200s", fd, strerror(errno));
       return -1;
@@ -561,8 +566,13 @@
 {
   fcntl(fd, F_SETFL, fcntl_flags);
 
-  if (tcsetattr(fd, TCSAFLUSH, saved_tio) < 0)
+  while (tcsetattr(fd, TCSAFLUSH, saved_tio) < 0)
     {
+      if (errno == EINTR)
+        {
+          errno = 0; /* For Solaris; just to make sure. */
+          continue;
+        }
       ssh_warning("tcsetattr failed in ssh_rl_restore_tty_modes_for_fd: "
                   "fd %d: %.200s", fd, strerror(errno));
       return -1;
