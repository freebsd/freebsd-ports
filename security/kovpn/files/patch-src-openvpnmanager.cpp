--- src/openvpnmanager.cpp	Fri Mar 31 21:56:53 2006
+++ src/openvpnmanager.cpp	Tue Apr 11 16:27:47 2006
@@ -159,7 +159,7 @@
    mConnectionWanted = false;
    mForce = false;
    command( "hold on\n" ); /* OpenVPN does imediatelly reconnect without the hold release. */
-   command( "signal SIGUSR1\n" );
+   command( "signal SIGHUP\n" );
 }
 
 void openVPNManager::ovpnReconnect()
