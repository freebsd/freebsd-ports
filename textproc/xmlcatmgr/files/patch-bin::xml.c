--- bin/xml.c.orig	Tue Dec 23 11:27:37 2003
+++ bin/xml.c	Thu Jan 15 00:31:14 2004
@@ -270,7 +270,6 @@
 
     if (search_entry(XMLDOC_ROOT(c), orig) != NULL) {
         warnx("entry already exists for `%s'", orig);
-        return false;
     }
 
     xn = xmlnode_new(XMLNODE_TYPE_ELEMENT, strdup(type));
