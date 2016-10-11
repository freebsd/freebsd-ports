--- config-top.h.orig	2016-05-19 18:34:02 UTC
+++ config-top.h
@@ -63,18 +63,18 @@
 /* The default value of the PATH variable. */
 #ifndef DEFAULT_PATH_VALUE
 #define DEFAULT_PATH_VALUE \
-  "/usr/local/bin:/usr/local/sbin:/usr/bin:/usr/sbin:/bin:/sbin:."
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
