--- src/be20_api/dfxml_cpp/src/dfxml_writer.h.orig	2023-07-02 09:24:33 UTC
+++ src/be20_api/dfxml_cpp/src/dfxml_writer.h
@@ -96,6 +96,10 @@
 #include <uuid/uuid.h>
 #endif
 
+#ifdef HAVE_EXIV2
+#include <exiv2/exiv2.hpp>
+#endif
+
 #include "cpuid.h"
 
 class dfxml_writer {
