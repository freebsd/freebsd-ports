--- chrome/test/chromedriver/server/chromedriver_server.cc.orig	2021-04-14 18:40:56 UTC
+++ chrome/test/chromedriver/server/chromedriver_server.cc
@@ -286,7 +286,7 @@ int main(int argc, char *argv[]) {
   base::AtExitManager at_exit;
   base::CommandLine* cmd_line = base::CommandLine::ForCurrentProcess();
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
   // Select the locale from the environment by passing an empty string instead
   // of the default "C" locale. This is particularly needed for the keycode
   // conversion code to work.
