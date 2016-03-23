--- src/QGlib/connect.h.orig	2013-10-14 08:44:40 UTC
+++ src/QGlib/connect.h
@@ -25,8 +25,11 @@
 #include <QtCore/QSharedPointer>
 #include <QtCore/QFlags>
 #include <QtCore/QHash>
+
+#ifndef Q_MOC_RUN
 #include <boost/type_traits.hpp>
 #include <boost/utility/enable_if.hpp>
+#endif
 
 namespace QGlib {
 
