Taken from: [FDclone-users:00108]
diff -u old/pathname.c ./pathname.c
--- old/pathname.c	Wed Dec 25 00:00:00 2002
+++ ./pathname.c	Sun Feb 16 10:18:00 2003
@@ -1173,7 +1173,7 @@
 				else paren[plen++] = toupper2(s[i]);
 			}
 		}
-		else if (!quote) switch (s[i]) {
+		else if (!quote && !metachar) switch (s[i]) {
 			case '?':
 				cp = wildsymbol1;
 				break;
