--- src/xmlparse.c.orig	Wed Apr  5 08:53:55 2006
+++ src/xmlparse.c	Wed Apr 19 10:35:15 2006
@@ -51,7 +51,7 @@
 #include "xmlparse.h"
 
 #define malloc g_malloc
-#define calloc(n,s) g_malloc0(n * s)
+#define calloc(n,s) g_malloc0((n) * (s))
 
 #define TAGSTACK_INCR 20
 
@@ -162,10 +162,11 @@
     e->attrs = NULL;
     if (attrs) {
 	for (i = 0 ; attrs[i] ; i++) ;
-	e->attrs = calloc(i, sizeof(xmlChar *));
+	e->attrs = calloc(i+1, sizeof(xmlChar *));
 	for (i = 0 ; attrs[i] ; i++) {
 	    e->attrs[i] = (guchar*)strdup((gchar*)attrs[i]);
 	}
+	e->attrs[i] = NULL;
     }
     
     /* lookup handler */
