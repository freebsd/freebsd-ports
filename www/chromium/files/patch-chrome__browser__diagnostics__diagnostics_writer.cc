--- chrome/browser/diagnostics/diagnostics_writer.cc.orig	2014-10-10 08:54:10 UTC
+++ chrome/browser/diagnostics/diagnostics_writer.cc
@@ -266,7 +266,7 @@
       console_->SetColor(color);
       console_->Write(base::ASCIIToUTF16(result));
     }
-    if (format_ == MACHINE) {
+    if (format_ == THEMACHINE) {
       return WriteInfoLine(base::StringPrintf(
           "%03d %s (%s)", outcome_code, id.c_str(), extra.c_str()));
     } else {
