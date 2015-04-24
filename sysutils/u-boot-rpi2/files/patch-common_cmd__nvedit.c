--- common/cmd_nvedit.c.orig	2015-04-24 11:11:51.572065000 -0300
+++ common/cmd_nvedit.c
@@ -321,7 +321,7 @@
 {
 	char str[17];
 
-	sprintf(str, "%lx", value);
+	sprintf(str, "%#lx", value);
 	return setenv(varname, str);
 }
 
