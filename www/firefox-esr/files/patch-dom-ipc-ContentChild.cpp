--- dom/ipc/ContentChild.cpp~
+++ dom/ipc/ContentChild.cpp
@@ -42,6 +42,7 @@
 #endif
 
 #ifdef MOZ_WIDGET_QT
+#include <unistd.h>
 #include "nsQAppInstance.h"
 #endif
 
