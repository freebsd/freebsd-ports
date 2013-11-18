--- chrome/browser/diagnostics/diagnostics_writer.h.orig	2013-11-08 07:40:50.000000000 +0100
+++ chrome/browser/diagnostics/diagnostics_writer.h	2013-11-16 11:29:16.000000000 +0100
@@ -18,7 +18,7 @@
  public:
   // The type of formatting done by this writer.
   enum FormatType {
-    MACHINE,
+    THEMACHINE,
     LOG,
     HUMAN
   };
