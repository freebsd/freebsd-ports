--- libs/libmythupnp/httprequest.cpp~	Tue Nov 14 12:29:06 2006
+++ libs/libmythupnp/httprequest.cpp	Tue Nov 14 12:59:13 2006
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
@@ -281,7 +285,30 @@
     {
         __off64_t offset = llStart;
         int       file   = open( sFileName.ascii(), O_RDONLY | O_LARGEFILE );
-        sendfile64( getSocketHandle(), file, &offset, llSize );
+        int error;
+
+#ifdef __FreeBSD__
+        error = sendfile (file,
+                          getSocketHandle (),
+                          offset,
+                          llSize,
+                          NULL,
+                          NULL,
+                          NULL );
+#else
+        error = sendfile64( getSocketHandle(), file, &offset, llSize );
+#endif
+
+        /*
+         * Yes, this isn't needed for portability, but I can't stand the sight
+         * of a call not checked for error conditions.
+         */
+        if (error)
+          fprintf (stderr,
+                   "Can't transfer %s: %s (%d)\n",
+                   sFileName.ascii(),
+                   strerror (errno),
+                   errno );

         close( file );
     }
