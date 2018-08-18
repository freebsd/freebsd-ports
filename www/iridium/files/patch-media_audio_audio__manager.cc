--- media/audio/audio_manager.cc.orig	2017-12-15 02:04:21.000000000 +0100
+++ media/audio/audio_manager.cc	2017-12-24 17:10:24.736979000 +0100
@@ -94,7 +94,7 @@
   }
 #endif
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   void set_app_name(const std::string& app_name) { app_name_ = app_name; }
   const std::string& app_name() const { return app_name_; }
 #endif
@@ -229,7 +229,7 @@
   std::unique_ptr<base::win::ScopedCOMInitializer> com_initializer_for_testing_;
 #endif
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   std::string app_name_;
 #endif
 
@@ -313,7 +313,7 @@
   GetHelper()->StartHangTimer(std::move(task_runner));
 }
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 // static
 void AudioManager::SetGlobalAppName(const std::string& app_name) {
   GetHelper()->set_app_name(app_name);
