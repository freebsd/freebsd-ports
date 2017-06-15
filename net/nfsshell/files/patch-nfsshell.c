--- nfsshell.c.orig	2013-05-10 21:40:04 UTC
+++ nfsshell.c
@@ -70,7 +70,7 @@
 #include <netinet/in.h>
 #include <arpa/inet.h>
 #include <sys/time.h>
-#include <sys/sysmacros.h>
+#include <sys/param.h>
 #include "mount.h"
 #include "nfs_prot.h"
 #include <netinet/in_systm.h>
@@ -238,6 +238,7 @@ void do_status(int, char **);
 void do_help(int, char **);
 
 AUTH *create_authenticator(void);
+char *mount_error(enum mountstat3);
 char *nfs_error(enum nfsstat3);
 int open_mount(char *);
 void close_mount(void);
@@ -1915,7 +1916,7 @@ open_nfs(char *path, int port, int flags
 	}
 	if (mountpoint->fhs_status != MNT3_OK) {
             fprintf(stderr, "Mount failed: %s\n",
-		nfs_error(mountpoint->fhs_status));
+		mount_error(mountpoint->fhs_status));
 	    return 0;
 	}
 	fhandle3_to_nfs_fh3(&directory_handle, &mountpoint->mountres3_u.mountinfo.fhandle);
@@ -2253,6 +2254,38 @@ umatchpattern(char *s, char *p)
 }
 
 /*
+ * MOUNT errors
+ */
+char *
+mount_error(enum mountstat3 stat)
+{
+    switch (stat) {
+    case MNT3_OK:
+	return "No error";
+    case MNT3ERR_PERM:
+	return "Not owner";
+    case MNT3ERR_NOENT:
+	return "No such file or directory";
+    case MNT3ERR_IO:
+	return "I/O error";
+    case MNT3ERR_ACCES:
+	return "Permission denied";
+    case MNT3ERR_NOTDIR:
+	return "Not a directory";
+    case MNT3ERR_INVAL:
+	return "Invalid parameter";
+    case MNT3ERR_NAMETOOLONG:
+	return "File name too long";
+    case MNT3ERR_NOTSUPP:
+	return "Operation is not supported";
+    case MNT3ERR_SERVERFAULT:
+	return "Other server error";
+    default:
+	return "UKNOWN MOUNT ERROR";
+    }
+}
+
+/*
  * NFS errors
  */
 char *
