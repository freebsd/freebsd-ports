--- src/GladeHelper.hh.orig	Sat Feb 28 22:30:58 2004
+++ src/GladeHelper.hh	Sat Feb 28 22:30:58 2004
@@ -24,6 +24,7 @@
 #include <glade/glade-xml.h>
 #include <gtk/gtkobject.h>
 #include <gtk--/base.h>
+#include <iostream.h>
 
 template<class T> T* getWidgetPtr(GladeXML* g, const char* name)
 {
