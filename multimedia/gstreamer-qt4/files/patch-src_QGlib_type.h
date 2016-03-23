--- src/QGlib/type.h.orig	2013-10-14 08:44:40 UTC
+++ src/QGlib/type.h
@@ -21,7 +21,9 @@
 
 #include "global.h"
 #include <QtCore/QList>
+#ifndef Q_MOC_RUN
 #include <boost/mpl/if.hpp>
+#endif
 
 /*
  * This is a re-definition of GType inside the QGlib::Private namespace.
