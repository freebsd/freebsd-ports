--- app/ui/humanstrings.cpp.orig	2026-03-01 03:26:05 UTC
+++ app/ui/humanstrings.cpp
@@ -60,7 +60,7 @@ QString HumanStrings::FormatToString(const SampleForma
     break;
   }
 
-  return QCoreApplication::translate("AudioParams", "Unknown (0x%1)").arg(f, 1, 16);
+  return QCoreApplication::translate("AudioParams", "Unknown (0x%1)").arg(static_cast<int>(f), 1, 16);
 }
 
 }
