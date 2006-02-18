--- cdda2wav/mycdrom.h  Wed Sep  4 14:07:16 2002
+++ cdda2wav/mycdrom.h  Sat Jan 17 18:52:08 2004
@@ -59,9 +59,16 @@
 #   endif /* if 0 */
 #  else /* not Sun SVR4 */
 #   if defined __FreeBSD__ || defined __NetBSD__ || defined __OpenBSD__ || defined __DragonFly__
-#    if (defined(__FreeBSD__) && __FreeBSD_version < 228000) || !defined(CDIOCREADAUDIO)
-#     undef HAVE_IOCTL_INTERFACE
+#    if defined __FreeBSD__  && !defined __DragonFly__ 
+#     if __FreeBSD_version < 228000
+#      undef HAVE_IOCTL_INTERFACE
+#     endif
 #    else
+#     if !defined CDIOCREADAUDIO 
+#      undef HAVE_IOCTL_INTERFACE
+#     endif
+#    endif
+#    if defined HAVE_IOCTL_INTERFACE 
 
 #define CDROM_LBA	CD_LBA_FORMAT
 #define CDROM_MSF	CD_MSF_FORMAT
