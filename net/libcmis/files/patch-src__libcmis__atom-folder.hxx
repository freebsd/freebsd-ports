--- src/libcmis/atom-folder.hxx.orig	2011-09-30 20:52:01.000000000 +0200
+++ src/libcmis/atom-folder.hxx	2012-05-07 20:06:29.000000000 +0200
@@ -42,7 +42,7 @@ class AtomFolder : public libcmis::Folde
     public:
         AtomFolder( AtomPubSession* session, std::string url );
         AtomFolder( AtomPubSession* session, xmlNodePtr entryNd );
-        ~AtomFolder( );
+        virtual ~AtomFolder( );
 
         // virtual pure methods from Folder
         virtual std::vector< libcmis::CmisObjectPtr > getChildren( );
