--- librscg/scsi-remote.c.orig	Thu Jan 15 01:25:09 2004
+++ librscg/scsi-remote.c	Tue Aug 24 00:11:42 2004
@@ -1074,6 +1074,13 @@
 		if (getuid() != pw->pw_uid &&
 		    setuid(pw->pw_uid) == -1) {
 			errmsg("setuid(%lld) failed.\n",
+							(Llong)pw->pw_uid);
+			_exit(EX_BAD);
+			/* NOTREACHED */
+		}
+		if (getuid() != geteuid() &&
+		    seteuid(pw->pw_uid) == -1) {
+			errmsg("seteuid(%lld) failed.\n",
 							(Llong)pw->pw_uid);
 			_exit(EX_BAD);
 			/* NOTREACHED */
