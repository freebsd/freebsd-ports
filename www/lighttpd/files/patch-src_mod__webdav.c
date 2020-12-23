--- src/mod_webdav.c.orig	2020-12-23 18:18:24 UTC
+++ src/mod_webdav.c
@@ -4574,7 +4574,7 @@ mod_webdav_put_deprecated_unsafe_partial_put_compat (r
         return HANDLER_FINISHED;
     }
 
-  #ifdef HAVE_COPY_FILE_RANGE
+  #if defined(HAVE_COPY_FILE_RANGE) && !defined(__FreeBSD__)
     /* use Linux copy_file_range() if available
      * (Linux 4.5, but glibc 2.27 provides a user-space emulation)
      * fd_in and fd_out must be on same mount (handled in mod_webdav_put_prep())
