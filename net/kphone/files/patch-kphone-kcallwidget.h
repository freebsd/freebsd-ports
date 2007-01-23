--- kphone/kcallwidget.h.orig	Tue Dec 19 23:08:52 2006
+++ kphone/kcallwidget.h	Tue Dec 19 23:09:05 2006
@@ -67,7 +67,7 @@
 	void clickHangup( void );
 	void setHide( void );
 	bool isHided( void ) const { return hided; }
-	void KCallWidget::setDTMFSender( QString &s );
+	void setDTMFSender( QString &s );
 
 public slots:
 	void pleaseDial( const SipUri &dialuri );
