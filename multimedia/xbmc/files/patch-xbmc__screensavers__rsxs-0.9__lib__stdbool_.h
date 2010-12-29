--- ./xbmc/screensavers/rsxs-0.9/lib/stdbool_.h.orig	2007-10-08 19:37:14.000000000 +0200
+++ ./xbmc/screensavers/rsxs-0.9/lib/stdbool_.h	2010-12-01 12:17:34.237808685 +0100
@@ -101,7 +101,9 @@
 # else
    /* With this compiler, trust the _Bool type if the compiler has it.  */
 #  if !@HAVE__BOOL@
+#if !defined(__FreeBSD__)
 typedef enum { _Bool_must_promote_to_int = -1, false = 0, true = 1 } _Bool;
+#endif
 #  endif
 # endif
 #endif
