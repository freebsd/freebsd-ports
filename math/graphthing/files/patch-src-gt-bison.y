--- src/gt-bison.y.orig	Fri Oct 25 16:16:17 2002
+++ src/gt-bison.y	Fri Oct 25 16:16:37 2002
@@ -1,6 +1,7 @@
 %{
 #include <stdio.h>
 #include <string.h>
+#include <iostream>
 #include "edge.h"
 #include "graph.h"
 #include "vertex.h"
