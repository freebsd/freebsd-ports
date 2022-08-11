--- libmailutils/stream/rdcache_stream.c.orig	2022-02-12 15:20:43 UTC
+++ libmailutils/stream/rdcache_stream.c
@@ -21,10 +21,9 @@
 #include <stdlib.h>
 #include <errno.h>
 #include <mailutils/types.h>
+#include <mailutils/errno.h>
 #include <mailutils/sys/rdcache_stream.h>
 
-size_t mu_rdcache_stream_max_memory_size = 4096;
-
 static int
 rdcache_read (struct _mu_stream *str, char *buf, size_t size, size_t *pnbytes)
 {
@@ -38,7 +37,6 @@ rdcache_read (struct _mu_stream *str, char *buf, size_
       if (status)
 	return status;
       sp->offset += nbytes;
-      sp->size += nbytes;
       buf += nbytes;
       size -= nbytes;
     }
@@ -79,11 +77,29 @@ static int
 }
 
 static int
-rdcache_size (struct _mu_stream *str, off_t *psize)
+rdcache_size (struct _mu_stream *str, mu_off_t *psize)
 {
   struct _mu_rdcache_stream *sp = (struct _mu_rdcache_stream *) str;
-  *psize = sp->size;
-  return 0;
+  int rc;
+
+  if (mu_stream_eof (sp->transport))
+    {
+      *psize = sp->size;
+      rc = 0;
+    }
+  else
+    {
+      rc = mu_stream_size (sp->transport, psize);
+      switch (rc)
+	{
+	case EAGAIN:
+	case EINTR:
+	case ENOSYS:
+	case EINPROGRESS:
+	  rc = MU_ERR_INFO_UNAVAILABLE;
+	}
+    }
+  return rc;
 }
 
 static int
