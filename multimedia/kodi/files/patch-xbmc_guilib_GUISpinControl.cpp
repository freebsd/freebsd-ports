--- xbmc/guilib/GUISpinControl.cpp.orig	2016-02-20 15:21:19 UTC
+++ xbmc/guilib/GUISpinControl.cpp
@@ -22,6 +22,7 @@
 #include "input/Key.h"
 #include "utils/StringUtils.h"
 #include <stdio.h>
+#include <stdlib.h>
 
 #define SPIN_BUTTON_DOWN 1
 #define SPIN_BUTTON_UP   2
