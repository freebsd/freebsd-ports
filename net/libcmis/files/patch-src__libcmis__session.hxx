--- src/libcmis/session.hxx.orig	2011-09-30 20:38:39.000000000 +0200
+++ src/libcmis/session.hxx	2012-05-07 19:23:43.000000000 +0200
@@ -36,6 +36,7 @@ namespace libcmis
     class Session
     {
         public:
+            virtual ~Session( ) { }
 
             /** Get the Root folder of the repository
               */
