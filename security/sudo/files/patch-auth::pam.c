--- auth/pam.c.orig	Wed Apr  2 11:55:50 2003
+++ auth/pam.c	Wed Apr  2 11:57:32 2003
@@ -224,11 +224,11 @@
 		    p = pm->msg;
 		/* Read the password. */
 		pass = tgetpass(p, def_ival(I_PASSWD_TIMEOUT) * 60, flags);
-		pr->resp = estrdup(pass ? pass : "");
+		pr->resp = estrdup((const char *)pass ? (const char *)pass : "");
 		if (*pr->resp == '\0')
 		    nil_pw = 1;		/* empty password */
 		else
-		    memset(pass, 0, strlen(pass));
+		    memset((void *)pass, 0, strlen((const char *)pass));
 		break;
 	    case PAM_TEXT_INFO:
 		if (pm->msg)
