--- scribus/scribus.cpp.orig	Wed Oct 30 14:03:20 2002
+++ scribus/scribus.cpp	Wed Oct 30 16:08:14 2002
@@ -2357,7 +2357,7 @@
 void ScribusApp::slotHelpAbout()
 {
 	void *mo;
-	char *error;
+	const char *error;
 	typedef About* (*sdem)(QWidget *d);
 	sdem demo;
 	QString pfad = PREL;
@@ -3836,7 +3836,7 @@
 void ScribusApp::slotPrefsOrg()
 {
 	void *mo;
-	char *error;
+	const char *error;
 	typedef Preferences* (*sdem)(QWidget *d, preV *Vor);
 	sdem demo;
 	QString pfad = PREL;
@@ -4246,7 +4246,7 @@
 
 PSLib* ScribusApp::getPSDriver(bool psart, SCFonts &AllFonts, QMap<QString,QFont> DocFonts, CListe DocColors, bool pdf)
 {
-	char *error;
+	const char *error;
 	typedef PSLib* (*sdem)(bool psart, SCFonts &AllFonts, QMap<QString,QFont> DocFonts, CListe DocColors, bool pdf);
 	sdem demo;
 	QString pfad = PREL;
@@ -4276,7 +4276,7 @@
 
 PDFlib* ScribusApp::getPDFDriver()
 {
-	char *error;
+	const char *error;
 	typedef PDFlib* (*sdem)();
 	sdem demo;
 	QString pfad = PREL;
@@ -4646,7 +4646,7 @@
 
 void ScribusApp::FinalizePlugs()
 {
-	char *error;
+	const char *error;
 	QMap<QString, PlugData>::Iterator it;
 	struct PlugData pda;
 	typedef void (*sdem2)();
@@ -4711,7 +4711,7 @@
 void ScribusApp::CallDLL(QString name)
 {
 	void *mo;
-	char *error;
+	const char *error;
 	struct PlugData pda;
 	pda = PluginMap[name];
 	typedef void (*sdem)(QWidget *d, ScribusApp *plug);
@@ -4745,7 +4745,7 @@
 bool ScribusApp::DLLName(QString name, QString *PName, int *typ, void **Zeig)
 {
 	void *mo;
-	char *error;
+	const char *error;
 	typedef QString (*sdem0)();
 	typedef int (*sdem1)();
 	typedef void (*sdem2)(QWidget *d, ScribusApp *plug);
