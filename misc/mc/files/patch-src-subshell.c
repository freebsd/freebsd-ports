diff -ruN src/subshell.c.orig src/subshell.c
--- src/subshell.c.orig	Wed Jun 14 15:45:12 2006
+++ src/subshell.c	Wed Jun 14 15:45:39 2006
@@ -395,6 +395,8 @@
	    subshell_type = ZSH;
	else if (strstr (shell, "/tcsh"))
	    subshell_type = TCSH;
+	else if (strstr (shell, "/csh"))
+	    subshell_type = TCSH;
	else if (strstr (shell, "/bash") || getenv ("BASH"))
	    subshell_type = BASH;
	else {
