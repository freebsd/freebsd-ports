--- fileio.c.orig	2019-10-01 15:08:00.000000000 -0700
+++ fileio.c	2019-10-28 19:37:41.585000000 -0700
@@ -480,10 +480,7 @@
                 break;
 
             case DUMP_TERMCAP:
-              if ((p = index(MakeTermcap(fore->w_aflag), '=')) != NULL) {
-                fputs(++p, f);
-                putc('\n', f);
-              }
+              DumpTermcap(fore->w_aflag, f);
 	      break;
 
 #ifdef COPY_PASTE
