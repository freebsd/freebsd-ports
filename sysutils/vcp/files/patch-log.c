--- log.c.orig	2022-11-06 12:59:27 UTC
+++ log.c
@@ -45,7 +45,7 @@ int logadds(int code, char *base, char *var, char *var
 }
 
 int logget(char *name) {
-	char c,decoy;
+	int c,decoy;
 	if(use_curses) {
 		if(Iflag)
 			wprintw(logw, "Overwrite %s ? [Y]/N ",name);
