--- src/smiltime.cc.orig	Wed Apr  7 05:13:27 2004
+++ src/smiltime.cc	Tue Apr 13 11:25:32 2004
@@ -28,6 +28,7 @@
 #include <iomanip>
 #include <sstream>
 
+#include <stdio.h>
 #include <stdlib.h>
 #include <math.h>
 
@@ -333,13 +334,13 @@
 		case TIME_FORMAT_MIN:
 			str << ( ms / 60000 ) << "." << 
 				std::setfill( '0' ) << std::setw( 4 ) << 
-				round( ( float )( ms % 60000 ) / 6 ) << "min";
+				floor( ( float )( ms % 60000 ) / 6 + .5) << "min";
 			break;
 		
 		case TIME_FORMAT_H:
 			str << ( ms / 3600000 ) << "." << 
 				std::setfill( '0' ) << std::setw( 5 ) << 
-				round( ( float )( ms % 3600000 ) / 36 ) << "h";
+				floor( ( float )( ms % 3600000 ) / 36 + .5) << "h";
 			break;
 		
 		default:
@@ -507,7 +508,7 @@
 				mm << ":" << std::setfill( '0' ) << std::setw( 2 ) << ss << 
 				( m_framerate == 25.0 ? ":" : ";" ) << 
 				std::setfill( '0' ) << std::setw( 2 ) << 
-				round( m_framerate * ms / 1000.0 );
+				floor( m_framerate * ms / 1000.0 + .5);
 			if ( m_subframe == SMIL_SUBFRAME_0 )
 				str << ".0";
 			else if ( m_subframe == SMIL_SUBFRAME_1 )
