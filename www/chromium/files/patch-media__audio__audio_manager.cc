--- media/audio/audio_manager.cc.orig	2015-12-05 21:00:28.652308000 +0100
+++ media/audio/audio_manager.cc	2015-12-05 21:00:59.340983000 +0100
@@ -157,7 +157,7 @@
   }
 #endif
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_FREEBSD)
   void set_app_name(const std::string& app_name) {
     app_name_ = app_name;
   }
@@ -184,7 +184,7 @@
   scoped_ptr<base::win::ScopedCOMInitializer> com_initializer_for_testing_;
 #endif
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_FREEBSD)
   std::string app_name_;
 #endif
 
@@ -267,7 +267,7 @@
 #endif
 }
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_FREEBSD)
 // static
 void AudioManager::SetGlobalAppName(const std::string& app_name) {
   g_helper.Pointer()->set_app_name(app_name);
