--- ./chrome/browser/diagnostics/diagnostics_writer.h.orig	2014-08-20 21:02:00.000000000 +0200
+++ ./chrome/browser/diagnostics/diagnostics_writer.h	2014-08-22 15:06:24.000000000 +0200
@@ -18,7 +18,7 @@
  public:
   // The type of formatting done by this writer.
   enum FormatType {
-    MACHINE,
+    THEMACHINE,
     LOG,
     HUMAN
   };
