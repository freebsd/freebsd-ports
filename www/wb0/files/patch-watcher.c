--- watcher.c.orig	Mon Dec  6 00:45:07 1999
+++ watcher.c	Wed Jan 31 13:42:20 2001
@@ -2,7 +2,7 @@
 /* (c) 1999 Clocksoft */
 /* Watcher -- watches for incoming data and keyhits */
 
-#define OTHK
+//#define OTHK
 //#define WATCHDOG
 /* When no keyboard scan is performed during 10 seconds, the program ends. */
 
@@ -11,6 +11,7 @@
 #include <sys/types.h>
 #include <unistd.h>
 #include <stdlib.h>
+#include <term.h>
 #include <sys/stat.h>
 #include <fcntl.h>
 #include <string.h>
@@ -18,10 +19,15 @@
 #include <vgakeyboard.h>
 #include <signal.h>
 #include <sys/ioctl.h>
-#ifndef OTHK
-#include <linux/kd.h>
+#ifdef __FreeBSD__
+#include <sys/ioctl_compat.h>
+#include <machine/pcvt_ioctl.h>
+#include <sys/kbio.h>
 #endif
+#ifdef LINUX
+#include <linux/kd.h>
 #include <sys/vt.h>
+#endif
 #include <sys/wait.h>
 
 #include "gvars.h"
@@ -38,9 +44,7 @@
 #define FILE_BUFFER_SIZE 4096
 #define min(x,y) ((x)<(y)?(x):(y))
 
-#ifndef OTHK
 extern int __svgalib_tty_fd;
-#endif
 
 /********************* Global variables for watcher ***************************/
 
@@ -138,7 +142,7 @@
 int
 reset_keyboard(void)
 {
- #ifdef OTHK
+ #if 0//def OTHK
  keyboard_close();
  #else
  if (ioctl(__svgalib_tty_fd,KDSKBMODE,old_keyboard_mode))
@@ -658,11 +662,11 @@
    close(fds[1]);
    if (content_type==WAI_HTML||content_type==WAI_TEXT)
    { 
-    execlp("lynx","lynx","-dump","-raw","-cfg=/etc/wb0/wb0.lynx.cfg",filename,NULL);
+    execlp("lynx","lynx","-dump","-raw","",filename,NULL);
    }
    else 
    { 
-    execlp("lynx","lynx","-source","-cfg=/etc/wb0/wb0.lynx.cfg",filename,NULL);
+    execlp("lynx","lynx","-source","",filename,NULL);
    }
    fprintf(stderr,"Unable to execlp lynx.\n");
    _exit(-1); /* Error */
@@ -941,7 +945,11 @@
    {
     /* alt-f1 ... alt-f10, alt-f11 ... alt-f12 */
     int vt;
+#ifdef __FreeBSD__
+    struct screeninfo vts;
+#else
     struct vt_stat vts;
+#endif
     
     if (k>=87)
     {vt=11+k-87;
@@ -949,22 +957,30 @@
     else
     {vt=1+k-59;
     }
+#ifdef __FreeBSD__
+    if (ioctl(__svgalib_tty_fd,VGAGETSCREEN,&vts))
+#else
     #ifdef OTHK
     ioctl(keyboard_fd,VT_GETSTATE,&vts);
     #else
     ioctl(__svgalib_tty_fd,VT_GETSTATE,&vts);
     #endif
     if (vt!=vts.v_active)
+#endif
     { 
      rightshift=leftshift=rightalt=leftalt=leftctrl=rightctrl=capslock=0;
      #ifdef DEBUG_VT
      printf("Trying to switch VT.\n");
      #endif
+#ifdef __FreeBSD__
+     ioctl(__svgalib_tty_fd,VT_ACTIVATE,vt);
+#else
      #ifdef OTHK
      ioctl(keyboard_fd,VT_ACTIVATE,vt);
      #else
      ioctl(__svgalib_tty_fd,VT_ACTIVATE,vt);
      #endif
+#endif
     }
    }
    break;
@@ -1399,8 +1415,13 @@
 int
 set_keyboard(void)
 {
+#ifdef __FreeBSD__
+ int sigs[]={SIGINT,SIGQUIT,SIGTERM,SIGSEGV,SIGHUP,SIGILL,SIGABRT,SIGFPE,
+ SIGBUS,SIGUSR1,SIGURG,SIGALRM};
+#else
  int sigs[]={SIGINT,SIGQUIT,SIGTERM,SIGSEGV,SIGHUP,SIGILL,SIGABRT,SIGFPE,
   SIGBUS,SIGPWR,SIGSTKFLT,SIGALRM};
+#endif
  int *p;
  int i;
  
@@ -1436,7 +1457,11 @@
    return 1;
   }
  }
+#ifdef __FreeBSD__
+ if (ioctl(__svgalib_tty_fd,KDSKBMODE,CBREAK))
+#else
  if (ioctl(__svgalib_tty_fd,KDSKBMODE,K_MEDIUMRAW))
+#endif
  {
   fprintf(stderr,"Unable to set keyboard to medium-raw mode.\n");
   return 1;
