--- chrome/browser/ui/views/extensions/extension_popup.cc.orig	2011-04-15 11:01:45.000000000 +0300
+++ chrome/browser/ui/views/extensions/extension_popup.cc	2011-04-15 23:02:00.445641973 +0300
@@ -1,4 +1,4 @@
-// Copyright (c) 2011 The Chromium Authors. All rights reserved.
+f// Copyright (c) 2011 The Chromium Authors. All rights reserved.
 // Use of this source code is governed by a BSD-style license that can be
 // found in the LICENSE file.
 
@@ -23,7 +23,7 @@
 #include "views/widget/root_view.h"
 #include "views/window/window.h"
 
-#if defined(OS_LINUX)
+#if defined(TOOLKIT_GTK)
 #include "views/widget/widget_gtk.h"
 #endif
 
@@ -94,7 +94,7 @@
 
   // The bubble chrome requires a separate window, so construct it here.
   gfx::NativeView native_window = frame->GetNativeView();
-#if defined(OS_LINUX)
+#if defined(TOOLKIT_GTK)
   border_widget_ = new views::WidgetGtk(views::WidgetGtk::TYPE_WINDOW);
   static_cast<views::WidgetGtk*>(border_widget_)->MakeTransparent();
   static_cast<views::WidgetGtk*>(border_widget_)->make_transient_to_parent();
