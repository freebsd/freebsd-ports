--- src/libcmis/atom-document.hxx.orig	2011-10-01 14:26:15.000000000 +0200
+++ src/libcmis/atom-document.hxx	2012-05-07 20:06:51.000000000 +0200
@@ -44,7 +44,7 @@ class AtomDocument : public libcmis::Doc
     public:
         AtomDocument( AtomPubSession* session, std::string url );
         AtomDocument( AtomPubSession* session, xmlNodePtr entryNd );
-        ~AtomDocument( );
+        virtual ~AtomDocument( );
 
         // Override content methods
         virtual FILE* getContent( const char* path = NULL );
