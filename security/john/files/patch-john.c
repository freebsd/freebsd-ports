--- john.c.orig	2014-12-18 07:59:02 UTC
+++ john.c
@@ -153,7 +153,6 @@ extern int base64conv(int argc, char **argv);
 extern int hccap2john(int argc, char **argv);
 extern int zip2john(int argc, char **argv);
 extern int gpg2john(int argc, char **argv);
-extern int ssh2john(int argc, char **argv);
 extern int pfx2john(int argc, char **argv);
 extern int keychain2john(int argc, char **argv);
 extern int kwallet2john(int argc, char **argv);
@@ -1540,11 +1539,6 @@ int main(int argc, char **argv)
 	if (!strcmp(name, "unique")) {
 		CPU_detect_or_fallback(argv, 0);
 		return unique(argc, argv);
-	}
-
-	if (!strcmp(name, "ssh2john")) {
-		CPU_detect_or_fallback(argv, 0);
-		return ssh2john(argc, argv);
 	}
 
 	if (!strcmp(name, "putty2john")) {
