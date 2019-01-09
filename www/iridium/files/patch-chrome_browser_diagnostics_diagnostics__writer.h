--- chrome/browser/diagnostics/diagnostics_writer.h.orig	2018-05-09 21:05:37.000000000 +0200
+++ chrome/browser/diagnostics/diagnostics_writer.h	2019-01-07 21:53:10.249123000 +0100
@@ -15,6 +15,8 @@
 // Console base class used internally.
 class SimpleConsole;

+#undef MACHINE
+
 class DiagnosticsWriter : public DiagnosticsModel::Observer {
  public:
   // The type of formatting done by this writer.
