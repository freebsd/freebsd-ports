https://github.com/ammen99/wf-recorder/pull/4

--- src/main.cpp.orig	2019-03-10 06:36:05 UTC
+++ src/main.cpp
@@ -275,7 +275,7 @@ static void write_loop(std::string name, int32_t width
 {
     /* Ignore SIGINT, main loop is responsible for the exit_main_loop signal */
     sigset_t sigset;
-    sigisemptyset(&sigset);
+    sigemptyset(&sigset);
     sigaddset(&sigset, SIGINT);
     pthread_sigmask(SIG_BLOCK, &sigset, NULL);
 
