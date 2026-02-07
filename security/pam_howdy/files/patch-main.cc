--- main.cc.orig	2023-03-08 16:41:32 UTC
+++ main.cc
@@ -35,13 +35,25 @@
 #include <INIReader.h>
 
 #include <security/pam_appl.h>
+
+#ifndef __FreeBSD__
 #include <security/pam_ext.h>
+#else
+#include <sys/types.h>
+#include <security/pam_appl.h>
+#endif
+
 #include <security/pam_modules.h>
 
+
 #include "enter_device.hh"
 #include "main.hh"
 #include "optional_task.hh"
 
+#ifdef __FreeBSD__
+#define euidaccess eaccess
+#endif
+
 const auto DEFAULT_TIMEOUT =
     std::chrono::duration<int, std::chrono::milliseconds::period>(100);
 const auto MAX_RETRIES = 5;
@@ -229,7 +241,7 @@ auto identify(pam_handle_t *pamh, int flags, int argc,
 
   // Wrap the PAM conversation function in our own, easier function
   auto conv_function = [conv](int msg_type, const char *msg_str) {
-    const struct pam_message msg = {.msg_style = msg_type, .msg = msg_str};
+    const struct pam_message msg = {.msg_style = msg_type, .msg = const_cast<char *>(msg_str)};
     const struct pam_message *msgp = &msg;
 
     struct pam_response res = {};
