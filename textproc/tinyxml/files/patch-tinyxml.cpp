--- tinyxml.cpp.orig	2010-03-23 13:16:36.000000000 +0800
+++ tinyxml.cpp	2010-07-26 15:28:06.000000000 +0800
@@ -57,30 +57,7 @@
 	{
 		unsigned char c = (unsigned char) str[i];
 
-		if (    c == '&' 
-		     && i < ( (int)str.length() - 2 )
-			 && str[i+1] == '#'
-			 && str[i+2] == 'x' )
-		{
-			// Hexadecimal character reference.
-			// Pass through unchanged.
-			// &#xA9;	-- copyright symbol, for example.
-			//
-			// The -1 is a bug fix from Rob Laveaux. It keeps
-			// an overflow from happening if there is no ';'.
-			// There are actually 2 ways to exit this loop -
-			// while fails (error case) and break (semicolon found).
-			// However, there is no mechanism (currently) for
-			// this function to return an error.
-			while ( i<(int)str.length()-1 )
-			{
-				outString->append( str.c_str() + i, 1 );
-				++i;
-				if ( str[i] == ';' )
-					break;
-			}
-		}
-		else if ( c == '&' )
+		if ( c == '&' )
 		{
 			outString->append( entity[0].str, entity[0].strLength );
 			++i;
