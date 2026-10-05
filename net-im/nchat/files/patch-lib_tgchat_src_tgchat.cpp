--- lib/tgchat/src/tgchat.cpp.orig	2026-10-05 13:48:25 UTC
+++ lib/tgchat/src/tgchat.cpp
@@ -2616,9 +2616,9 @@ void TgChat::Impl::OnAuthStateUpdate()
 
     set_parameters->system_language_code_ = "en";
     set_parameters->device_model_ = "Desktop";
-#ifdef __linux__
+#if defined (__linux__)
     set_parameters->system_version_ = "Linux";
-#elif __APPLE__
+#elif defined(__APPLE__)
     set_parameters->system_version_ = "Darwin";
 #else
     set_parameters->system_version_ = "Unknown";
