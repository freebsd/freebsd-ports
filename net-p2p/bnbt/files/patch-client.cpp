--- client.cpp	Wed Sep 29 21:38:32 2004
+++ client.cpp.new	Sat Oct 23 15:40:05 2004
@@ -19,6 +19,7 @@
 *
 ***/
 
+#include <sys/time.h>
 #include <fcntl.h>
 
 #include "bnbt.h"
@@ -639,4 +640,4 @@
 	rsp.strContent.reserve( 1024 );
 	rsp.bCompressOK = true;
 	m_iLast = GetTime( );
-}
\ No newline at end of file
+}
