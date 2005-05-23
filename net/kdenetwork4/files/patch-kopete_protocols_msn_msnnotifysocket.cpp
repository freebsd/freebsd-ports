--- kopete/protocols/msn/msnnotifysocket.cpp	Wed Feb 23 05:30:54 2005
+++ kopete/protocols/msn/msnnotifysocket.cpp	Sun May 22 13:33:31 2005
@@ -23,6 +23,7 @@
 #include "msnnotifysocket.h"
 #include "msncontact.h"
 #include "msnaccount.h"
+#include "sslloginhandler.h"
 
 #include <qregexp.h>
 
@@ -48,7 +49,8 @@
 : MSNSocket( account )
 {
 	m_newstatus = MSNProtocol::protocol()->NLN;
-	
+	m_sslLoginHandler=0l;
+
 	m_isHotmailAccount=false;
 	m_ping=false;
 
@@ -59,12 +61,11 @@
 
 	m_keepaliveTimer = new QTimer( this, "m_keepaliveTimer" );
 	QObject::connect( m_keepaliveTimer, SIGNAL( timeout() ), SLOT( slotSendKeepAlive() ) );
-
-	QObject::connect( this, SIGNAL( commandSent() ), SLOT( slotResetKeepAlive() ) );
 }
 
 MSNNotifySocket::~MSNNotifySocket()
 {
+	delete m_sslLoginHandler;
 	kdDebug(14140) << k_funcinfo << endl;
 }
 
@@ -203,11 +204,13 @@
 	}
 	case 715:
 	{
+		/*
 		//if(handlev==m_account->accountId())
 		QString msg = i18n( "Your email address has not been verified with the MSN server.\n"
 			"You should have received a mail with a link to confirm your email address.\n"
 			"Some functions will be restricted if you do not confirm your email address." );
 		KMessageBox::queuedMessageBox( Kopete::UI::Global::mainWidget(), KMessageBox::Sorry, msg, i18n( "MSN Plugin" ) );//TODO don't show again
+		*/
 		break;
 	}
 	case 800:
