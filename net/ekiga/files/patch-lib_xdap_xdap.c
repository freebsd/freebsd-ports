--- lib/xdap/xdap.c.orig	Tue Oct 28 21:28:24 2003
+++ lib/xdap/xdap.c	Tue Oct 28 21:49:59 2003
@@ -159,7 +159,7 @@
   xmlSAXHandler sax;
 
   memset (&sax, 0, sizeof sax);
-  sax = xmlDefaultSAXHandler;	/* Copy original handler */
+  xmlSAX2InitDefaultSAXHandler (&sax, 0);
   *oldgetent = sax.getEntity;	/* Substitute entity handling */
   if (noerr) {
     sax.error = NULL;	/* Disable errors and warnings */
