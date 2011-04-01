--- ./chrome/browser/ui/views/info_bubble.cc.orig	2010-12-16 02:11:56.000000000 +0100
+++ ./chrome/browser/ui/views/info_bubble.cc	2010-12-20 20:15:08.000000000 +0100
@@ -308,7 +308,7 @@
 
 InfoBubble::InfoBubble()
     :
-#if defined(OS_LINUX)
+#if defined(TOOLKIT_GTK)
       WidgetGtk(TYPE_WINDOW),
       border_contents_(NULL),
 #elif defined(OS_WIN)
@@ -375,7 +375,7 @@
   WidgetWin::Init(border_->GetNativeView(), gfx::Rect());
 
   SetWindowText(GetNativeView(), delegate_->accessible_name().c_str());
-#elif defined(OS_LINUX)
+#elif defined(TOOLKIT_USES_GTK)
   MakeTransparent();
   make_transient_to_parent();
   WidgetGtk::InitWithWidget(parent, gfx::Rect());
@@ -447,7 +447,7 @@
   ShowWindow(SW_SHOW);
   if (fade_in)
     FadeIn();
-#elif defined(OS_LINUX)
+#elif defined(TOOLKIT_USES_GTK)
   views::WidgetGtk::Show();
 #endif
 }
@@ -487,7 +487,7 @@
     GetRootView()->GetChildViewAt(0)->RequestFocus();
   }
 }
-#elif defined(OS_LINUX)
+#elif defined(TOOLKIT_GTK)
 void InfoBubble::IsActiveChanged() {
   if (!IsActive())
     Close();
@@ -506,7 +506,7 @@
 #if defined(OS_WIN)
   border_->Close();
   WidgetWin::Close();
-#elif defined(OS_LINUX)
+#elif defined(TOOLKIT_GTK)
   WidgetGtk::Close();
 #endif
 }
