--- qutebrowser/browser/webengine/webview.py.orig	2018-06-10 13:42:47 UTC
+++ qutebrowser/browser/webengine/webview.py
@@ -24,7 +24,6 @@ import functools
 import sip
 from PyQt5.QtCore import pyqtSignal, pyqtSlot, QUrl, PYQT_VERSION
 from PyQt5.QtGui import QPalette
-from PyQt5.QtQuickWidgets import QQuickWidget
 from PyQt5.QtWebEngineWidgets import (QWebEngineView, QWebEnginePage,
                                       QWebEngineScript)
 
@@ -72,9 +71,10 @@ class WebEngineView(QWebEngineView):
         if proxy is not None:
             return proxy
 
-        # This should only find the RenderWidgetHostViewQtDelegateWidget,
-        # but not e.g. a QMenu
-        children = self.findChildren(QQuickWidget)
+        # We don't want e.g. a QMenu.
+        rwhv_class = 'QtWebEngineCore::RenderWidgetHostViewQtDelegateWidget'
+        children = [child for child in self.findChildren(QWidget)
+                    if child.inherits(rwhv_class)]
 
         if not children:
             return None
