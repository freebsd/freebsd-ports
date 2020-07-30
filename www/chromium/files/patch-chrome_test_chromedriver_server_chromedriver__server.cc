--- chrome/test/chromedriver/server/chromedriver_server.cc.orig	2020-07-13 09:28:06 UTC
+++ chrome/test/chromedriver/server/chromedriver_server.cc
@@ -492,7 +492,7 @@ int main(int argc, char *argv[]) {
   base::AtExitManager at_exit;
   base::CommandLine* cmd_line = base::CommandLine::ForCurrentProcess();
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   // Select the locale from the environment by passing an empty string instead
   // of the default "C" locale. This is particularly needed for the keycode
   // conversion code to work.
