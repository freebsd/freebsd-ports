--- tty.c.orig	1997-07-18 14:58:32 UTC
+++ tty.c
@@ -82,7 +82,7 @@ static struct ltchars oldchars, newchars;
 #   define OXTABS TAB3
 #endif
 
-int TtyUpperCase;
+int TtyUpperCase = 0;
 
 #define NOCHAR 0
 
