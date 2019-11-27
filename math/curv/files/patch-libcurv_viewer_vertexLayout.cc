--- libcurv/viewer/vertexLayout.cc.orig	2019-10-22 18:23:57 UTC
+++ libcurv/viewer/vertexLayout.cc
@@ -1,5 +1,6 @@
 #include "vertexLayout.h"
 #include "text.h"
+#include <sys/types.h>
 
 std::map<GLint, GLuint> VertexLayout::s_enabledAttribs = std::map<GLint, GLuint>();
 
