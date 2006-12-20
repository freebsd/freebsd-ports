--- src/format.h.orig	Wed Dec 20 16:46:15 2006
+++ src/format.h	Wed Dec 20 16:46:55 2006
@@ -648,17 +648,17 @@
 		
 		switch( num_of_args )
 		{
-		    case 1: n = std::snprintf( buffer, buffer_size, format.c_str(),
+		    case 1: n = snprintf( buffer, buffer_size, format.c_str(),
 					       D( a ) ); break;
-		    case 2: n = std::snprintf( buffer, buffer_size, format.c_str(),
+		    case 2: n = snprintf( buffer, buffer_size, format.c_str(),
 					       D( a ), D( b ) ); break;
-		    case 3: n = std::snprintf( buffer, buffer_size, format.c_str(),
+		    case 3: n = snprintf( buffer, buffer_size, format.c_str(),
 					       D( a ), D( b ), D( c ) ); break;
-		    case 4: n = std::snprintf( buffer, buffer_size, format.c_str(),
+		    case 4: n = snprintf( buffer, buffer_size, format.c_str(),
 					       D( a ), D( b ), D( c ), D( d ) ); break;
-		    case 5: n = std::snprintf( buffer, buffer_size, format.c_str(),
+		    case 5: n = snprintf( buffer, buffer_size, format.c_str(),
 					       D( a ), D( b ), D( c ), D( d ), D( e ) ); break;
-		    case 6: n = std::snprintf( buffer, buffer_size, format.c_str(),
+		    case 6: n = snprintf( buffer, buffer_size, format.c_str(),
 					       D( a ), D( b ), D( c ), D( d ), D( e ), D( f ) ); break;
 		}
 		
