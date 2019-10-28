--- termcap.c.orig	2019-10-01 22:08:00 UTC
+++ termcap.c
@@ -227,7 +227,7 @@ int he;
 	  (D_CKM && (InStr(D_CKM, "\033[M") || InStr(D_CKM, "\033[<"))))
         {
           D_CXT = 1;
-          kmapdef[0] = SaveStr(D_CKM);
+          kmapdef[0] = D_CKM ? SaveStr(D_CKM) : NULL;
         }
       /* "be" seems to be standard for xterms... */
       if (D_CXT)
@@ -362,11 +362,7 @@ int he;
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
