--- nepenthes-core/src/Nepenthes.cpp.orig
+++ nepenthes-core/src/Nepenthes.cpp
@@ -35,16 +35,17 @@
 #include <getopt.h>
 #endif /* WIN32 */
 
-#include <stdio.h>
-#include <signal.h>
+#include <cstdio>
+#include <cstdlib>
+#include <csignal>
 #include <sys/types.h>
 #include <pwd.h>
 #include <grp.h>
 #include <dirent.h>
 #include <sys/utsname.h>
-#include <ctype.h>
-#include <errno.h>
-#include <string.h>
+#include <cctype>
+#include <cerrno>
+#include <cstring>
 
 #ifdef HAVE_LIBCAP
 #undef _POSIX_SOURCE
