--- auth-skey.c.orig	Wed Jun 19 02:27:55 2002
+++ auth-skey.c	Mon Jun 24 20:35:50 2002
@@ -26,7 +26,7 @@
 
 #ifdef SKEY
 
-#include <skey.h>
+#include <opie.h>
 
 #include "xmalloc.h"
 #include "auth.h"
@@ -45,9 +45,11 @@
 	Authctxt *authctxt = ctx;
 	char challenge[1024], *p;
 	int len;
-	struct skey skey;
+	struct opie opie;
 
-	if (skeychallenge(&skey, authctxt->user, challenge) == -1)
+	if (opie_haskey(authctxt->user) != 0)
+		return -1;
+	if (opiechallenge(&opie, authctxt->user, challenge) == -1)
 		return -1;
 
 	*name  = xstrdup("");
@@ -73,8 +75,8 @@
 
 	if (authctxt->valid &&
 	    numresponses == 1 &&
-	    skey_haskey(authctxt->pw->pw_name) == 0 &&
-	    skey_passcheck(authctxt->pw->pw_name, responses[0]) != -1)
+	    opie_haskey(authctxt->pw->pw_name) == 0 &&
+	    opie_passverify(authctxt->pw->pw_name, responses[0]) != -1)
 	    return 0;
 	return -1;
 }
