--- termcap.c.orig	2020-02-05 12:09:38.000000000 -0800
+++ termcap.c	2020-02-11 20:10:12.747990000 -0800
@@ -361,11 +361,7 @@
   if (D_CG0)
     {
       if (D_CS0 == 0)
-#ifdef TERMINFO
-        D_CS0 = "\033(%p1%c";
-#else
-        D_CS0 = "\033(%.";
-#endif
+	D_CS0 = "\033(%p1%c"; /* Old ncurses can't handle %. */
       if (D_CE0 == 0)
         D_CE0 = "\033(B";
       D_AC = 0;
