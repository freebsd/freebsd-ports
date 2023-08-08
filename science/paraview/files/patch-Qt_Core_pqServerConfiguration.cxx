--- Qt/Core/pqServerConfiguration.cxx.orig	2022-11-14 01:44:43 UTC
+++ Qt/Core/pqServerConfiguration.cxx
@@ -229,7 +229,7 @@ QString pqServerConfiguration::termCommand()
 //-----------------------------------------------------------------------------
 QString pqServerConfiguration::termCommand()
 {
-#if defined(__linux__)
+#if defined(__linux__) || defined(__FreeBSD__)
   // Based on i3 code
   // https://github.com/i3/i3/blob/next/i3-sensible-terminal
   QStringList termNames = { qgetenv("TERMINAL"), "x-terminal-emulator", "urxvt", "rxvt", "termit",
