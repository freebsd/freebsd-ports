--- src/openvpnmanager.cpp	Mon Mar 26 10:43:56 2007
+++ src/openvpnmanager.cpp	Mon Mar 26 10:47:06 2007
@@ -192,7 +192,7 @@
    mConnectionWanted = false;
    mForce = false;
    command( "hold on\n" ); /* OpenVPN does imediatelly reconnect without the hold release. */
-   command( "signal SIGUSR1\n" );
+   command( "signal SIGHUP\n" );
 }
 
 void openVPNManager::ovpnReconnect()
