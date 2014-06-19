--- Xvnc/lib/font/Type1/t1malloc.c.orig	2000-04-12 11:18:28.000000000 -0700
+++ Xvnc/lib/font/Type1/t1malloc.c	2013-10-30 23:14:26.000000000 -0700
@@ -286,7 +286,7 @@
 */
                 addr[0] = addr[size - 1] = size;
                 firstcombined = (struct freeblock *) addr;
-                return;
+                return(0);
         }
 /*
 Otherwise, we unhook this pointer from the chain:
@@ -657,7 +657,7 @@
        register struct freeblock *p;  /* pointer to block                    */
  
        if (area == NULL)
-               return;
+               return (0);
        wholesize = - *area++;
        wholesize -= 2;
  
