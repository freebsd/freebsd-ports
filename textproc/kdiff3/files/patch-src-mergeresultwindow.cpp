--- src/mergeresultwindow.cpp.orig	Sun Oct 29 18:42:07 2006
+++ src/mergeresultwindow.cpp	Sun Nov  5 13:56:47 2006
@@ -3136,7 +3136,7 @@
 
 void WindowTitleWidget::slotSetModified( bool bModified )
 {
-   m_pModifiedLabel->setText( bModified ? i18n("[Modified]") : "" );
+   m_pModifiedLabel->setText( bModified ? i18n("[Modified]") : QString("") );
 }
 
 bool WindowTitleWidget::eventFilter( QObject* o, QEvent* e )
