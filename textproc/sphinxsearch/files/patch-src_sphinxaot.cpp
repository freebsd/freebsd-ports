--- src/sphinxaot.cpp.orig	2018-02-03 10:35:17 UTC
+++ src/sphinxaot.cpp
@@ -1133,7 +1133,7 @@ static inline int Utf8ToWin1251 ( BYTE * pOut, const B
 		assert ( pWord[1]>=0x80 && pWord[1]<0xC0 );
 
 		// table index D0 80..BF to 0..3F, and D1 80..BF to 40..7F
-		register BYTE uWin = dTable [ ( pWord[1] & 0x7F ) + ( ( pWord[0] & 1 )<<6 ) ];
+		BYTE uWin = dTable [ ( pWord[1] & 0x7F ) + ( ( pWord[0] & 1 )<<6 ) ];
 		pWord += 2;
 
 		if ( !uWin )
