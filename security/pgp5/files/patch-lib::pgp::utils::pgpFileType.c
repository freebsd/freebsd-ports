$FreeBSD$

--- lib/pgp/utils/pgpFileType.c~	Sun Sep 26 15:23:48 1999
+++ lib/pgp/utils/pgpFileType.c	Sun Sep 26 15:28:22 1999
@@ -171,7 +171,7 @@
  * 24 CN cancel (can) ILLEGAL
  * 25 EM end of medium (em) ILLEGAL
  * 26 SB substitute (sub) legal (CP/M & MS-DOS EOF)
- * 27 EC escape (esc) ILLEGAL
+ * 27 EC escape (esc) legal
  * 28 FS file separator (is4)	ILLEGAL
  * 29 GS group separator (is3)	ILLEGAL
  * 30 RS record separator (is2)	ILLEGAL
@@ -199,7 +199,7 @@
 
 			do {
 					c = *buf++;
-					if (c < ' ' && (c < '\a' || c > '\r') && c != 26)
+					if (c < ' ' && (c < '\a' || c > '\r') && c != 26 && c != 27)
 						return 1;	/* Illegal control char */
 					if ((c & 0x80) && highlimit-- == 0)
 						return 1;	/* Too many 8th bits set */

