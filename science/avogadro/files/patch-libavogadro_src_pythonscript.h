--- libavogadro/src/pythonscript.h.orig	2013-12-06 15:50:04 UTC
+++ libavogadro/src/pythonscript.h
@@ -27,7 +27,9 @@
 #define PYTHONSCRIPT_H
 
 #include <avogadro/global.h>
+#ifndef Q_MOC_RUN
 #include <boost/python.hpp>
+#endif
 
 #include "pythonerror.h"
 
