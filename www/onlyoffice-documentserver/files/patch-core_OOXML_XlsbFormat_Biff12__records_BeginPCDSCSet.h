--- core/OOXML/XlsbFormat/Biff12_records/BeginPCDSCSet.h.orig	2024-01-22 10:44:38 UTC
+++ core/OOXML/XlsbFormat/Biff12_records/BeginPCDSCSet.h
@@ -37,6 +37,8 @@
 #include "../../../MsBinaryFile/XlsFile/Format/Logic/Biff_structures/BIFF12/RelID.h"
 #include "../../../MsBinaryFile/XlsFile/Format/Logic/Biff_structures/BIFF12/CellRangeRef.h"
 
+#include <array>
+
 namespace XLSB
 {
     // Logical representation of BrtBeginPCDSCSet record in BIFF12
