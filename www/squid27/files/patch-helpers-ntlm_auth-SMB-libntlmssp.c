This patch fixes a buffer overflow vulnerability in the NTLM auth
helper which was reported by Stefan Esser on the 07th June 2004.
Original advisory:
<http://www.idefense.com/application/poi/display?id=107&type=vulnerabilities&flashstatus=false>
CVE-ID: CAN-2004-0541
Patch obtained from:
<http://www.squid-cache.org/~wessels/patch/libntlmssp.c.patch>
The patch was slightly modified by the me (tmseck@netcologne.de) to make
it apply cleanly to the FreeBSD port.

Index: libntlmssp.c
===================================================================
RCS file: /server/cvs-server/squid/squid/helpers/ntlm_auth/SMB/libntlmssp.c,v
retrieving revision 1.7
diff -u -3 -p -u -r1.7 libntlmssp.c
--- helpers/ntlm_auth/SMB/libntlmssp.c	30 Nov 2001 09:50:28 -0000	1.7
+++ helpers/ntlm_auth/SMB/libntlmssp.c	20 May 2004 22:31:33 -0000
@@ -161,7 +161,10 @@ make_challenge(char *domain, char *domai
 #define min(A,B) (A<B?A:B)
 
 int ntlm_errno;
-static char credentials[1024];	/* we can afford to waste */
+#define MAX_USERNAME_LEN 255
+#define MAX_DOMAIN_LEN 255
+#define MAX_PASSWD_LEN 31
+static char credentials[MAX_USERNAME_LEN+MAX_DOMAIN_LEN+2];	/* we can afford to waste */
 
 
 /* Fetches the user's credentials from the challenge.
@@ -197,7 +200,7 @@ char *
 ntlm_check_auth(ntlm_authenticate * auth, int auth_length)
 {
     int rv;
-    char pass[25] /*, encrypted_pass[40] */;
+    char pass[MAX_PASSWD_LEN+1];
     char *domain = credentials;
     char *user;
     lstring tmp;
@@ -215,8 +218,13 @@ ntlm_check_auth(ntlm_authenticate * auth
 	ntlm_errno = NTLM_LOGON_ERROR;
 	return NULL;
     }
+    if (tmp.l > MAX_DOMAIN_LEN) {
+	debug("Domain string exceeds %d bytes, rejecting\n", MAX_DOMAIN_LEN);
+	ntlm_errno = NTLM_LOGON_ERROR;
+	return NULL;
+    }
     memcpy(domain, tmp.str, tmp.l);
-    user = domain + tmp.l;
+    user = domain + tmp.l + 1;
     *user++ = '\0';
 
 /*      debug("fetching user name\n"); */
@@ -226,20 +234,30 @@ ntlm_check_auth(ntlm_authenticate * auth
 	ntlm_errno = NTLM_LOGON_ERROR;
 	return NULL;
     }
+    if (tmp.l > MAX_USERNAME_LEN) {
+	debug("Username string exceeds %d bytes, rejecting\n", MAX_USERNAME_LEN);
+	ntlm_errno = NTLM_LOGON_ERROR;
+	return NULL;
+    }
     memcpy(user, tmp.str, tmp.l);
     *(user + tmp.l) = '\0';
 
 		
-		/* Authenticating against the NT response doesn't seem to work... */
+    /* Authenticating against the NT response doesn't seem to work... */
     tmp = ntlm_fetch_string((char *) auth, auth_length, &auth->lmresponse);
     if (tmp.str == NULL || tmp.l == 0) {
 	fprintf(stderr, "No auth at all. Returning no-auth\n");
 	ntlm_errno = NTLM_LOGON_ERROR;
 	return NULL;
     }
-		
+    if (tmp.l > MAX_PASSWD_LEN) {
+	debug("Password string exceeds %d bytes, rejecting\n", MAX_PASSWD_LEN);
+	ntlm_errno = NTLM_LOGON_ERROR;
+	return NULL;
+    }
+
     memcpy(pass, tmp.str, tmp.l);
-    pass[25] = '\0';
+    pass[min(MAX_PASSWD_LEN,tmp.l)] = '\0';
 
 #if 1
 		debug ("Empty LM pass detection: user: '%s', ours:'%s', his: '%s'"
