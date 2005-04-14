--- src/kdmtheme.cpp	Wed Apr  6 07:50:26 2005
+++ src/kdmtheme.cpp	Fri Apr 15 00:35:34 2005
@@ -393,8 +393,8 @@
 
 void kdmtheme::updateTheme( const QString &screenshot, const QString &copyright, const QString &description ) {
 	p_configWidget->Info->setText(
-			((copyright.length() > 0)?i18n( "<b>Copyright:</b> " ) + copyright + "<br/>":"") +
-			((description.length() > 0)?i18n( "<b>Description:</b> " ) + description:"") );
+			((copyright.length() > 0)?i18n( "<b>Copyright:</b> " ) + copyright + ("<br/>"):QString("")) +
+			((description.length() > 0)?i18n( "<b>Description:</b> " ) + description:QString("")) );
 	p_configWidget->Preview->setPixmap( screenshot );
 }
 
