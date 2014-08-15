--- ./chrome/browser/diagnostics/diagnostics_writer.h.orig	2014-08-12 21:01:46.000000000 +0200
+++ ./chrome/browser/diagnostics/diagnostics_writer.h	2014-08-13 09:56:56.000000000 +0200
@@ -18,7 +18,7 @@
  public:
   // The type of formatting done by this writer.
   enum FormatType {
-    MACHINE,
+    THEMACHINE,
     LOG,
     HUMAN
   };
