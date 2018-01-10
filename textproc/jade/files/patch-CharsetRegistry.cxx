--- lib/CharsetRegistry.cxx.orig	Sat Jul 31 17:03:07 2004
+++ lib/CharsetRegistry.cxx	Sat Jul 31 17:05:46 2004
@@ -164,6 +164,9 @@
 static const unsigned short iso8859_9[] = {
 #include "iso8859-9.h"
 };
+static const unsigned short koi8_r[] = {
+#include "koi8-r.h"
+};
 static const unsigned short iso646_jis_G0[] = {
 #include "iso646-jis.h"
 };
@@ -203,6 +206,7 @@
   { CharsetRegistry::ISO8859_7, iso8859_7 },
   { CharsetRegistry::ISO8859_8, iso8859_8 },
   { CharsetRegistry::ISO8859_9, iso8859_9 },
+  { CharsetRegistry::KOI8_R, koi8_r },
   { CharsetRegistry::ISO646_JIS_G0, iso646_jis_G0 },
   { CharsetRegistry::JIS0201, jis0201 },
 #ifdef SP_MULTI_BYTE
