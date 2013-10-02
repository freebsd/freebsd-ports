--- src/TPMManager.cxx.orig	2011-08-15 13:23:48.000000000 +0000
+++ src/TPMManager.cxx
@@ -409,7 +409,7 @@ void TPM_Manager::slotUpdatePCRs()
 
 void TPM_Manager::slotProcessURL( const QString& url )
 {
-	QUrl myURL = QUrl::QUrl(url, QUrl::StrictMode);
+	QUrl myURL = QUrl(url, QUrl::StrictMode);
 	if ( !( QDesktopServices::openUrl(myURL) ) )
 		QMessageBox::critical( this, "Error: Opening a URL", "Could not open your favourite browser. " );
 }
