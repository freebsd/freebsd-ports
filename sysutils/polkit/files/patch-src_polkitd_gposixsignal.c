--- src/polkitd/gposixsignal.c.orig	2010-08-29 20:05:07.000000000 -0400
+++ src/polkitd/gposixsignal.c	2010-08-29 20:13:20.000000000 -0400
@@ -23,7 +23,13 @@
 #include "config.h"
 
 #include <unistd.h>
+#ifdef __FreeBSD__
+#include <sys/types.h>
+#include <sys/event.h>
+#include <sys/time.h>
+#else
 #include <sys/signalfd.h>
+#endif
 #include <signal.h>
 
 #include "gposixsignal.h"
@@ -83,6 +89,9 @@ _g_posix_signal_source_new (gint signum)
   gint fd;
   GSource *_source;
   _GPosixSignalSource *source;
+#ifdef __FreeBSD__
+  struct kevent ev;
+#endif
 
   _source = NULL;
 
@@ -92,7 +101,13 @@ _g_posix_signal_source_new (gint signum)
   if (sigprocmask (SIG_BLOCK, &sigset, NULL) == -1)
     g_assert_not_reached ();
 
+#ifdef __FreeBSD__
+  fd = kqueue ();
+  EV_SET (&ev, signum, EVFILT_SIGNAL, EV_ADD, 0, 0, NULL);
+  kevent (fd, &ev, 1, NULL, 0, NULL);
+#else
   fd = signalfd (-1, &sigset, SFD_NONBLOCK | SFD_CLOEXEC);
+#endif
 
   _source = g_source_new (&_g_posix_signal_source_funcs, sizeof (_GPosixSignalSource));
   source = (_GPosixSignalSource *) _source;
