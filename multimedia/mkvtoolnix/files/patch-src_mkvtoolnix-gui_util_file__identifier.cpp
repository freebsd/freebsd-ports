--- src/mkvtoolnix-gui/util/file_identifier.cpp.orig	2016-07-14 05:51:59 UTC
+++ src/mkvtoolnix-gui/util/file_identifier.cpp
@@ -1,5 +1,7 @@
 #include "common/common_pch.h"
 
+#include <cmath>
+
 #include <QDebug>
 #include <QDir>
 #include <QFile>
@@ -288,8 +290,8 @@ FileIdentifier::addProbeRangePercentageA
   if (probeRangePercentage <= 0)
     return;
 
-  auto integerPart = static_cast<unsigned int>(std::round(probeRangePercentage * 100)) / 100;
-  auto decimalPart = static_cast<unsigned int>(std::round(probeRangePercentage * 100)) % 100;
+  auto integerPart = static_cast<unsigned int>(round(probeRangePercentage * 100)) / 100;
+  auto decimalPart = static_cast<unsigned int>(round(probeRangePercentage * 100)) % 100;
 
   if (integerPart >= 100)
     return;
