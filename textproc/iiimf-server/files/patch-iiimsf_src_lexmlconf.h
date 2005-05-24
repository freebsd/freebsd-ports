--- iiimsf/src/lexmlconf.h.orig	Fri Apr 22 16:53:03 2005
+++ iiimsf/src/lexmlconf.h	Mon May 16 19:00:59 2005
@@ -63,6 +63,7 @@
 struct _IIIMLEInfoList {
 	IIIMLEInfo     *data;
 	IIIMLEInfoList *next;
+	IIIMLEInfoList *prev;
 };
 struct _IIIMLEInfo {
 	char       *language;
