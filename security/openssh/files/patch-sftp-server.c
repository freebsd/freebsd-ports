--- sftp-server.c.orig	Wed Feb 13 01:28:13 2002
+++ sftp-server.c	Fri Mar  8 21:15:56 2002
@@ -614,6 +614,9 @@
 	u_int32_t id;
 	int handle, fd, ret;
 	int status = SSH2_FX_OK;
+#if defined(__FreeBSD__) && __FreeBSD__ <= 3
+	char *name;
+#endif
 
 	id = get_int();
 	handle = get_handle();
@@ -634,7 +637,12 @@
 				status = errno_to_portable(errno);
 		}
 		if (a->flags & SSH2_FILEXFER_ATTR_ACMODTIME) {
+#if defined(__FreeBSD__) && __FreeBSD__ <= 3
+			name = handle_to_name(handle);
+			ret = utimes(name, attrib_to_tv(a));
+#else
 			ret = futimes(fd, attrib_to_tv(a));
+#endif
 			if (ret == -1)
 				status = errno_to_portable(errno);
 		}
