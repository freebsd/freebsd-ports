--- cdda2wav/mycdrom.h	Wed Sep  4 14:07:16 2002
+++ cdda2wav/mycdrom.h	Sat Jan 17 18:52:08 2004
@@ -4,6 +4,12 @@
 #else
 # if defined HAVE_SYS_CDIO_H
 #  include <sys/cdio.h>
+#  if defined(__FreeBSD__) && __FreeBSD__ >= 2
+#   include <osreldate.h>
+#   if __FreeBSD_version >= 400014
+#    include <sys/cdrio.h>
+#   endif
+#  endif
 
 #  if (defined (__sun) && defined (SVR4))
 #   if 0
@@ -53,7 +59,7 @@
 #   endif /* if 0 */
 #  else /* not Sun SVR4 */
 #   if defined __FreeBSD__ || defined __NetBSD__ || defined __OpenBSD__
-#    if !defined CDIOCREADAUDIO
+#    if (!defined(__FreeBSD__) && !defined(CDIOCREADAUDIO)) || __FreeBSD_version < 228000
 #     undef HAVE_IOCTL_INTERFACE
 #    else
 
