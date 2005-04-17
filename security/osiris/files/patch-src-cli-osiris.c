--- src/cli/osiris.c.orig	Tue Apr  5 14:37:58 2005
+++ src/cli/osiris.c	Sun Apr 17 15:47:40 2005
@@ -2985,11 +2985,13 @@
 
     if( filters == NULL )
     {
+	OSI_CMP_FILTER *f;
+
         filters = list_new();
 
         /* add a comment filter. */
 
-        OSI_CMP_FILTER *f = osi_malloc( sizeof(OSI_CMP_FILTER) );
+        f = osi_malloc( sizeof(OSI_CMP_FILTER) );
         osi_strlcpy( f->exclude, CMP_FILTER_COMMENT, sizeof(f->exclude) );
         list_add( filters, f ); 
     }
