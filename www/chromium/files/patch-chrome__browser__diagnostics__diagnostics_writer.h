--- ./chrome/browser/diagnostics/diagnostics_writer.h.orig	2014-04-24 22:35:10.000000000 +0200
+++ ./chrome/browser/diagnostics/diagnostics_writer.h	2014-04-24 23:23:42.000000000 +0200
@@ -18,7 +18,7 @@
  public:
   // The type of formatting done by this writer.
   enum FormatType {
-    MACHINE,
+    THEMACHINE,
     LOG,
     HUMAN
   };
