--- mbox_maildir.c.orig	Tue Apr 17 05:09:26 2001
+++ mbox_maildir.c	Wed May 16 08:52:34 2001
@@ -212,6 +212,7 @@
 			continue;
 		}
 	}
+	facility = LOG_INFO;
 	syslog(facility, "%s: retr %d leave %d %d byte%s %d error%s D%d(%d) "
 	    "E%d(%d) R%d(%d)",
 	    user->auth_string, ret, user->mbx.mail.num - del - exp - rem,
