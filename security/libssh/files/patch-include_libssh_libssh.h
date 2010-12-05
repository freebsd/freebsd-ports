--- include/libssh/libssh.h.orig	2010-10-31 18:16:26.000000000 +0900
+++ include/libssh/libssh.h	2010-10-31 18:16:41.000000000 +0900
@@ -22,9 +22,6 @@
 #ifndef _LIBSSH_H
 #define _LIBSSH_H

-#ifdef LIBSSH_STATIC
-  #define LIBSSH_API
-#else
   #if defined _WIN32 || defined __CYGWIN__
     #ifdef LIBSSH_EXPORTS
       #ifdef __GNUC__
@@ -46,7 +43,6 @@
       #define LIBSSH_API
     #endif
   #endif
-#endif

 #ifdef _MSC_VER
   /* Visual Studio hasn't inttypes.h so it doesn't know uint32_t */

