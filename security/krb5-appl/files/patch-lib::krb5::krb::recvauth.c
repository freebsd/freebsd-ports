--- lib/krb5/krb/recvauth.c.orig	Mon Sep  2 18:13:47 2002
+++ lib/krb5/krb/recvauth.c	Tue Jul 12 14:02:03 2005
@@ -76,7 +76,6 @@
 	    if ((retval = krb5_read_message(context, fd, &inbuf)))
 		return(retval);
 	    if (strcmp(inbuf.data, sendauth_version)) {
-		krb5_xfree(inbuf.data);
 		problem = KRB5_SENDAUTH_BADAUTHVERS;
 	    }
 	    krb5_xfree(inbuf.data);
@@ -90,7 +89,6 @@
 	if ((retval = krb5_read_message(context, fd, &inbuf)))
 		return(retval);
 	if (appl_version && strcmp(inbuf.data, appl_version)) {
-		krb5_xfree(inbuf.data);
 		if (!problem)
 			problem = KRB5_SENDAUTH_BADAPPLVERS;
 	}
