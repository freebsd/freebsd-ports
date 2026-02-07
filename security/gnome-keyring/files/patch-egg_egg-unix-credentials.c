--- egg/egg-unix-credentials.c.orig	2025-03-18 08:38:44 UTC
+++ egg/egg-unix-credentials.c
@@ -142,7 +142,9 @@ egg_unix_credentials_read (int sock, pid_t *pid, uid_t
 		cred = (struct sockcred *) CMSG_DATA (&cmsg.hdr);
 		*pid = 0;
 		*uid = cred->sc_euid;
+#ifndef __FreeBSD__
 		set_local_creds(sock, 0);
+#endif
 #elif defined(HAVE_GETPEEREID) /* OpenBSD */
 		uid_t euid;
 		gid_t egid;
@@ -230,7 +232,7 @@ egg_unix_credentials_setup (int sock)
 #if defined(LOCAL_CREDS) && !defined(HAVE_CMSGCRED)
 	int val = 1;
 	if (setsockopt (sock, 0, LOCAL_CREDS, &val, sizeof (val)) < 0) {
-		fprintf (stderr, "unable to set LOCAL_CREDS socket option on fd %d\n", fd);
+		fprintf (stderr, "unable to set LOCAL_CREDS socket option\n");
 		retval = -1;
 	}
 #endif
