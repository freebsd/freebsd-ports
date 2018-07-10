--- udp.cxx.orig	2018-07-10 16:05:16 UTC
+++ udp.cxx
@@ -64,7 +64,7 @@ openPort( unsigned short port, unsigned 
       }
    }
 	
-   if ( bind( fd,(struct sockaddr*)&addr, sizeof(addr)) != 0 )
+   if ( ::bind( fd,(struct sockaddr*)&addr, sizeof(addr)) != 0 )
    {
       int e = getErrno();
         
