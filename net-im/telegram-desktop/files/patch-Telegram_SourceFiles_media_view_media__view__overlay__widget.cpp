--- Telegram/SourceFiles/media/view/media_view_overlay_widget.cpp.orig	2022-04-20 09:56:09 UTC
+++ Telegram/SourceFiles/media/view/media_view_overlay_widget.cpp
@@ -499,7 +499,7 @@ void OverlayWidget::moveToScreen(bool inMove) {
 		DEBUG_LOG(("Viewer Pos: Currently on screen %1, moving to screen %2")
 			.arg(screenList.indexOf(myScreen))
 			.arg(screenList.indexOf(activeWindowScreen)));
-		_widget->setScreen(activeWindowScreen);
+		window()->setScreen(activeWindowScreen);
 		DEBUG_LOG(("Viewer Pos: New actual screen: %1")
 			.arg(screenList.indexOf(_widget->screen())));
 	}
