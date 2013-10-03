--- src/core/sstring.cpp.orig	2009-05-24 21:56:30.000000000 +0000
+++ src/core/sstring.cpp
@@ -1112,7 +1112,7 @@ SStringList::SStringList( const SString&
 	append( str );
 }
 
-SStringList::SStringList( const SStringList::SStringList& list ):
+SStringList::SStringList( const SStringList& list ):
 	QList<SString>( list )
 {
 }
