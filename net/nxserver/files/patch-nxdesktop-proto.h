--- nxdesktop/proto.h.orig	Wed Sep 15 18:29:24 2004
+++ nxdesktop/proto.h	Wed Apr  6 12:02:30 2005
@@ -133,7 +133,7 @@
 int get_device_index(HANDLE handle);
 void convert_to_unix_filename(char *filename);
 BOOL rdpdr_init(void);
-void rdpdr_add_fds(int *n, fd_set * rfds, fd_set * wfds, struct timeval *tv, BOOL * timeout);
+/* void rdpdr_add_fds(int *n, fd_set * rfds, fd_set * wfds, struct timeval *tv, BOOL * timeout); */
 struct async_iorequest *rdpdr_remove_iorequest(struct async_iorequest *prev,
 					       struct async_iorequest *iorq);
 void rdpdr_check_fds(fd_set * rfds, fd_set * wfds, BOOL timed_out);
