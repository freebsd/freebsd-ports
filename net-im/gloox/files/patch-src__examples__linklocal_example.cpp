--- src/examples/linklocal_example.cpp.orig	2015-08-11 14:37:51 UTC
+++ src/examples/linklocal_example.cpp
@@ -111,15 +111,15 @@ class LinkLocalExample : public LinkLoca
       for( ; it != services.end(); ++it )
       {
         printf( "%s:\t%s.%s%s on interface %d\n", (*it).flag == LinkLocal::AddService ? "Added" : "Removed", (*it).service.c_str(), (*it).regtype.c_str(),
-                (*it).domain.c_str(), (*it).interface );
+                (*it).domain.c_str(), (*it).iface );
         if( !m_fClient /*&& (*it)->flag == LinkLocal::AddService && (*it)->service != "js@pitufo"*/ )
         {
           printf( "setting up new local client and connecting to %s.%s%s on interface %d\n",
-                  (*it).service.c_str(), (*it).regtype.c_str(), (*it).domain.c_str(), (*it).interface );
+                  (*it).service.c_str(), (*it).regtype.c_str(), (*it).domain.c_str(), (*it).iface );
           m_fClient = new LinkLocal::Client( JID( "js@pitufo" ) );
           m_fClient->logInstance().registerLogHandler( LogLevelDebug, LogAreaAll, this );
           m_fClient->registerConnectionListener( this );
-          if( !m_fClient->connect( (*it).service, (*it).regtype, (*it).domain, (*it).interface ) )
+          if( !m_fClient->connect( (*it).service, (*it).regtype, (*it).domain, (*it).iface ) )
           {
             printf( "m_fClient->connect() failed\n" );
           }
