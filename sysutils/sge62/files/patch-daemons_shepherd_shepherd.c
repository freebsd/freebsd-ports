
$FreeBSD$

--- daemons/shepherd/shepherd.c.orig
+++ daemons/shepherd/shepherd.c
@@ -108,7 +108,7 @@
 #include "windows_gui.h"
 #endif
 
-#if defined(DARWIN)
+#if defined(DARWIN) || defined(FREEBSD)
 #  include <termios.h>
 #  include <sys/ttycom.h>
 #  include <sys/ioctl.h>    
@@ -214,7 +214,7 @@
    memset(tmpbuf, 0, sizeof(tmpbuf));
 
    /* TODO: Why do we ingore SIGWINCH here? Why do we ignore only SIGWINCH here?*/
-   sigignore(SIGWINCH);
+   signal(SIGWINCH, SIG_IGN);
 
    /* close parents end of out copy of the pipe */
    shepherd_trace("Child: closing parents end of the pipe");
