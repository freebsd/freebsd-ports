--- dix/dixfonts.c.orig	2010-05-04 02:47:57.000000000 +0200
+++ dix/dixfonts.c	2013-10-09 10:54:40.488267646 +0200
@@ -1508,6 +1508,7 @@
 	    GC *pGC;
 	    unsigned char *data;
 	    ITclosurePtr new_closure;
+	    ITclosurePtr old_closure;
 
 	    /* We're putting the client to sleep.  We need to
 	       save some state.  Similar problem to that handled
@@ -1520,6 +1521,7 @@
 		err = BadAlloc;
 		goto bail;
 	    }
+	    old_closure = c;
 	    *new_closure = *c;
 	    c = new_closure;
 
@@ -1527,6 +1529,7 @@
 	    if (!data)
 	    {
 		xfree(c);
+		c = old_closure;
 		err = BadAlloc;
 		goto bail;
 	    }
@@ -1538,6 +1541,7 @@
 	    {
 		xfree(c->data);
 		xfree(c);
+		c = old_closure;
 		err = BadAlloc;
 		goto bail;
 	    }
@@ -1551,6 +1555,7 @@
 		FreeScratchGC(pGC);
 		xfree(c->data);
 		xfree(c);
+		c = old_closure;
 		err = BadAlloc;
 		goto bail;
 	    }
