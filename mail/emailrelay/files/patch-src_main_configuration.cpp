--- src/main/configuration.cpp.orig	2013-12-07 22:55:50 UTC
+++ src/main/configuration.cpp
@@ -86,10 +86,14 @@ G::Strings Main::Configuration::listenin
 	// the required list of addresses
 	for( G::Strings::iterator p = result.begin() ; p != result.end() ; )
 	{
-		if( protocol.empty() || protocol == G::Str::head( *p , (*p).find('=') , protocol ) )
-			*p++ = G::Str::tail( *p , (*p).find('=') , *p ) ;
-		else
-			p = result.erase( p ) ;
+		std::string::size_type pos = (*p).find('=');
+		if( pos != std::string::npos ) {
+			if( protocol.empty() || protocol == G::Str::head( *p , pos , protocol ) )
+				*p++ = G::Str::tail( *p , pos , *p ) ;
+			else
+				p = result.erase( p ) ;
+		} else
+			++p;
 	}
 
 	return result ;
