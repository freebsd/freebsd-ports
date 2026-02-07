--- gl/getopt.in.h.orig	2011-12-16 17:10:10 UTC
+++ gl/getopt.in.h
@@ -23,15 +23,6 @@
 #endif
 @PRAGMA_COLUMNS@
 
-/* The include_next requires a split double-inclusion guard.  We must
-   also inform the replacement unistd.h to not recursively use
-   <getopt.h>; our definitions will be present soon enough.  */
-#if @HAVE_GETOPT_H@
-# define _GL_SYSTEM_GETOPT
-# @INCLUDE_NEXT@ @NEXT_GETOPT_H@
-# undef _GL_SYSTEM_GETOPT
-#endif
-
 #ifndef _@GUARD_PREFIX@_GETOPT_H
 
 #ifndef __need_getopt
