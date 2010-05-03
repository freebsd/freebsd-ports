--- lib/rfc1738.c.orig	2010-04-16 14:36:23.000000000 +0200
+++ lib/rfc1738.c	2010-04-16 14:37:11.000000000 +0200
@@ -203,8 +203,7 @@ rfc1738_unescape(char *s)
             j++;		/* Skip % */
         } else {
             /* decode */
-            char v1, v2;
-            int x;
+            int v1, v2, x;
             v1 = fromhex(s[j + 1]);
             if (v1 < 0)
                 continue;  /* non-hex or \0 */
