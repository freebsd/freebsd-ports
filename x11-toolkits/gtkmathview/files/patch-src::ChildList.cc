--- src/ChildList.cc.orig	Wed Jul 23 16:15:50 2003
+++ src/ChildList.cc	Wed Jul 23 16:17:12 2003
@@ -20,6 +20,9 @@
 // http://www.cs.unibo.it/helm/mml-widget, or send a mail to
 // <luca.padovani@cs.unibo.it>
 
+#ifdef __FreeBSD__
+#include <assert.h>
+#endif
 #include <config.h>
 
 #include "ChildList.hh"
