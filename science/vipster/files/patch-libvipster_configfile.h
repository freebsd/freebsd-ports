--- libvipster/configfile.h.orig	2018-12-21 06:15:43 UTC
+++ libvipster/configfile.h
@@ -27,7 +27,7 @@ bool saveConfig();
 #ifdef __EMSCRIPTEN__
 const std::string user_path{}; // not used
 const std::string user_config{}; // not used
-#elif __linux__
+#elif __linux__ || defined(__FreeBSD__)
 const std::string user_path = [](){
         auto tmp = std::getenv("XDG_CONFIG_HOME");
         return tmp == nullptr ? std::string{std::getenv("HOME")}+"/.config" : tmp;
