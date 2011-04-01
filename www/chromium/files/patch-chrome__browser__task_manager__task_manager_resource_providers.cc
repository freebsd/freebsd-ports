--- ./chrome/browser/task_manager/task_manager_resource_providers.cc.orig	2010-12-16 02:11:54.000000000 +0100
+++ ./chrome/browser/task_manager/task_manager_resource_providers.cc	2010-12-20 20:15:08.000000000 +0100
@@ -1198,7 +1198,7 @@
       default_icon_ = IconUtil::CreateSkBitmapFromHICON(icon, icon_size);
     }
   }
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_FREEBSD)
   if (!default_icon_) {
     ResourceBundle& rb = ResourceBundle::GetSharedInstance();
     default_icon_ = rb.GetBitmapNamed(IDR_PRODUCT_LOGO_16);
