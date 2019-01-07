--- chrome/browser/diagnostics/diagnostics_writer.h.orig	2019-01-03 21:12:30.399407000 +0100
+++ chrome/browser/diagnostics/diagnostics_writer.h	2019-01-03 21:12:49.905049000 +0100
@@ -15,6 +15,8 @@
 // Console base class used internally.
 class SimpleConsole;
 
+#undef MACHINE
+
 class DiagnosticsWriter : public DiagnosticsModel::Observer {
  public:
   // The type of formatting done by this writer.
