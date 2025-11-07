--- core/src/lib/cli.h.orig	2025-09-02 08:09:07 UTC
+++ core/src/lib/cli.h
@@ -24,6 +24,7 @@
 #include "CLI/App.hpp"
 #include "CLI/Config.hpp"
 #include "CLI/Formatter.hpp"
+#include "CLI/ExtraValidators.hpp"
 
 void ParseBareosApp(CLI::App& app, int argc, char** argv);
 void InitCLIApp(CLI::App& app, std::string description, int fsfyear = 0);
