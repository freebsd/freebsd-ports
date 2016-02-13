--- src/QGlib/connectimpl.h.orig	2013-10-14 08:44:40 UTC
+++ src/QGlib/connectimpl.h
@@ -26,7 +26,9 @@
 # include "refpointer.h"
 # include <QtCore/QList>
 # include <stdexcept>
+#ifndef Q_MOC_RUN
 # include <boost/type_traits.hpp>
+#endif
 
 
 namespace QGlib {
