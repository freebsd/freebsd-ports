--- ./libs/libmythupnp/httprequest.cpp.orig	2008-03-03 22:14:01.000000000 -0500
+++ ./libs/libmythupnp/httprequest.cpp	2009-02-23 09:59:26.000000000 -0500
@@ -21,9 +21,13 @@
 #if defined CONFIG_DARWIN || defined CONFIG_CYGWIN || defined(__FreeBSD__) || defined(USING_MINGW)
 #include "darwin-sendfile.h"
 #else
+#ifdef __FreeBSD__
+typedef off_t __off64_t;
+#else
 #define USE_SETSOCKOPT
 #include <sys/sendfile.h>
 #endif
+#endif
 #include <sys/types.h>
 #include <sys/stat.h>
 #include <unistd.h>
@@ -398,6 +402,24 @@
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
@@ -411,6 +433,7 @@
 	    //VERBOSE(VB_UPNP, QString("SendResponseFile : --- size = %1, offset = %2, sent = %3").arg(llSize).arg(offset).arg(sent));
         } 
         while (( sent >= 0 ) && ( llSize > 0 ));  
+#endif
 
         if (sent == -1)
         {
