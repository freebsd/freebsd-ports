--- dom.h.orig	2002-02-09 05:12:46 UTC
+++ dom.h
@@ -1,6 +1,8 @@
 #ifndef __LIBXML_DOM_H__
 #define __LIBXML_DOM_H__
 
+#include <libxml/xmlstring.h>
+
 xmlChar*
 domEncodeString( const char *encoding, const char *string );
 char*
