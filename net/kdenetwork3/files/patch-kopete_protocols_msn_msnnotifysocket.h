--- kopete/protocols/msn/msnnotifysocket.h	Wed Feb 23 05:30:54 2005
+++ kopete/protocols/msn/msnnotifysocket.h	Sun May 22 13:33:31 2005
@@ -29,6 +29,7 @@
 class MSNDispatchSocket;
 class MSNAccount;
 class KTempFile;
+class SslLoginHandler;
 
 #include <kio/job.h>
 
@@ -62,7 +63,7 @@
 	void createChatSession();
 
 	void sendMail(const QString &email);
-	
+
 	bool badPassword() { return m_badPassword; }
 
 public slots:
@@ -88,8 +89,8 @@
 	void statusChanged( const Kopete::OnlineStatus &newStatus );
 
 	void hotmailSeted(bool) ;
-	
-	
+
+
 	/**
 	 * When the dispatch server sends us the notification server to use, this
 	 * signal is emitted. After this the socket is automatically closed.
@@ -109,7 +110,7 @@
 	 * This reimplementation handles most of the other MSN error codes.
 	 */
 	virtual void handleError( uint code, uint id );
-	
+
 	/**
 	 * This reimplementation sets up the negotiating with the server and
 	 * suppresses the change of the status to online until the handshake
@@ -131,15 +132,9 @@
 	 */
 	void slotSendKeepAlive();
 
-	/**
-	 * Reset the keepalive time after the socket has sent a command.
-	 */
-	void slotResetKeepAlive();
-
-
-
-	void slotAuthJobDataReceived ( KIO::Job *, const QByteArray &data);
-	void slotAuthJobDone ( KIO::Job *);
+	void sslLoginFailed();
+	void sslLoginIncorrect();
+	void sslLoginSucceeded(QString);
 
 
 private:
@@ -170,12 +165,12 @@
 	QString m_kv;
 	QString m_sid;
 	QString m_loginTime;
-	QString m_authData;
+	SslLoginHandler *m_sslLoginHandler;
 
 	QTimer *m_keepaliveTimer;
 
 	bool m_ping;
-	
+
 	bool m_badPassword;
 };
 
