--- chrome/browser/diagnostics/diagnostics_writer.h.orig	2017-06-05 19:03:02 UTC
+++ chrome/browser/diagnostics/diagnostics_writer.h
@@ -19,7 +19,7 @@ class DiagnosticsWriter : public DiagnosticsModel::Obs
  public:
   // The type of formatting done by this writer.
   enum FormatType {
-    MACHINE,
+    THEMACHINE,
     LOG,
     HUMAN
   };
