--- monitor.c.orig	Fri Jun 21 07:50:51 2002
+++ monitor.c	Mon Jun 24 20:39:42 2002
@@ -30,7 +30,7 @@
 #include <openssl/dh.h>
 
 #ifdef SKEY
-#include <skey.h>
+#include <opie.h>
 #endif
 
 #include "ssh.h"
@@ -656,11 +656,11 @@
 int
 mm_answer_skeyquery(int socket, Buffer *m)
 {
-	struct skey skey;
+	struct opie opie;
 	char challenge[1024];
 	int res;
 
-	res = skeychallenge(&skey, authctxt->user, challenge);
+	res = opiechallenge(&opie, authctxt->user, challenge);
 
 	buffer_clear(m);
 	buffer_put_int(m, res);
@@ -683,8 +683,8 @@
 
 	authok = (options.challenge_response_authentication &&
 	    authctxt->valid &&
-	    skey_haskey(authctxt->pw->pw_name) == 0 &&
-	    skey_passcheck(authctxt->pw->pw_name, response) != -1);
+	    opie_haskey(authctxt->pw->pw_name) == 0 &&
+	    opie_passverify(authctxt->pw->pw_name, response) != -1);
 
 	xfree(response);
 
