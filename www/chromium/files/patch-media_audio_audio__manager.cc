--- media/audio/audio_manager.cc.orig	2017-04-19 19:06:35 UTC
+++ media/audio/audio_manager.cc
@@ -93,7 +93,7 @@ class AudioManagerHelper : public base::
   }
 #endif
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_FREEBSD)
   void set_app_name(const std::string& app_name) { app_name_ = app_name; }
   const std::string& app_name() const { return app_name_; }
 #endif
@@ -227,7 +227,7 @@ class AudioManagerHelper : public base::
   std::unique_ptr<base::win::ScopedCOMInitializer> com_initializer_for_testing_;
 #endif
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_FREEBSD)
   std::string app_name_;
 #endif
 
@@ -342,7 +342,7 @@ void AudioManager::StartHangMonitorIfNee
   GetHelper()->StartHangTimer(std::move(task_runner));
 }
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_FREEBSD)
 // static
 void AudioManager::SetGlobalAppName(const std::string& app_name) {
   GetHelper()->set_app_name(app_name);
