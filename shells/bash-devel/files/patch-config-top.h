--- config-top.h.orig	Wed Dec 28 19:52:23 2005
+++ config-top.h	Wed Dec 28 19:54:12 2005
@@ -52,18 +52,18 @@
 /* The default value of the PATH variable. */
 #ifndef DEFAULT_PATH_VALUE
 #define DEFAULT_PATH_VALUE \
-  "/usr/gnu/bin:/usr/local/bin:/bin:/usr/bin:."
+  "/sbin:/bin:/usr/sbin:/usr/bin:/usr/games:%%LOCALBASE%%/sbin:%%LOCALBASE%%/bin"
 #endif
 
 /* The value for PATH when invoking `command -p'.  This is only used when
    the Posix.2 confstr () function, or CS_PATH define are not present. */
 #ifndef STANDARD_UTILS_PATH
 #define STANDARD_UTILS_PATH \
-  "/bin:/usr/bin:/sbin:/usr/sbin:/etc:/usr/etc"
+  "/sbin:/bin:/usr/sbin:/usr/bin:/usr/games"
 #endif
 
 /* Default primary and secondary prompt strings. */
-#define PPROMPT "\\s-\\v\\$ "
+#define PPROMPT "[\\u@\\h \\w]\\$ "
 #define SPROMPT "> "
 
 /* Undefine this if you don't want the ksh-compatible behavior of reprinting
