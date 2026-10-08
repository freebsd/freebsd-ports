--- Qt/Core/pqServerConfiguration.cxx.orig	2026-09-29 17:25:09 UTC
+++ Qt/Core/pqServerConfiguration.cxx
@@ -201,7 +201,7 @@ QString pqServerConfiguration::termCommand()
 //-----------------------------------------------------------------------------
 QString pqServerConfiguration::termCommand()
 {
-#if defined(__linux__)
+#if defined(__linux__) || defined(__FreeBSD__)
   // Based on i3 code
   // https://github.com/i3/i3/blob/next/i3-sensible-terminal
   QStringList termNames = { qgetenv("TERMINAL"), "x-terminal-emulator", "urxvt", "rxvt", "termit",
