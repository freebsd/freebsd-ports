--- Qt/Core/pqServerConfiguration.cxx.orig	2022-03-11 22:19:30 UTC
+++ Qt/Core/pqServerConfiguration.cxx
@@ -212,7 +212,7 @@ vtkPVXMLElement* pqServerConfiguration::startupXML() c
 //-----------------------------------------------------------------------------
 QString pqServerConfiguration::termCommand()
 {
-#if defined(__linux__)
+#if defined(__linux__) || defined(__FreeBSD__)
   // Based on i3 code
   // https://github.com/i3/i3/blob/next/i3-sensible-terminal
   QStringList termNames = { qgetenv("TERMINAL"), "x-terminal-emulator", "urxvt", "rxvt", "termit",
