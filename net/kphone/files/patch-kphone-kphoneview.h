--- kphone/kphoneview.h.orig	Tue Dec 19 23:07:14 2006
+++ kphone/kphoneview.h	Tue Dec 19 23:07:46 2006
@@ -54,7 +54,7 @@
 	QString getStunSrv( void );
 	void kphoneQuit( void );
 	bool getState( void );
-	KCallWidget *KPhoneView::DoCall( QString num, SipCall::CallType ctype );
+	KCallWidget *DoCall( QString num, SipCall::CallType ctype );
 
 signals:
 	void stateChanged( void );
