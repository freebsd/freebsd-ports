--- scribus/scribus.cpp.orig	Sat Jun 14 04:35:07 2003
+++ scribus/scribus.cpp	Sun Jun 15 19:50:27 2003
@@ -3040,7 +3040,7 @@
 void ScribusApp::slotHelpAbout()
 {
 	void *mo;
-	char *error;
+	const char *error;
 	typedef About* (*sdem)(QWidget *d);
 	sdem demo;
 	QString pfad = PREL;
@@ -4694,7 +4694,7 @@
 void ScribusApp::slotPrefsOrg()
 {
 	void *mo;
-	char *error;
+	const char *error;
 	typedef Preferences* (*sdem)(QWidget *d, preV *Vor);
 	sdem demo;
 	QString pfad = PREL;
@@ -5153,7 +5153,7 @@
 
 PSLib* ScribusApp::getPSDriver(bool psart, SCFonts &AllFonts, QMap<QString,QFont> DocFonts, CListe DocColors, bool pdf)
 {
-	char *error;
+	const char *error;
 	typedef PSLib* (*sdem)(bool psart, SCFonts &AllFonts, QMap<QString,QFont> DocFonts, CListe DocColors, bool pdf);
 	sdem demo;
 	QString pfad = PREL;
@@ -5188,7 +5188,7 @@
 bool ScribusApp::getPDFDriver(QString fn, QString nam, int Components, int frPa, int toPa, QMap<int,QPixmap> thumbs)
 {
 	bool ret = false;
-	char *error;
+	const char *error;
 	void *PDFDriver;
 	typedef bool (*sdem)(ScribusApp *plug, QString fn, QString nam, int Components, int frPa, int toPa, QMap<int,QPixmap> thumbs);
 	sdem demo;
@@ -5734,7 +5734,7 @@
 
 void ScribusApp::FinalizePlugs()
 {
-	char *error;
+	const char *error;
 	QMap<QString, PlugData>::Iterator it;
 	struct PlugData pda;
 	typedef void (*sdem2)();
@@ -5804,7 +5804,7 @@
 void ScribusApp::CallDLL(QString name)
 {
 	void *mo;
-	char *error;
+	const char *error;
 	struct PlugData pda;
 	pda = PluginMap[name];
 	typedef void (*sdem)(QWidget *d, ScribusApp *plug);
@@ -5838,7 +5838,7 @@
 bool ScribusApp::DLLName(QString name, QString *PName, int *typ, void **Zeig)
 {
 	void *mo;
-	char *error;
+	const char *error;
 	typedef QString (*sdem0)();
 	typedef int (*sdem1)();
 	typedef void (*sdem2)(QWidget *d, ScribusApp *plug);
