diff -u ../old/FD-2.00a/pathname.c ./pathname.c
--- ../old/FD-2.00a/pathname.c	Wed Feb  6 00:00:00 2002
+++ ./pathname.c	Fri Mar 22 08:55:40 2002
@@ -2744,7 +2744,7 @@
 				for (w = 0; wild[w]; w++)
 					(*argvp)[n + w] = wild[w];
 				free(wild);
-				n += w;
+				n += w - 1;
 				break;
 			}
 
