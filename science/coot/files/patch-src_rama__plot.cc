--- src/rama_plot.cc.orig	2018-07-08 02:28:57 UTC
+++ src/rama_plot.cc
@@ -39,6 +39,8 @@
 #include <iostream>
 #include <algorithm>
 
+#include <sys/stat.h>
+
 #include <gdk/gdkkeysyms.h> // for keyboarding.
 
 #include "utils/coot-utils.hh" // int to string
