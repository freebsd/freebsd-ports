--- widget/qt/nsSound.cpp~
+++ widget/qt/nsSound.cpp
@@ -40,6 +40,7 @@
 #include <QSound>
 
 #include <string.h>
+#include <unistd.h>
 
 #include "nscore.h"
 #include "plstr.h"
