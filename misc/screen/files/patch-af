--- termcap.c.orig	Wed Jul  5 16:33:30 2000
+++ termcap.c	Wed Oct 11 05:40:12 2000
@@ -355,11 +355,7 @@
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
