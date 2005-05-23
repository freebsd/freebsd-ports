--- kopete/protocols/msn/sslloginhandler.cpp	Sun May 22 14:01:55 2005
+++ kopete/protocols/msn/sslloginhandler.cpp	Sun May 22 13:33:31 2005
@@ -0,0 +1,453 @@
+//Imported from KMess (2005-05-19)
+
+/***************************************************************************
+                          sslloginhandler.cpp  -  description
+                             -------------------
+    begin                : Sat Jun 28 2003
+    copyright            : (C) 2003 by Mike K. Bennett
+    email                : mkb137b@hotmail.com
+ ***************************************************************************/
+
+/***************************************************************************
+ *                                                                         *
+ *   This program is free software; you can redistribute it and/or modify  *
+ *   it under the terms of the GNU General Public License as published by  *
+ *   the Free Software Foundation; either version 2 of the License, or     *
+ *   (at your option) any later version.                                   *
+ *                                                                         *
+ ***************************************************************************/
+
+#include "sslloginhandler.h"
+
+#include <qstringlist.h>
+#include <qregexp.h>
+#include <qsocket.h>
+#include <qurl.h>
+
+#include <kdebug.h>
+#include <kextsock.h>
+#include <kssl.h>
+#include <kurl.h>
+
+#if 0
+#include "../kmessdebug.h"
+#include "mimemessage.h"
+#else
+//i didn't want to import the whole MimeMessage from Kmess for Kopete so i
+// reimplemented the base here  -Olivier
+
+class MimeMessage
+{
+	public:
+		MimeMessage(const QString &msg) : message(msg) {}
+
+		QString getValue(const QString &key)
+		{
+			QRegExp rx(key+": (.*)\n");
+			rx.search(message);
+			return rx.cap(1);
+		}
+	private:
+		QString message;
+};
+
+#include "sslloginhandler.moc"
+#endif
+//there is nothing modified from here.  this is exactly the kmerlin code
+
+
+
+/*
+ * Great documentation about this can be found at
+ * http://siebe.bot2k3.net/docs/
+ */
+
+
+// The constructor
+SslLoginHandler::SslLoginHandler()
+ : mode_(NONE)
+{
+  // Create the SSL handler
+  ssl_ = new KSSL( true );
+
+  // Create and set up the socket.
+  socket_ = new KExtendedSocket( );
+
+  //socket_->setSocketFlags( 0x00 | 0x600000 ); // 0x00 = anySocket | 0x600000 = bufferedSocket
+  socket_->setSocketFlags( 0x00 ); // 0x00 = anySocket | 0x600000 = bufferedSocket
+  socket_->setTimeout( 30   );
+  socket_->enableRead( true );
+  connect( socket_, SIGNAL(         readyRead()    ),
+           this,    SLOT  (      dataReceived()    ) );
+  connect( socket_, SIGNAL(  connectionFailed(int) ),
+           this,    SLOT  (       socketError(int) ) );
+}
+
+
+
+// The destructor
+SslLoginHandler::~SslLoginHandler()
+{
+  delete ssl_;
+  delete socket_;
+}
+
+
+
+// Data was received over the socket
+void SslLoginHandler::dataReceived()
+{
+#ifdef KMESSDEBUG_SSLLOGINHANDLER
+  kdDebug() << "SslLoginHandler - ******************** Data received ********************" << endl;
+  kdDebug() << "SslLoginHandler - " << socket_->bytesAvailable() << " bytes available." << endl;
+  kdDebug() << "SslLoginHandler - SSL says " << ssl_->pending() << " bytes available." << endl;
+#endif
+
+  QString   data;
+  int       breakOut = 0;
+  const int maxIterations = 1000;
+  while ( ( !data.contains( QRegExp("\r\n") ) ) && ( breakOut < maxIterations ) )
+  {
+    // Read data via SSL
+    data = readSslData();
+    breakOut ++;
+  }
+
+  // Output the data for debugging
+#ifdef KMESSDEBUG_SSLLOGINHANDLER
+  kdDebug() << "SslLoginHandler - ********************   Contents    ********************" << endl;
+  kdDebug() << data << endl;
+  kdDebug() << "SslLoginHandler - ********************  End of data  ********************" << endl;
+#endif
+
+  // Warn if timed out
+  if ( breakOut >= maxIterations )
+  {
+    kdDebug() << "WARNING - SSL read timed out." << endl;
+    emit loginFailed();
+    return;
+  }
+
+  if ( data.length() > 0 )
+  {
+    parseHttpResponse(data);
+  }
+  else
+  {
+    kdDebug() << "WARNING - Available data wasn't read from the SSL socket." << endl;
+    emit loginFailed();
+  }
+}
+
+
+
+// Start the login process
+void SslLoginHandler::login( QString parameters, QString handle, QString password )
+{
+#ifdef KMESSDEBUG_SSLLOGINHANDLER
+  kdDebug() << "SslLoginHandler - Starting login with parameters " << parameters << "." << endl;
+#endif
+
+  // Store the given data
+  authenticationParameters_ = parameters;
+  handle_                   = handle;
+  password_                 = password;
+
+  // Get the login server
+  sendLoginServerRequest("nexus.passport.com");
+  dataReceived();
+}
+
+
+
+// Get the authentication data from a string
+void SslLoginHandler::parseAuthenticationData( QString data )
+{
+  QString twnData;
+
+  // Pull TWN data out of the message
+  twnData = data.right( data.length() - data.find(QRegExp("from-PP='")) - 9 );
+  twnData = twnData.left( twnData.find(QRegExp("',")) );
+
+#ifdef KMESSDEBUG_SSLLOGINHANDLER
+  kdDebug() << "SslLoginHandler - data for TWN is " << twnData << "." << endl;
+#endif
+
+  // Notify the MsnNotificationConnection
+  emit loginSucceeded(twnData);
+}
+
+
+
+// Parse the HTTP response from the server
+void SslLoginHandler::parseHttpResponse(QString data)
+{
+  KURL    location;
+  int     headerEnd;
+  QString header;
+  int     headerCode;
+  QString headerText;
+
+  // Parse the HTTP status header
+  QRegExp re("HTTP/\\d+\\.\\d+ (\\d+) ([^\r\n]+)");
+  headerEnd  = data.find("\r\n");
+  header     = data.left( (headerEnd == -1) ? 20 : headerEnd );
+
+  re.search(header);
+  headerCode = re.cap(1).toUInt();
+  headerText = re.cap(2);
+
+  // Create a MimeMessage, removing the HTTP status header
+  MimeMessage message( data.section( ",", 1 ) );
+
+
+  switch(mode_)
+  {
+    case GETLOGINSERVER:
+    {
+      // Step 1. This data describes the login server to use.
+      if(headerCode == 302)
+      {
+        // HTTP Redirect
+        location = KURL( message.getValue( "Location" ) );
+        sendLoginServerRequest(location.host());
+      }
+      else
+      {
+        // Parse the data
+        QString loginServer;
+        QString page;
+        parseLoginServerData( loginServer, page, message.getValue("PassportURLs") );
+
+        // Send the authentication request
+        sendAuthenticationRequest( loginServer, page );
+      }
+      break;
+    }
+    case GETAUTHENTICATIONDATA:
+    {
+      // Step 2. Get the authentication data
+      if(headerCode == 200)
+      {
+        // Login success
+        parseAuthenticationData(message.getValue("Authentication-Info"));
+      }
+      else if(headerCode == 302)
+      {
+        // HTTP Redirect
+        location = KURL( message.getValue( "Location" ) );
+        sendAuthenticationRequest(location.host(), location.path());
+      }
+      else if(headerCode == 401)
+      {
+        // Got a HTTP "401 Unauthorized"; Login failed
+        emit loginIncorrect();
+      }
+      else
+      {
+        kdDebug() << "SslLoginHandler::parseHttpResponse: WARNING "
+                  << "- Unhandled response code " << headerCode << " " << headerText << endl;
+        emit loginFailed();
+      }
+      break;
+    }
+    default:
+    {
+      kdDebug() << "SslLoginHandler::parseHttpResponse: WARNING - Entered illegal state" << endl;
+      emit loginFailed();
+    }
+  }
+}
+
+
+// Get login server data from a string
+void SslLoginHandler::parseLoginServerData( QString &host, QString &page, QString serverData )
+{
+  int slashIndex;
+
+  // Get everything between "DLLogin=" and to the comma.
+  serverData = serverData.right( serverData.length() - serverData.find( "DALogin=" ) - 8 );
+  serverData = serverData.left( serverData.find( "," ) );
+
+#ifdef KMESSDEBUG_SSLLOGINHANDLER
+  kdDebug() << "SslLoginHandler - host/page=" << serverData << endl;
+#endif
+
+  // Separate the "host/page" string.
+  slashIndex = serverData.find( "/" );
+  host = serverData.left( slashIndex );
+  page = serverData.right( serverData.length() - slashIndex );
+
+#ifdef KMESSDEBUG_SSLLOGINHANDLER
+  kdDebug() << "SslLoginHandler - host=" << host << " page=" << page << endl;
+#endif
+}
+
+
+
+// Read data from the socket via SSL
+QString SslLoginHandler::readSslData()
+{
+  char       rawblock[1024];
+  QCString   block;
+  QString    data        = "";
+  int        noBytesRead = 1;
+
+  // Read data from the SSL socket.
+  if ( ssl_ != 0 )
+  {
+//    while( ( ssl_->pending() > 0 ) && ( noBytesRead > 0 ) )
+//    while( ( socket_->bytesAvailable() > 0 ) && ( noBytesRead > 0 ) )
+    while(noBytesRead > 0)
+    {
+      noBytesRead = ssl_->read( rawblock, 1024 );
+#ifdef KMESSDEBUG_SSLLOGINHANDLER
+      kdDebug() << "SslLoginHandler - " << noBytesRead << " bytes read." << endl;
+#endif
+      block = rawblock;
+      block = block.left( noBytesRead );
+      data += QString::fromUtf8( block );
+    }
+  }
+
+  return data;
+}
+
+
+
+// Send the authenticationn request
+void SslLoginHandler::sendAuthenticationRequest( QString loginServer, QString page )
+{
+#ifdef KMESSDEBUG_SSLLOGINHANDLER
+  kdDebug() << "SslLoginHandler - Step 2. Requesting authentication data." << endl;
+#endif
+
+  QString request;
+  QString encodedHandle   = handle_;
+  QString encodedPassword = password_;
+
+  QUrl::encode(encodedHandle);
+  QUrl::encode(encodedPassword);
+
+  request = "GET " + page + " HTTP/1.1\r\n"
+            "Authorization: Passport1.4"
+              " OrgVerb=GET"
+              ",OrgURL=http%3A%2F%2Fmessenger%2Emsn%2Ecom"
+              ",sign-in=" + encodedHandle +
+              ",pwd="     + encodedPassword +
+              ","         + authenticationParameters_ + "\r\n"
+            "User-Agent: MSMSGS\r\n"     // Make sure the server won't discriminate
+            "Host: " + loginServer + "\r\n"
+            "Connection: Keep-Alive\r\n"
+            "Cache-Control: no-cache\r\n\r\n";
+
+  // Step 2. Send the authorisation request
+  mode_ = GETAUTHENTICATIONDATA;
+  sendHttpRequest( request, loginServer, 443 );
+}
+
+
+
+// Send a HTTP request to the server
+void SslLoginHandler::sendHttpRequest( QString request, QString host, int port )
+{
+  QString response;
+  QString responseBody;
+
+  if ( socket_ == 0 )
+  {
+    kdDebug() << "SslLoginHandler::sendHttpRequest - WARNING "
+              << "- Trying to login using a null socket." << endl;
+    return;
+  }
+
+  // Configure the socket
+#ifdef KMESSDEBUG_SSLLOGINHANDLER
+  kdDebug() << "SslLoginHandler - Close and reset the socket." << endl;
+#endif
+  ssl_->setAutoReconfig( true );
+  ssl_->reInitialize();
+  socket_->closeNow();
+  socket_->reset();
+
+  // Try to connect
+#ifdef KMESSDEBUG_SSLLOGINHANDLER
+  kdDebug() << "SslLoginHandler - Connecting to " << host << ":" << port << "." << endl;
+#endif
+  socket_->setAddress( host, port );
+  socket_->lookup();
+  int connectionSuccess = socket_->connect();
+  if ( connectionSuccess != 0 )
+  {
+    kdDebug() << "SslLoginHandler::sendHttpRequest - WARNING "
+              << "- Connection failed, giving " << connectionSuccess << endl;
+    return;
+  }
+
+  // Try to wrap the SSL handler
+#ifdef KMESSDEBUG_SSLLOGINHANDLER
+  kdDebug() << "SslLoginHandler - Connection success, binding SSL to socket fd " << socket_->fd() << endl;
+#endif
+  int sslConnectionSuccess = ssl_->connect( socket_->fd() );
+  if ( sslConnectionSuccess != 1 )
+  {
+    kdDebug() << "SslLoginHandler::sendHttpRequest - WARNING "
+              << "- SSL Connection failed, giving " << sslConnectionSuccess << endl;
+    return;
+  }
+
+  // Send the request
+#ifdef KMESSDEBUG_SSLLOGINHANDLER
+  kdDebug() << "SslLoginHandler - SSL connected OK, sending the request." << endl;
+  kdDebug() << request;
+#endif
+  writeSslData( request );
+}
+
+
+
+// Request the name of the login server
+void SslLoginHandler::sendLoginServerRequest(QString hostname)
+{
+#ifdef KMESSDEBUG_SSLLOGINHANDLER
+  kdDebug() << "SslLoginHandler - Step 1. Requesting the login server." << endl;
+#endif
+
+  // Step 1. Send the login server request
+  // The server will respond with the location of the main SSL server.
+  mode_ = GETLOGINSERVER;
+  sendHttpRequest( "GET /rdr/pprdr.asp\r\n\r\n", hostname, 443 );
+}
+
+
+
+// Detect a socket error
+void SslLoginHandler::socketError(int error)
+{
+  kdDebug() << "SslLoginHandler : WARNING - Received error " << error << " from the socket." << endl;
+}
+
+
+
+// Write data to the socket via SSL
+void SslLoginHandler::writeSslData( QString data )
+{
+  int noBytesWritten;
+
+  if(socket_ != 0 && ssl_ != 0)
+  {
+    noBytesWritten = ssl_->write( data.latin1(), data.length() );
+    if(noBytesWritten != (int)data.length())
+    {
+      kdDebug() << "WARNING - Wanted to write " << data.length() << " to the socket, "
+                << " wrote " << noBytesWritten << "." << endl;
+    }
+#ifdef KMESSDEBUG_SSLLOGINHANDLER
+    else
+    {
+      kdDebug() << "SslLoginHandler - Sent " << noBytesWritten << " bytes via SSL." << endl;
+    }
+#endif
+  }
+}
+
