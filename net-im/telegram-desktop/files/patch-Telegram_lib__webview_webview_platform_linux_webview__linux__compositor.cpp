--- Telegram/lib_webview/webview/platform/linux/webview_linux_compositor.cpp.orig	2023-09-22 07:01:01 UTC
+++ Telegram/lib_webview/webview/platform/linux/webview_linux_compositor.cpp
@@ -199,8 +199,9 @@ Compositor::Compositor()
 		const auto output = new Output(this, xdgSurface);
 
 		output->chrome().surfaceCompleted() | rpl::start_with_next([=] {
-			const auto parent = qvariant_cast<Output*>(
-				popup->parentXdgSurface()->property("output"))->window();
+			const auto parent = (*static_cast<Output * const *>(
+				popup->parentXdgSurface()->property("output").constData()
+			))->window();
 			if (_private->widget
 					&& parent == _private->widget->quickWindow()) {
 				output->window()->setTransientParent(
