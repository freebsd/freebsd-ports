--- libavogadro/src/pythoninterpreter.h.orig	2013-12-06 15:50:04 UTC
+++ libavogadro/src/pythoninterpreter.h
@@ -26,7 +26,9 @@
 #define PYTHONINTERPRETER_H
 
 #include <avogadro/global.h>
+#ifndef Q_MOC_RUN
 #include <boost/python.hpp>
+#endif
 #include <avogadro/primitive.h>
 #include <QString>
 
