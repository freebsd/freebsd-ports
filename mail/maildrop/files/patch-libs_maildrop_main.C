--- libs/maildrop/main.C.orig	2015-06-20 13:01:36 UTC
+++ libs/maildrop/main.C
@@ -264,13 +264,13 @@ static int callback_authlib(struct authi
 			    void *void_arg)
 {
 	Maildrop &maildrop=*(Maildrop *)void_arg;
-
+/*
 	if (auth_mkhomedir(auth))
 	{
 		perror(auth->homedir);
 		exit(1);
 	}
-
+*/
 	if (VerboseLevel() > 1)
 	{
 		Buffer b;
