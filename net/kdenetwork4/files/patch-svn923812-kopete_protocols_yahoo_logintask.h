--- ../kopete/protocols/yahoo/libkyahoo/logintask.h	2009/01/06 17:13:38	906699
+++ ../kopete/protocols/yahoo/libkyahoo/logintask.h	2009/02/09 14:00:12	923817
@@ -62,6 +62,7 @@
 	void haveSessionID( uint );
 	void haveCookies();
 	void loginResponse( int, const QString& );
+	void buddyListReady();
 private:
 	State mState;
 	Yahoo::Status m_stateOnConnect;
