--- src/tree.cpp.orig	Tue Dec 31 05:00:47 2002
+++ src/tree.cpp	Tue Dec 31 16:30:12 2002
@@ -18,6 +18,7 @@
 
 #ifdef HAVE_REGEX_H
 extern "C" {
+#  include <sys/types.h>
 #  include <regex.h>
 }
 #endif
@@ -1181,7 +1182,7 @@
 
 	DEBUG( OUT(3)( "wrote %d: bytes error: %d\n", rsize, ferror( o ) ) );
 
-    } while( !std::feof( o ) && !ferror( o ) && !ferror( t ) );
+    } while ( !feof( o ) && !ferror( o ) && !ferror( t ) );
 
     std::fclose( o );
     std::fclose( t );
