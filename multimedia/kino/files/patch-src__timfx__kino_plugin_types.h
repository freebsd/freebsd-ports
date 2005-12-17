--- src/timfx/kino_plugin_types.h.orig	Mon Oct  3 05:13:13 2005
+++ src/timfx/kino_plugin_types.h	Sat Dec 17 22:00:05 2005
@@ -2,13 +2,13 @@
 #define KINO_PLUGIN_TYPES_H
 
 #include "kino_plugin_utility.h"
+#include <sys/types.h>
 
 #include <algorithm>
 #include <cmath>
 #include <functional>
 #include <iostream>
 #include <string>
-#include <stdint.h>
 
 namespace kino
 {
