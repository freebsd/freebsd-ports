--- rot.c.orig	1989-03-05 02:11:02.000000000 +0100
+++ rot.c	2013-06-14 00:36:58.068387596 +0200
@@ -244,10 +244,10 @@
       if (i2 >= 0L)
       {
          if (seekinput (sum + z + col, 1) == -1)
-            return;
+            return 0;
 
          if ((c = getinput()) == EOF)
-            return;                  /* end of input */
+            return 0;                  /* end of input */
 
          if (c == ' ' && !bflag)
             holdbl++;
@@ -292,9 +292,9 @@
       if (i2 > 0L)
       {
          if (seekinput (- (sum + z + 2L), 1) == -1)
-            return;
+            return 0;
          if ((c = getinput()) == EOF)
-            return;                  /* end of input */
+            return 0;                  /* end of input */
 
          if (c == ' ' && !bflag)
             holdbl++;
