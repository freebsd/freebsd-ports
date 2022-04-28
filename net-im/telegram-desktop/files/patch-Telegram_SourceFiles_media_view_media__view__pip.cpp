--- Telegram/SourceFiles/media/view/media_view_pip.cpp.orig	2022-04-20 09:56:09 UTC
+++ Telegram/SourceFiles/media/view/media_view_pip.cpp
@@ -475,7 +475,7 @@ void PipPanel::setPositionDefault() {
 	const auto parentScreen = widgetScreen(_parent);
 	const auto myScreen = widgetScreen(widget());
 	if (parentScreen && myScreen && myScreen != parentScreen) {
-		widget()->setScreen(parentScreen);
+		widget()->windowHandle()->setScreen(parentScreen);
 	}
 	auto position = Position();
 	position.snapped = RectPart::Top | RectPart::Left;
