--- common/cmd_nvedit.c.orig	2015-04-13 14:53:03 UTC
+++ common/cmd_nvedit.c
@@ -321,7 +321,7 @@ int setenv_hex(const char *varname, ulon
 {
 	char str[17];
 
-	sprintf(str, "%lx", value);
+	sprintf(str, "%#lx", value);
 	return setenv(varname, str);
 }
 
