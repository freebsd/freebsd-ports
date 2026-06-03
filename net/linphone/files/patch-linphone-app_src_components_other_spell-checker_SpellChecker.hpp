--- linphone-app/src/components/other/spell-checker/SpellChecker.hpp.orig	2025-12-26 08:14:55 UTC
+++ linphone-app/src/components/other/spell-checker/SpellChecker.hpp
@@ -38,7 +38,7 @@
 #include "components/core/CoreManager.hpp"
 #include "components/settings/SettingsModel.hpp"
 
-#ifdef __linux__
+#if defined(__linux__) || defined(__FreeBSD__)
 #include <thread>
 #endif
 
@@ -113,7 +113,7 @@ signals: (private)
 #endif
 	
 // ISpell linux
-#ifdef __linux__
+#if defined(__linux__) || defined(__FreeBSD__)
 	static int gISpell_sc_read_fd;
 	static int gISpell_sc_write_fd;
 	static int gISpell_app_read_fd;
