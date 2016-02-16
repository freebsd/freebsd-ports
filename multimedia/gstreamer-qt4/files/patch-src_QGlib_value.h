--- src/QGlib/value.h.orig	2013-10-14 08:44:40 UTC
+++ src/QGlib/value.h
@@ -23,8 +23,10 @@
 #include "type.h"
 #include "refpointer.h"
 #include "error.h"
+#ifndef Q_MOC_RUN
 #include <boost/mpl/if.hpp>
 #include <boost/type_traits.hpp>
+#endif
 #include <stdexcept>
 #include <QtCore/QString>
 #include <QtCore/QDebug>
