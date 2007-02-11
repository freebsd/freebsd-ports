--- ftparchive/cachedb.cc.orig	Tue Jul 25 00:35:54 2006
+++ ftparchive/cachedb.cc	Tue Nov 14 17:06:17 2006
@@ -25,6 +25,7 @@
 #include <apt-pkg/configuration.h>
     
 #include <netinet/in.h>       // htonl, etc
+#include <publib.h>
 									/*}}}*/
 
 // CacheDB::ReadyDB - Ready the DB2					/*{{{*/
