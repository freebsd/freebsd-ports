--- monitor.c.orig	Sun Mar 23 20:02:00 2003
+++ monitor.c	Mon Mar 31 16:15:24 2003
@@ -30,7 +30,7 @@
 #include <openssl/dh.h>
 
 #ifdef SKEY
-#include <skey.h>
+#include <opie.h>
 #endif
 
 #include "ssh.h"
@@ -670,11 +670,11 @@
 int
 mm_answer_skeyquery(int socket, Buffer *m)
 {
-	struct skey skey;
+ 	struct opie opie;
 	char challenge[1024];
 	u_int success;
 
-	success = skeychallenge(&skey, authctxt->user, challenge) < 0 ? 0 : 1;
+	success = opiechallenge(&opie, authctxt->user, challenge) < 0 ? 0 : 1;
 
 	buffer_clear(m);
 	buffer_put_int(m, success);
@@ -697,8 +697,8 @@
 
 	authok = (options.challenge_response_authentication &&
 	    authctxt->valid &&
-	    skey_haskey(authctxt->pw->pw_name) == 0 &&
-	    skey_passcheck(authctxt->pw->pw_name, response) != -1);
+	    opie_haskey(authctxt->pw->pw_name) == 0 &&
+	    opie_passverify(authctxt->pw->pw_name, response) != -1);
 
 	xfree(response);
 
