--- src/polkit/polkit-sysdeps.h.orig	2007-12-23 01:46:49.000000000 -0500
+++ src/polkit/polkit-sysdeps.h	2007-12-23 01:48:22.000000000 -0500
@@ -35,6 +35,7 @@
 #define POLKIT_SYSDEPS_H
 
 #include <sys/types.h>
+#include <stdio.h>
 #include <polkit/polkit-types.h>
 
 POLKIT_BEGIN_DECLS
@@ -43,6 +44,9 @@ polkit_uint64_t polkit_sysdeps_get_start
 
 int polkit_sysdeps_get_exe_for_pid (pid_t pid, char *out_buf, size_t buf_size);
 
+ssize_t polkit_sysdeps_getline (char **lineptr, size_t *n, FILE *stream);
+
+int polkit_sysdeps_clearenv (void);
 
 POLKIT_END_DECLS
 
