--- libavogadro/src/pythonextension_p.h.orig	2013-12-06 15:50:04 UTC
+++ libavogadro/src/pythonextension_p.h
@@ -29,7 +29,9 @@
 #include <avogadro/extension.h>
 #include <avogadro/primitive.h>
 #include <avogadro/glwidget.h>
+#ifndef Q_MOC_RUN
 #include <boost/python.hpp>
+#endif
 
 #include <QWidget>
 #include <QList>
