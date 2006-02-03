--- plugins/upnp/upnpmcastsocket.cpp.orig	Fri Feb  3 18:13:05 2006
+++ plugins/upnp/upnpmcastsocket.cpp	Fri Feb  3 20:00:54 2006
@@ -40,6 +40,7 @@
 		QObject::connect(this,SIGNAL(readyRead()),this,SLOT(onReadyRead()));
 		QObject::connect(this,SIGNAL(gotError(int)),this,SLOT(onError(int)));
 		setAddressReuseable(true);
+		setFamily(KNetwork::KResolver::IPv4Family);
 		setBlocking(true);
 		for (Uint32 i = 0;i < 10;i++)
 		{
