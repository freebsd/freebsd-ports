--- libs/maildrop/main.C.orig	2023-03-05 01:40:24 UTC
+++ libs/maildrop/main.C
@@ -404,11 +404,8 @@ static int callback_dovecotauth(struct dovecotauthinfo
 
 	if (VerboseLevel() > 1)
 	{
-		std::string b;
+		std::string b = std::to_string(auth->sysgroupid);
 
-		b.set(auth->sysgroupid);
-		b.push(0);
-
 		merr << "maildrop: dovecotauth: groupid="
 		     << b << "\n";
 	}
@@ -436,10 +433,7 @@ static int callback_dovecotauth(struct dovecotauthinfo
 
 	if (VerboseLevel() > 1)
 	{
-		std::string b;
-
-		b.set(u);
-		b.push(0);
+		std::string b = std::to_string(u);
 
 		merr << "maildrop: dovecotauth: userid="
 		     << b << "\n";
