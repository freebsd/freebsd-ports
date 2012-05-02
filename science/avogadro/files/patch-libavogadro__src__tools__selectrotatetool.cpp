--- ./libavogadro/src/tools/selectrotatetool.cpp.orig	2011-04-25 05:22:18.000000000 +0000
+++ ./libavogadro/src/tools/selectrotatetool.cpp	2012-05-01 22:05:46.053696029 +0000
@@ -44,6 +44,8 @@
 #include <QComboBox>
 #include <QDebug>
 
+#include <GL/glu.h>
+
 using namespace std;
 using namespace OpenBabel;
 using namespace Eigen;
