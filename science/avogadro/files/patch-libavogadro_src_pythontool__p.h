--- libavogadro/src/pythontool_p.h.orig	2013-12-06 15:50:04 UTC
+++ libavogadro/src/pythontool_p.h
@@ -27,7 +27,9 @@
 
 #include <avogadro/global.h>
 #include <avogadro/tool.h>
+#ifndef Q_MOC_RUN
 #include <boost/python.hpp>
+#endif
 
 #include <QObject>
 #include <QAction>
