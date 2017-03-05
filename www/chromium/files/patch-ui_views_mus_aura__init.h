--- ui/views/mus/aura_init.h.orig	2017-02-02 02:03:13 UTC
+++ ui/views/mus/aura_init.h
@@ -64,7 +64,7 @@ class VIEWS_MUS_EXPORT AuraInit {
  private:
   void InitializeResources(service_manager::Connector* connector);
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   sk_sp<font_service::FontLoader> font_loader_;
 #endif
 
