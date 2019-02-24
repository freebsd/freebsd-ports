--- media/audio/audio_manager.cc.orig	2019-01-30 02:18:05.000000000 +0100
+++ media/audio/audio_manager.cc	2019-02-01 10:05:43.833445000 +0100
@@ -48,7 +48,7 @@
   }
 #endif
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   void set_app_name(const std::string& app_name) { app_name_ = app_name; }
   const std::string& app_name() const { return app_name_; }
 #endif
@@ -59,7 +59,7 @@
   std::unique_ptr<base::win::ScopedCOMInitializer> com_initializer_for_testing_;
 #endif
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   std::string app_name_;
 #endif
 
@@ -128,7 +128,7 @@
   return Create(std::move(audio_thread), GetHelper()->fake_log_factory());
 }
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 // static
 void AudioManager::SetGlobalAppName(const std::string& app_name) {
   GetHelper()->set_app_name(app_name);
