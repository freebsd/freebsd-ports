commit 5900b14a2bf367203f6d417bc51b59ab5ecc2129
Author: Raphael Kubo da Costa <rakuco@FreeBSD.org>
Date:   Sun Mar 2 13:26:18 2014 +0200

    qt4 immodule: Add missing <clocale> include.
    
    * qt4/immodule/plugin.cpp
      - Stop relying on implicit includes that may not always work and
        explicitly include <clocale> for the setlocale(3) call.

diff --git a/qt4/immodule/plugin.cpp b/qt4/immodule/plugin.cpp
index cb5863a..be2b9f2 100644
--- qt4/immodule/plugin.cpp
+++ qt4/immodule/plugin.cpp
@@ -34,6 +34,8 @@
 
 #include "plugin.h"
 
+#include <clocale>
+
 #include <QtCore/QStringList>
 #ifdef Q_WS_X11
 # include <QtGui/QX11Info>
