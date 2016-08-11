--- chrome/browser/diagnostics/diagnostics_writer.h.orig	2016-05-11 19:02:14 UTC
+++ chrome/browser/diagnostics/diagnostics_writer.h
@@ -18,7 +18,7 @@ class DiagnosticsWriter : public Diagnos
  public:
   // The type of formatting done by this writer.
   enum FormatType {
-    MACHINE,
+    THEMACHINE,
     LOG,
     HUMAN
   };
