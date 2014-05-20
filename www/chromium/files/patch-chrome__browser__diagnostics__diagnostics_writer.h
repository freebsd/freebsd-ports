--- ./chrome/browser/diagnostics/diagnostics_writer.h.orig	2014-04-30 22:42:03.000000000 +0200
+++ ./chrome/browser/diagnostics/diagnostics_writer.h	2014-05-04 14:38:46.000000000 +0200
@@ -18,7 +18,7 @@
  public:
   // The type of formatting done by this writer.
   enum FormatType {
-    MACHINE,
+    THEMACHINE,
     LOG,
     HUMAN
   };
