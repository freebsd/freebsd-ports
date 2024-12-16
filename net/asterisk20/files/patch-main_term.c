--- main/term.c.orig	2024-10-17 16:00:41 UTC
+++ main/term.c
@@ -46,6 +46,7 @@ static const char * const termpath[] = {
 static char quitdata[80] = "";
 
 static const char * const termpath[] = {
+	"%%LOCALBASE%%/share/terminfo",
 	"/usr/share/terminfo",
 	"/usr/local/share/misc/terminfo",
 	"/usr/lib/terminfo",
