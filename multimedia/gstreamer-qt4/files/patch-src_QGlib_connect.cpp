--- src/QGlib/connect.cpp.orig	2013-10-14 08:44:40 UTC
+++ src/QGlib/connect.cpp
@@ -20,10 +20,13 @@
 #include <glib-object.h>
 #include <QtCore/QHash>
 #include <QtCore/QMutex>
+
+#ifndef Q_MOC_RUN
 #include <boost/multi_index_container.hpp>
 #include <boost/multi_index/sequenced_index.hpp>
 #include <boost/multi_index/ordered_index.hpp>
 #include <boost/multi_index/member.hpp>
+#endif
 
 namespace QGlib {
 namespace Private {
