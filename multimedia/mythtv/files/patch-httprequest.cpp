--- libs/libmythupnp/httprequest.cpp~	Fri Mar 16 08:25:39 2007
+++ libs/libmythupnp/httprequest.cpp	Fri Mar 16 08:40:32 2007
@@ -21,8 +21,12 @@
 #ifdef CONFIG_DARWIN
 #include "darwin-sendfile.h"
 #else
+#ifdef __FreeBSD__
+typedef off_t __off64_t;
+#else
 #include <sys/sendfile.h>
 #endif
+#endif
 #include <sys/types.h>
 #include <sys/stat.h>
 #include <unistd.h>
@@ -289,6 +293,24 @@
         __off64_t offset = llStart;
         int       file   = open( sFileName.ascii(), O_RDONLY | O_LARGEFILE );
         ssize_t   sent   = 0;  
+#ifdef __FreeBSD__
+
+	int error;
+        error = sendfile (file,
+                          getSocketHandle (),
+                          offset,
+                          llSize,
+                          NULL,
+                          NULL,
+                          NULL );
+        if (error)
+          fprintf (stderr,
+                   "Can't transfer %s: %s (%d)\n",
+                   sFileName.ascii(),
+                   strerror (errno),
+                   errno );
+
+#else
 
         do 
         {  
@@ -301,6 +319,7 @@
             llSize -= sent;  
         } 
         while (( sent >= 0 ) && ( llSize > 0 ));  
+#endif
 
         close( file );
     }
