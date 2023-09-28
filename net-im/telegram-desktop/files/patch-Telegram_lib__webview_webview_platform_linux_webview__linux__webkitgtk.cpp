--- Telegram/lib_webview/webview/platform/linux/webview_linux_webkitgtk.cpp.orig	2023-09-22 07:01:01 UTC
+++ Telegram/lib_webview/webview/platform/linux/webview_linux_webkitgtk.cpp
@@ -33,6 +33,13 @@ constexpr auto kHelperObjectPath = "/org/desktop_app/G
 constexpr auto kMasterObjectPath = "/org/desktop_app/GtkIntegration/Webview/Master";
 constexpr auto kHelperObjectPath = "/org/desktop_app/GtkIntegration/Webview/Helper";
 
+void (* const SetGraphicsApi)(QSGRendererInterface::GraphicsApi) =
+#if QT_VERSION >= QT_VERSION_CHECK(6, 0, 0)
+	QQuickWindow::setGraphicsApi;
+#else // Qt >= 6.0.0
+	QQuickWindow::setSceneGraphBackend;
+#endif // Qt < 6.0.0
+
 std::string SocketPath;
 
 inline std::string SocketPathToDBusAddress(const std::string &socketPath) {
@@ -116,12 +123,10 @@ Instance::Instance(bool remoting)
 					Ui::GL::CheckCapabilities(nullptr));
 				switch (backend) {
 				case Ui::GL::Backend::Raster:
-					QQuickWindow::setGraphicsApi(
-						QSGRendererInterface::Software);
+					SetGraphicsApi(QSGRendererInterface::Software);
 					break;
 				case Ui::GL::Backend::OpenGL:
-					QQuickWindow::setGraphicsApi(
-						QSGRendererInterface::OpenGL);
+					SetGraphicsApi(QSGRendererInterface::OpenGL);
 					break;
 				}
 				return true;
@@ -637,11 +642,11 @@ void Instance::setOpaqueBg(QColor opaqueBg) {
 		return;
 	}
 
-	GdkRGBA rgba{
-		opaqueBg.redF(),
-		opaqueBg.greenF(),
-		opaqueBg.blueF(),
-		opaqueBg.alphaF(),
+	const GdkRGBA rgba{
+		float(opaqueBg.redF()),
+		float(opaqueBg.greenF()),
+		float(opaqueBg.blueF()),
+		float(opaqueBg.alphaF()),
 	};
 	webkit_web_view_set_background_color(
 		WEBKIT_WEB_VIEW(_webview),
