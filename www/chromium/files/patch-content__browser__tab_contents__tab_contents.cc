--- content/browser/tab_contents/tab_contents.cc.orig	2010-12-16 02:11:56.000000000 +0100
+++ content/browser/tab_contents/tab_contents.cc	2010-12-20 20:15:08.000000000 +0100
@@ -407,7 +407,7 @@
                  NotificationService::AllSources());
   registrar_.Add(this, NotificationType::RENDER_WIDGET_HOST_DESTROYED,
                  NotificationService::AllSources());
-#if defined(OS_LINUX)
+#if defined(TOOLKIT_GTK)
   registrar_.Add(this, NotificationType::BROWSER_THEME_CHANGED,
                  NotificationService::AllSources());
 #endif
@@ -3181,7 +3181,7 @@
       break;
     }
 
-#if defined(OS_LINUX)
+#if defined(TOOLKIT_GTK)
     case NotificationType::BROWSER_THEME_CHANGED: {
       renderer_preferences_util::UpdateFromSystemSettings(
           &renderer_preferences_, profile());
