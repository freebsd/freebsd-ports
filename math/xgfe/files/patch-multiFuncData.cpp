--- multiFuncData.cpp.orig	Mon May 18 04:04:37 1998
+++ multiFuncData.cpp	Wed Mar 17 17:35:27 2004
@@ -52,7 +52,7 @@
 	multiFuncList = new QComboBox( FALSE, this, "ComboBox_3" );
 	multiFuncList->setMinimumSize( 340, 30 );
 	multiFuncList->setMaximumSize( 32767, 30 );
-	connect( multiFuncList, SIGNAL(activated(const char*)), SLOT(funcChanged(const char*)) );
+	connect( multiFuncList, SIGNAL(activated(const QString&)), SLOT(funcChanged(const QString&)) );
 	multiFuncList->setSizeLimit( 100 );
 	multiFuncList->setAutoResize( FALSE );
 
@@ -243,7 +243,7 @@
 multiFuncData::~multiFuncData()
 {
 }
-void multiFuncData::funcChanged(const char*)
+void multiFuncData::funcChanged(const QString&)
 {
 }
 void multiFuncData::insertNewFunction()
