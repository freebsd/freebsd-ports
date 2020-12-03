--- src/cmd/ksh93/edit/pcomplete.c.orig	2020-11-20 14:41:10.427589000 +0000
+++ src/cmd/ksh93/edit/pcomplete.c	2020-11-20 14:47:28.958973000 +0000
@@ -338,8 +338,7 @@
     }
     if (complete) {
         // Reserved space on stack and try again.
-        len = 3;
-        tlen = (c + 1) * sizeof(char *) + len * c + 1024;
+        tlen += (c + 1) * sizeof(char *) + (plen + slen + 1) * c;
         stkseek(shp->stk, tlen);
         complete = 2;
         av = (char **)stkptr(shp->stk, 0);
