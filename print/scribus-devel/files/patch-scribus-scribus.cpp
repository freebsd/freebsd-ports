--- scribus/scribus.cpp.orig	Thu Apr 22 23:14:09 2004
+++ scribus/scribus.cpp	Thu Apr 22 23:16:00 2004
@@ -5660,7 +5660,7 @@
 void ScribusApp::slotPrefsOrg()
 {
 	void *mo;
-	char *error;
+	const char *error;
 	bool zChange = false;
 	typedef Preferences* (*sdem)(QWidget *d, preV *Vor);
 	sdem demo;
@@ -6142,7 +6142,7 @@
 bool ScribusApp::getPDFDriver(QString fn, QString nam, int Components, int frPa, int toPa, QMap<int,QPixmap> thumbs)
 {
 	bool ret = false;
-	char *error;
+	const char *error;
 	void *PDFDriver;
 	typedef bool (*sdem)(ScribusApp *plug, QString fn, QString nam, int Components, int frPa, int toPa, QMap<int,QPixmap> thumbs, QProgressBar *dia2);
 	sdem demo;
@@ -6686,7 +6686,7 @@
 		dia.setSelection(defNa);
 	if (dia.exec() == QDialog::Accepted)
 		{
-			LoadEnc = cod ? dia.TxCodeM->currentText() : "";
+			LoadEnc = cod ? dia.TxCodeM->currentText() : QString("");
 			this->repaint();
 			qApp->eventLoop()->processEvents(QEventLoop::ExcludeUserInput);
 			return dia.selectedFile();