@@ -245,10 +248,10 @@
 {
 	//kdDebug(14140) << "MSNNotifySocket::parseCommand: Command: " << cmd << endl;
 
-	
+
 	if ( cmd == "VER" )
 	{
-		sendCommand( "CVR", "0x0409 winnt 5.1 i386 MSNMSGR 6.0.0602 MSMSGS " + m_account->accountId() );
+		sendCommand( "CVR", "0x0409 winnt 5.1 i386 MSNMSGR 6.2.0205 MSMSGS " + m_account->accountId() );
 /*
 		struct utsname utsBuf;
 		uname ( &utsBuf );
@@ -266,26 +269,15 @@
 	{
 		if( data.section( ' ', 1, 1 ) == "S" )
 		{
-			m_authData=data.section( ' ' , 2 , 2 );
-			m_kv=QString::null;
-
-			if( m_account->accountId().contains("@hotmail.") )
-				m_sid="loginnet.passport.com";
-			else if( m_account->accountId().contains("@msn.") ||  m_account->accountId().contains("@compaq.net") ||  m_account->accountId().contains("@webtv.net") )
-				m_sid="msnialogin.passport.com";
-			else
-				m_sid="login.passport.com";
-
-			QString authURL="https://"+m_sid+"/login.srf?" + m_authData;
-			authURL.replace("," , "&" ) ;
-
-			kdDebug(14140) << k_funcinfo << "downlaod URL: " << authURL << endl;
+			m_sslLoginHandler = new SslLoginHandler();
+			QObject::connect( m_sslLoginHandler, SIGNAL(       loginFailed()        ),
+					 this,            SLOT  (    sslLoginFailed()        ) );
+			QObject::connect( m_sslLoginHandler, SIGNAL(    loginIncorrect()        ),
+					 this,            SLOT  ( sslLoginIncorrect()        ) );
+			QObject::connect( m_sslLoginHandler, SIGNAL(    loginSucceeded(QString) ),
+					 this,            SLOT  ( sslLoginSucceeded(QString) ) );
 
-			KIO::Job *job = KIO::get( KURL( authURL ), true, false );
-			job->addMetaData("cookies", "manual");
-			// This should force kio to download the page even is we are in the konqueror offline mode.  [see bug #68483]
-			job->addMetaData("cache", "reload");
-			QObject::connect( job, SIGNAL(result( KIO::Job *)), this, SLOT(slotAuthJobDone( KIO::Job *)) );
+			m_sslLoginHandler->login( data.section( ' ' , 2 , 2 ), m_account->accountId() , m_password );
 		}
 		else
 		{
@@ -301,6 +293,9 @@
 			// do some nice things with it  :-)
 			QString publicName = unescape( data.section( ' ', 2, 2 ) );
 			emit publicNameChanged( publicName );
+
+			// We are connected start to ping
+			slotSendKeepAlive();
 		}
 	}
 	else if( cmd == "LST" )
@@ -355,9 +350,9 @@
 	}
 	else if( cmd == "XFR" )
 	{
-		QString stype=data.section( ' ', 0, 0 ); 
+		QString stype=data.section( ' ', 0, 0 );
 		if( stype=="SB" ) //switchboard connection (chat)
-		{ 
+		{
 			// Address, AuthInfo
 			emit startChat( data.section( ' ', 1, 1 ), data.section( ' ', 3, 3 ) );
 		}
@@ -370,7 +365,7 @@
 			emit receivedNotificationServer( server, port );
 			disconnect();
 		}
-		
+
 	}
 	else if( cmd == "RNG" )
 	{
@@ -526,6 +521,10 @@
 	{
 		//this is a reply from a ping
 		m_ping=false;
+
+		// id is the timeout in fact, and we remove 5% of it
+		m_keepaliveTimer->start( id * 950, true );
+		kdDebug( 14140 ) << k_funcinfo << "timerTimeout=" << id << "sec"<< endl;
 	}
 	else if( cmd == "URL" )
 	{
@@ -582,76 +581,20 @@
 }
 
 
-void MSNNotifySocket::slotAuthJobDataReceived ( KIO::Job */*job*/,const  QByteArray &data)
+void MSNNotifySocket::sslLoginFailed()
 {
-	m_authData += QCString( data, data.size()+1 );
-//	kdDebug(14140) << "MSNNotifySocket::slotAuthJobDataReceived: " << data << endl;
+	disconnect();
 }
-
-void MSNNotifySocket::slotAuthJobDone ( KIO::Job *job)
+void MSNNotifySocket::sslLoginIncorrect()
 {
-//	kdDebug(14140) << "MSNNotifySocket::slotAuthJobDone: "<< m_authData << endl;
-
-	if(job->error())
-	{
-		//FIXME: Shouldn't we say that we are the MSN plugin?
-		job->showErrorDialog();
-		disconnect();
-		return;
-	}
-
-	if(m_kv.isNull())
-	{
-		QStringList cookielist=QStringList::split("\n", job->queryMetaData("setcookies") );
-		QString cookies="Cookie: ";
-		for ( QStringList::Iterator it = cookielist.begin(); it != cookielist.end(); ++it )
-		{
-			QRegExp rx("Set-Cookie: ([^;]*)");
-			rx.search(*it);
-			cookies+=rx.cap(1)+";";
-		}
-
-		//QRegExp rx("lc=([1-9]*),id=([1-9]*),tw=([1-9]*),fs=[1-9]*,ru=[1-9a-zA-Z%]*,ct=[1-9]*,kpp=[1-9]*,kv=([1-9]*),");
-		QRegExp rx("lc=([0-9]*),id=([0-9]*),tw=([0-9]*),.*kv=([0-9]*),");
-		rx.search(m_authData);
-
-		QString authURL = "https://" + m_sid + "/ppsecure/post.srf?lc=" + rx.cap( 1 ) + "&id=" +
-			rx.cap( 2 ) + "&tw=" + rx.cap( 3 ) + "&cbid=" + rx.cap( 2 ) + "&da=passport.com&login=" +
-			KURL::encode_string( m_account->accountId()) + "&domain=passport.com&passwd=";
-
-		kdDebug( 14140 ) << k_funcinfo << "Download URL: " << authURL << "(*******)" << endl;
-
-		m_authData = QString::null;
-		m_kv=rx.cap(4);
-		if(m_kv.isNull()) m_kv="";
-
-		authURL += KURL::encode_string( m_password ) ;
-		job = KIO::get( KURL( authURL ), false, false );
-		job->addMetaData("cookies", "manual");
-		job->addMetaData("setcookies", cookies);
-		job->addMetaData("cache", "reload");
-
-		QObject::connect( job, SIGNAL(data( KIO::Job *,const QByteArray&)), this, SLOT(slotAuthJobDataReceived( KIO::Job *,const QByteArray&)) );
-		QObject::connect( job, SIGNAL(result( KIO::Job *)), this, SLOT(slotAuthJobDone( KIO::Job *)) );
-	}
-	else
-	{
-		if(m_authData.contains("CookiesDisabled"))
-		{
-			// FIXME: is this still possible now we add our meta data? - Martijn
-			disconnect();
-			KMessageBox::queuedMessageBox( Kopete::UI::Global::mainWidget(), KMessageBox::Error,
-				i18n( "Unable to connect to the MSN Network.\nYour Web browser options are currently set to disable cookies.\n"
-				"To use .NET Passport, you must enable cookies at least for the passport.com domain" ), i18n( "MSN Plugin" ) );
-			return;
-		}
-
-		QRegExp rx(/*URL=http://memberservices.passport.net/memberservice.srf*/"\\?did=[0-9]*&(t=[0-9A-Za-z!$*]*&p=[0-9A-Za-z!$*]*)\"");
-		rx.search(m_authData);
-
-		m_badPassword=true;  //if this disconnect, that mean the password was bad
-		sendCommand("USR" , "TWN S " + rx.cap(1));
-	}
+	m_badPassword = true;
+	disconnect();
+}
+void MSNNotifySocket::sslLoginSucceeded(QString a)
+{
+	sendCommand("USR" , "TWN S " + a);
+	m_sslLoginHandler->deleteLater();
+	m_sslLoginHandler=0;
 }
 
 
@@ -893,13 +836,6 @@
 	//at least 90 second has been ellapsed since the last messages
 	// we shouldn't receive error from theses command anymore
 	m_tmpHandles.clear();
-}
-
-void MSNNotifySocket::slotResetKeepAlive()
-{
-	// Fire the timer every 90 seconds. QTimer will reset a running timer
-	// on a subsequent call if there has been activity again.
-	m_keepaliveTimer->start( 90000 );
 }
 
 Kopete::OnlineStatus MSNNotifySocket::convertOnlineStatus( const QString &status )
