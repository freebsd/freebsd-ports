--- Telegram/lib_ui/ui/rp_widget.h.orig	2022-04-20 07:41:10 UTC
+++ Telegram/lib_ui/ui/rp_widget.h
@@ -206,6 +206,10 @@ class TWidget : public TWidgetHelper<QWidget> { (publi
 		return rectNoMargins().size();
 	}
 
+#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
+	bool setScreen(QScreen*);
+#endif  // Qt < 6.0.0
+
 	// Updates the area that is visible inside the scroll container.
 	void setVisibleTopBottom(int visibleTop, int visibleBottom) {
 		auto max = height();
