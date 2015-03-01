--- xbmc/filesystem/iso9660.cpp.orig	2014-12-20 16:28:43 UTC
+++ xbmc/filesystem/iso9660.cpp
@@ -52,6 +52,7 @@ ISO9660
 #include "storage/DetectDVDType.h"  // for MODE2_DATA_SIZE etc.
 #endif
 #include <cdio/bytesex.h>
+#include <stdlib.h>
 //#define _DEBUG_OUTPUT 1
 
 static CCriticalSection m_critSection;
