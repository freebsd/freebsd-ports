--- unusedpackagesdialog.cc	Mon Aug  5 16:30:26 2002
+++ unusedpackagesdialog.cc.new	Sun Nov 24 18:38:02 2002
@@ -67,7 +67,7 @@
 
 UnusedPackagesProgressDialog::UnusedPackagesProgressDialog(
 	unsigned int daysNotAccessed, bool leafPackagesOnly,
-	QWidget *parent, const char *name = 0 )
+	QWidget *parent, const char *name )
 	: KDialogBase( parent, name, true, i18n( "Searching for packages..." ),
 	               Close, Close, true ),
 	m_daysNotAccessed( daysNotAccessed ),
