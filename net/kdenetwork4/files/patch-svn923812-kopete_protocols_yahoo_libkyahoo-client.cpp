--- ../kopete/protocols/yahoo/libkyahoo/client.cpp	2009/02/06 02:57:20	921978
+++ ../kopete/protocols/yahoo/libkyahoo/client.cpp	2009/02/09 14:00:12	923817
@@ -99,6 +99,8 @@
 	QString statusMessageOnConnect;
 	Yahoo::PictureStatus pictureFlag;
 	int pictureChecksum;
+	bool buddyListReady;
+	QStringList pictureRequestQueue;
 };
 
 Client::Client(QObject *par) :QObject(par)
@@ -117,12 +119,14 @@
 	d->loginTask = new LoginTask( d->root );
 	d->listTask = new ListTask( d->root );
 	d->pictureFlag = Yahoo::NoPicture;
+	d->buddyListReady = false;
 	m_connector = 0L;
 
 	m_pingTimer = new QTimer( this );
 	QObject::connect( m_pingTimer, SIGNAL( timeout() ), this, SLOT( sendPing() ) );
 
 	QObject::connect( d->loginTask, SIGNAL( haveSessionID( uint ) ), SLOT( lt_gotSessionID( uint ) ) );
+	QObject::connect( d->loginTask, SIGNAL( buddyListReady() ), SLOT( processPictureQueue() ) );
 	QObject::connect( d->loginTask, SIGNAL( loginResponse( int, const QString& ) ), 
 				SLOT( slotLoginResponse( int, const QString& ) ) );
 	QObject::connect( d->loginTask, SIGNAL( haveCookies() ), SLOT( slotGotCookies() ) );
@@ -197,6 +201,7 @@
 		m_connector->deleteLater();
 	m_connector = 0L;
 	d->active = false;
+	d->buddyListReady = false;
 }
 
 int Client::error()
@@ -490,8 +495,33 @@
 
 // ***** Buddyicon handling *****
 
+void Client::processPictureQueue()
+{
+	kDebug(YAHOO_RAW_DEBUG) << k_funcinfo << endl;
+	d->buddyListReady = true;
+	if( d->pictureRequestQueue.isEmpty() )
+	{
+		return;
+	}
+
+	requestPicture( d->pictureRequestQueue.front() );
+	d->pictureRequestQueue.pop_front();
+
+	
+	if( !d->pictureRequestQueue.isEmpty() )
+	{
+		QTimer::singleShot( 1000, this, SLOT(processPictureQueue()) );
+	}
+}
+
 void Client::requestPicture( const QString &userId )
 {
+	if( !d->buddyListReady )
+	{
+		d->pictureRequestQueue << userId;
+		return;
+	}
+
 	RequestPictureTask *rpt = new RequestPictureTask( d->root );
 	rpt->setTarget( userId );
 	rpt->go( true );
