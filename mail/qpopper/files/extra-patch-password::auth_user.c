--- password/auth_user.c.orig	Fri Mar 14 00:39:42 2003
+++ password/auth_user.c	Fri Mar 14 00:40:02 2003
@@ -41,6 +41,7 @@
 
 
 
+#undef SPEC_POP_AUTH
 
 
 static const char *ERRMSG_PW = "Password mismatch for user \"%s\"";
