Index: auth/pam.c
===================================================================
RCS file: /home/cvs/sudo/sudo/auth/pam.c,v
retrieving revision 1.30
retrieving revision 1.31
diff -u -r1.30 -r1.31
--- auth/pam.c	22 Nov 2002 19:41:13 -0000	1.30
+++ auth/pam.c	13 Dec 2002 16:33:26 -0000	1.31
@@ -66,7 +66,7 @@
 #include "sudo_auth.h"
 
 #ifndef lint
-static const char rcsid[] = "$Sudo: pam.c,v 1.29 2002/01/22 16:43:23 millert Exp $";
+static const char rcsid[] = "$Sudo: pam.c,v 1.30 2002/11/22 19:41:13 millert Exp $";
 #endif /* lint */
 
 static int sudo_conv __P((int, PAM_CONST struct pam_message **,
@@ -205,7 +205,7 @@
     PAM_CONST struct pam_message *pm;
     const char *p = def_prompt;
     char *pass;
-    int n;
+    int n, flags;
     extern int nil_pw;
 
     if ((*response = malloc(num_msg * sizeof(struct pam_response))) == NULL)
@@ -213,17 +213,17 @@
     (void) memset(*response, 0, num_msg * sizeof(struct pam_response));
 
     for (pr = *response, pm = *msg, n = num_msg; n--; pr++, pm++) {
+	flags = tgetpass_flags;
 	switch (pm->msg_style) {
 	    case PAM_PROMPT_ECHO_ON:
-		tgetpass_flags |= TGP_ECHO;
+		flags |= TGP_ECHO;
 	    case PAM_PROMPT_ECHO_OFF:
 		/* Only override PAM prompt if it matches /^Password: ?/ */
 		if (strncmp(pm->msg, "Password:", 9) || (pm->msg[9] != '\0'
 		    && (pm->msg[9] != ' ' || pm->msg[10] != '\0')))
 		    p = pm->msg;
 		/* Read the password. */
-		pass = tgetpass(p, def_ival(I_PASSWD_TIMEOUT) * 60,
-		    tgetpass_flags);
+		pass = tgetpass(p, def_ival(I_PASSWD_TIMEOUT) * 60, flags);
 		pr->resp = estrdup(pass ? pass : "");
 		if (*pr->resp == '\0')
 		    nil_pw = 1;		/* empty password */
