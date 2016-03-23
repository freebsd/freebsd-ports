--- src/QGlib/refpointer.h.orig	2013-10-14 08:44:40 UTC
+++ src/QGlib/refpointer.h
@@ -23,8 +23,10 @@
 #include "type.h"
 #include "wrap.h"
 #include <cstddef>
+#ifndef Q_MOC_RUN
 #include <boost/type_traits.hpp>
 #include <boost/utility/enable_if.hpp>
+#endif
 #include <QtCore/QHash>
 
 namespace QGlib {
