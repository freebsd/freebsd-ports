--- clients/telnet/externs.h
+++ clients/telnet/externs.h
@@ -92,10 +92,10 @@
 #   include <termio.h>
 #  endif
 # else
-#  ifdef HAVE_SYS_TERMIOS_H
-#   include <sys/termios.h>
-#elif defined(HAVE_TERMIOS_H)
+#  ifdef HAVE_TERMIOS_H
 #   include <termios.h>
+#elif defined(HAVE_SYS_TERMIOS_H)
+#   include <sys/termios.h>
 #  endif
 # endif
 #endif
