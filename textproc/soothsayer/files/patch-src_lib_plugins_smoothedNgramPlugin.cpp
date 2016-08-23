--- src/lib/plugins/smoothedNgramPlugin.cpp.orig	2008-06-02 13:29:01 UTC
+++ src/lib/plugins/smoothedNgramPlugin.cpp
@@ -23,6 +23,7 @@
 
 #include "plugins/smoothedNgramPlugin.h"
 #include <sstream>
+#include <algorithm>
 
 
 SmoothedNgramPlugin::SmoothedNgramPlugin(Configuration* config, ContextTracker* ct)
