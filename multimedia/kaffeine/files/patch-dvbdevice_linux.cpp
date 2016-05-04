--- src/dvb/dvbdevice_linux.cpp.orig	2016-05-03 12:36:58.011789000 +0200
+++ src/dvb/dvbdevice_linux.cpp	2016-05-03 12:41:02.658341000 +0200
@@ -35,7 +35,9 @@
 #include <sys/ioctl.h>
 #include <sys/stat.h>
 #include <dirent.h>
+#ifndef __FreeBSD__
 #include <sys/inotify.h>
+#endif
 #include <vector>
 #include <stdlib.h>
 #include <unistd.h>
@@ -854,8 +856,10 @@
 
                 runstate = 1;
 
+#ifndef __FreeBSD__
                 ifd = inotify_init();
                 inotify_add_watch(ifd, "/dev/dvb", IN_CREATE|IN_DELETE);
+#endif
                 fcntl(ifd, F_SETFL, O_NONBLOCK);
                 pfd.fd = ifd;
                 pfd.events = POLLIN;
