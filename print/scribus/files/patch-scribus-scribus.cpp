--- scribus/scribus.cpp.orig	Fri Jul 11 21:58:11 2003
+++ scribus/scribus.cpp	Tue Jul 15 12:40:29 2003
@@ -3051,7 +3051,7 @@
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
 	bool zChange = false;
 	typedef Preferences* (*sdem)(QWidget *d, preV *Vor);
 	sdem demo;
@@ -5156,7 +5156,7 @@
 
 PSLib* ScribusApp::getPSDriver(bool psart, SCFonts &AllFonts, QMap<QString,QFont> DocFonts, CListe DocColors, bool pdf)
 {
-	char *error;
+	const char *error;
 	typedef PSLib* (*sdem)(bool psart, SCFonts &AllFonts, QMap<QString,QFont> DocFonts, CListe DocColors, bool pdf);
 	sdem demo;
 	QString pfad = PREL;
@@ -5191,7 +5191,7 @@
 bool ScribusApp::getPDFDriver(QString fn, QString nam, int Components, int frPa, int toPa, QMap<int,QPixmap> thumbs)
 {
 	bool ret = false;
-	char *error;
+	const char *error;
 	void *PDFDriver;
 	typedef bool (*sdem)(ScribusApp *plug, QString fn, QString nam, int Components, int frPa, int toPa, QMap<int,QPixmap> thumbs);
 	sdem demo;
@@ -5738,7 +5738,7 @@
 
 void ScribusApp::FinalizePlugs()
 {
-	char *error;
+	const char *error;
 	QMap<QString, PlugData>::Iterator it;
 	struct PlugData pda;
 	typedef void (*sdem2)();
@@ -5808,7 +5808,7 @@
 void ScribusApp::CallDLL(QString name)
 {
 	void *mo;
-	char *error;
+	const char *error;
 	struct PlugData pda;
 	pda = PluginMap[name];
 	typedef void (*sdem)(QWidget *d, ScribusApp *plug);
@@ -5842,7 +5842,7 @@
 bool ScribusApp::DLLName(QString name, QString *PName, int *typ, void **Zeig)
 {
 	void *mo;
-	char *error;
+	const char *error;
 	typedef QString (*sdem0)();
 	typedef int (*sdem1)();
 	typedef void (*sdem2)(QWidget *d, ScribusApp *plug);
