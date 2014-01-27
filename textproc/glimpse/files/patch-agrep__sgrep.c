--- ./agrep/sgrep.c.orig	1999-11-01 20:32:58.000000000 +0000
+++ ./agrep/sgrep.c	2014-01-27 21:40:18.000000000 +0000
@@ -1539,7 +1539,7 @@
 		hash = TR[*text];
 		hash = (hash << 3) + TR[*(text-1)];
 		shift = SHIFT_2[hash];
-		while(shift) {
+		while(shift && text <= textend) {
 			text = text + shift;
 			hash = (TR[*text] << 3) + TR[*(text-1)];
 			shift = SHIFT_2[hash];
