--- src/subshell.c.orig
+++ src/subshell.c
@@ -386,6 +386,8 @@
 	    subshell_type = ZSH;
 	else if (strstr (shell, "/tcsh"))
 	    subshell_type = TCSH;
+	else if (strstr (shell, "/csh"))
+	    subshell_type = TCSH;
 	else if (strstr (shell, "/bash") || getenv ("BASH"))
 	    subshell_type = BASH;
 	else {
