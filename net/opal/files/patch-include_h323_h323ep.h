--- include/h323/h323ep.h.orig  2013-02-20 06:18:14.000000000 +0400
+++ include/h323/h323ep.h       2018-07-31 01:18:14.180154000 +0300
@@ -145,7 +145,7 @@
       OpalCall & call,                  ///<  Owner of connection
       const PString & party,            ///<  Remote party to call
       void * userData  = NULL,          ///<  Arbitrary data to pass to connection
-      unsigned int options = NULL,      ///<  options to pass to conneciton
+      unsigned int options = 0,         ///<  options to pass to conneciton
       OpalConnection::StringOptions * stringOptions = NULL
     );
   //@}
