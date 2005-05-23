--- kopete/protocols/msn/sslloginhandler.h	Sun May 22 14:01:56 2005
+++ kopete/protocols/msn/sslloginhandler.h	Sun May 22 13:33:31 2005
@@ -0,0 +1,96 @@
+//Imported from KMess  - 2005-05-19
+
+/***************************************************************************
+                          sslloginhandler.h  -  description
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
+#ifndef SSLLOGINHANDLER_H
+#define SSLLOGINHANDLER_H
+
+#include <qobject.h>
+#include <qstringlist.h>
+
+// Forward declarations
+class KExtendedSocket;
+class KSSL;
+class MimeMessage;
+
+/**This class handles the SSL portion of the login.
+  *@author Mike K. Bennett
+  */
+
+class SslLoginHandler : public QObject
+{
+   Q_OBJECT
+
+  public:
+    // The constructor
+                         SslLoginHandler();
+    // The destructor
+                        ~SslLoginHandler();
+    // Start the login process
+    void                 login( QString parameters, QString handle, QString password );
+
+  private : // Private methods
+    // Get the authentication data from a string
+    void                 parseAuthenticationData( QString data );
+    // Parse the HTTP response from the server
+    void                 parseHttpResponse(QString data);
+    // Get login server data from a string
+    void                 parseLoginServerData( QString &host, QString &page, QString serverData );
+    // Read data from the socket via SSL
+    QString              readSslData();
+    // Send the authenticationn request
+    void                 sendAuthenticationRequest( QString loginServer, QString page );
+    // Send a HTTP request to the server
+    void                 sendHttpRequest( QString request, QString host, int port );
+    // Request the name of the login server
+    void                 sendLoginServerRequest(QString hostname);
+    // Write data to the socket via SSL
+    void                 writeSslData( QString data );
+
+  private slots : // Private slots
+    // Data was received over the socket
+    void                 dataReceived();
+    // Detect a socket error
+    void                 socketError(int error);
+
+  private : // Private attributes
+    // The mode of the transfer.
+    enum Mode          { NONE = 0, GETLOGINSERVER = 1, GETAUTHENTICATIONDATA = 2 } mode_;
+    // The list of parameters sent by the notification server
+    QString              authenticationParameters_;
+    // The cookies we received from the server
+    QStringList          cookies_;
+    // The user's handle
+    QString              handle_;
+    // The user's password
+    QString              password_;
+    // The socket over which the SSL data is written and read
+    KExtendedSocket     *socket_;
+    // The SSL handler
+    KSSL                *ssl_;
+
+  signals : // Public signals
+    // Signal that the login was aborted because an internal error occured
+    void                 loginFailed();
+    // Signal that the login failed, username/password was incorrect
+    void                 loginIncorrect();
+    // Signal that the login succeeded
+    void                 loginSucceeded( QString authentication );
+};
+
+#endif
