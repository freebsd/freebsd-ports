--- examples/activeqt/webbrowser/webbrowser.py.orig	2009-10-29 13:37:30.000000000 +1000
+++ examples/activeqt/webbrowser/webbrowser.py	2009-10-31 18:03:38.000000000 +1000
@@ -115,7 +115,7 @@
         QtGui.QMessageBox.about(self, "About WebBrowser",
                 "This Example has been created using the ActiveQt integration into Qt Designer.\n"
                 "It demonstrates the use of QAxWidget to embed the Internet Explorer ActiveX\n"
-                "control into a Qt application."))
+                "control into a Qt application.")
 
     @QtCore.pyqtSlot()
     def on_actionAboutQt_triggered(self):
