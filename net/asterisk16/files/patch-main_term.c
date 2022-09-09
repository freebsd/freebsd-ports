--- main/term.c.orig	2022-06-23 15:21:01 UTC
+++ main/term.c
@@ -46,6 +46,7 @@ static char enddata[80] = "";
 static char quitdata[80] = "";
 
 static const char * const termpath[] = {
+	"%%LOCALBASE%%/share/terminfo",
 	"/usr/share/terminfo",
 	"/usr/local/share/misc/terminfo",
 	"/usr/lib/terminfo",
