--- src/logging.c.orig	2017-12-08 12:22:41 UTC
+++ src/logging.c
@@ -1090,9 +1090,10 @@ _gpgrt_log_flush (void)
 
 
 /* Print a hexdump of (BUFFER,LENGTH).  With FMT passed as NULL print
- * just the raw dump, with FMT being an empty string, print a trailing
- * linefeed, otherwise print an entire debug line with the expanded
- * FMT followed by a possible wrapped hexdump and a final LF.  */
+ * just the raw dump (in this case ARG_PTR is not used), with FMT
+ * being an empty string, print a trailing linefeed, otherwise print
+ * an entire debug line with the expanded FMT followed by a possible
+ * wrapped hexdump and a final LF.  */
 void
 _gpgrt_logv_printhex (const void *buffer, size_t length,
                       const char *fmt, va_list arg_ptr)
@@ -1150,7 +1151,16 @@ _gpgrt_log_printhex (const void *buffer, size_t length
       va_end (arg_ptr);
     }
   else
-    _gpgrt_logv_printhex (buffer, length, NULL, NULL);
+    {
+      /* va_list is not necessary a pointer and thus we can't use NULL
+       * because that would conflict with platforms using a straight
+       * struct for it (e.g. arm64).  We use a dummy variable instead;
+       * the static is a simple way zero it out so to not get
+       * complains about uninitialized use.  */
+      static va_list dummy_argptr;
+
+      _gpgrt_logv_printhex (buffer, length, NULL, dummy_argptr);
+    }
 }
 
 
