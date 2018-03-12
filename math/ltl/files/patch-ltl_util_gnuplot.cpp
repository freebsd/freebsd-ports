--- ltl/util/gnuplot.cpp.orig	2018-03-12 09:18:42 UTC
+++ ltl/util/gnuplot.cpp
@@ -27,6 +27,11 @@ THE SOFTWARE.
 #include <sys/stat.h>
 #include <errno.h>
 
+#include <sys/types.h>
+#include <sys/ioctl.h>
+#include <termios.h>
+#include <libutil.h>
+
 #if defined(HAVE_PTY_H)
 #  include <pty.h>
 #else
