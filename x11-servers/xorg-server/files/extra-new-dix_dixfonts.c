--- dix/dixfonts.c.orig	2012-05-17 19:09:01.000000000 +0200
+++ dix/dixfonts.c	2013-10-09 10:49:38.158284440 +0200
@@ -1414,6 +1414,7 @@
             GC *pGC;
             unsigned char *data;
             ITclosurePtr new_closure;
+            ITclosurePtr old_closure;
 
             /* We're putting the client to sleep.  We need to
                save some state.  Similar problem to that handled
@@ -1425,12 +1426,14 @@
                 err = BadAlloc;
                 goto bail;
             }
+            old_closure = c;
             *new_closure = *c;
             c = new_closure;
 
             data = malloc(c->nChars * itemSize);
             if (!data) {
                 free(c);
+                c = old_closure;
                 err = BadAlloc;
                 goto bail;
             }
@@ -1441,6 +1444,7 @@
             if (!pGC) {
                 free(c->data);
                 free(c);
+                c = old_closure;
                 err = BadAlloc;
                 goto bail;
             }
@@ -1453,6 +1457,7 @@
                 FreeScratchGC(pGC);
                 free(c->data);
                 free(c);
+                c = old_closure;
                 err = BadAlloc;
                 goto bail;
             }
