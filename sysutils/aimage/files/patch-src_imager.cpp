imager.cpp:857:8: error: value of type '__bind<int &, sockaddr *, unsigned long>' is not contextually convertible to 'bool'
    if(bind(sock,(sockaddr *)&local,sizeof(local))) err(1,"bind");
           ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

--- src/imager.cpp.orig	2018-06-05 06:55:20 UTC
+++ src/imager.cpp
@@ -854,7 +854,7 @@ int imager::socket_listen(int port)
 #endif
     local.sin_family = AF_INET;
     local.sin_port   = htons(port);	// listen on requested port.
-    if(bind(sock,(sockaddr *)&local,sizeof(local))) err(1,"bind");
+    if(::bind(sock,(sockaddr *)&local,sizeof(local))) err(1,"bind");
     if(listen(sock,0)) err(1,"listen");		// listen, and only accept one
     printf("Listening for connection on port %d...\n",port);
     in = accept(sock,(sockaddr *)&remote,&rsize);
