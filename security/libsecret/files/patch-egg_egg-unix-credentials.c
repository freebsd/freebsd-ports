--- egg/egg-unix-credentials.c.orig	2024-02-23 09:53:23 UTC
+++ egg/egg-unix-credentials.c
@@ -230,7 +230,7 @@ egg_unix_credentials_setup (int sock)
 #if defined(LOCAL_CREDS) && !defined(HAVE_CMSGCRED)
 	int val = 1;
 	if (setsockopt (sock, 0, LOCAL_CREDS, &val, sizeof (val)) < 0) {
-		fprintf (stderr, "unable to set LOCAL_CREDS socket option on fd %d\n", fd);
+		fprintf (stderr, "unable to set LOCAL_CREDS socket option\n");
 		retval = -1;
 	}
 #endif
