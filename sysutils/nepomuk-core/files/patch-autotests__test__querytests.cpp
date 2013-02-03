--- ./autotests/test/querytests.cpp.orig	2012-11-30 09:00:24.000000000 +0100
+++ ./autotests/test/querytests.cpp	2013-01-09 20:41:58.662772968 +0100
@@ -295,7 +295,7 @@
 
     // Resource Type Term
     {
-        Query::Query query( ResourceTypeTerm( NAO::Tag() ) );
+        Query::Query query( ( ResourceTypeTerm( NAO::Tag() ) ) );
 
         QSet<QUrl> uris;
         NepomukStatementIterator it( RDF::type() );
