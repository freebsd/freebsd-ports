--- src/auth.c.old	Tue Sep  5 23:16:10 2000
+++ src/auth.c	Fri Jan  5 10:14:11 2001
@@ -420,7 +420,7 @@
 				/*
 				 *	Plain text password.
 				 */
-				snprintf(dbpass, 128, " Password should be '%s'", password_pair->strvalue);
+				strncpy(dbpass," Password mismatch",128);
 				if (password_pair == NULL ||
 				    strcmp(password_pair->strvalue, string)!=0)
 					result = -1;
