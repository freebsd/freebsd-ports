--- ui/views/mus/aura_init.h.orig	2017-03-09 20:04:49 UTC
+++ ui/views/mus/aura_init.h
@@ -68,7 +68,7 @@ class VIEWS_MUS_EXPORT AuraInit {
  private:
   void InitializeResources(service_manager::Connector* connector);
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   sk_sp<font_service::FontLoader> font_loader_;
 #endif
 
