--- src/hotkeys.c.orig	Tue Dec  3 14:26:32 2002
+++ src/hotkeys.c	Wed Jun 11 23:54:54 2003
@@ -54,7 +54,7 @@
 #include <fcntl.h>
 #include <sys/ioctl.h>
 #if defined (__FreeBSD__)
-#include <machine/soundcard.h>
+#include <sys/soundcard.h>
 #else
 #       if defined (__NetBSD__) || defined (__OpenBSD__)
 #       include <soundcard.h>          /* OSS emulation */
@@ -66,9 +66,9 @@
 #endif                          /* __FreeBSD__ */
 
 /* CDROM related */
-#include <linux/cdrom.h>        /* FIXME: linux specific! */
+//#include <linux/cdrom.h>        /* FIXME: linux specific! */
 /* APM (suspend/standby) support */
-#include "apm.h"
+//#include "apm.h"
 #if HAVE_GTK
   #include "splash.h"
 #endif
@@ -585,7 +585,7 @@
 {
     int         mixer_fd = -1, cdrom_fd = -1;
     int         master_vol, cd_vol;
-    struct cdrom_volctrl cdrom_vol;
+//    struct cdrom_volctrl cdrom_vol;
     int         left, right;
     static struct timeval last_time;
     struct timeval this_time;
@@ -683,6 +683,7 @@
     }
 
     /* open the cdrom/dvdrom drive device */
+/***** ANDY: No CD support yet
     if ( cdromDevice != NULL )
     {
         if ( (cdrom_fd = open( cdromDevice, O_RDONLY|O_NONBLOCK )) == -1 )
@@ -691,7 +692,7 @@
         }
         else
         {
-            /* read the cdrom volume */
+            || read the cdrom volume ||
             if ( ioctl(cdrom_fd, CDROMVOLREAD, &cdrom_vol) == -1 )
             {
                 uError("Unable to read the CDROM volume of `%s'", cdromDevice);
@@ -699,7 +700,7 @@
             }
             else
             {
-                /* Set the CDROM volume */
+                || Set the CDROM volume ||
                 int     t;
                 float   myAdj;
                 myAdj = 0xFF / 100.0 * adj;
@@ -721,9 +722,10 @@
             }
         }
     }
+END Andy *****/
 
     if (mixer_fd != -1)     close(mixer_fd);
-    if (cdrom_fd != -1)     close(cdrom_fd);
+//Andy    if (cdrom_fd != -1)     close(cdrom_fd);
 
     return ret;
 }
@@ -737,10 +739,10 @@
 {
     static Bool             muted = False;
     static int              last_mixer_vol, last_cd_vol;
-    static struct cdrom_volctrl last_cdrom_vol;
+//Andy    static struct cdrom_volctrl last_cdrom_vol;
 
     int                     vol, cd_vol;
-    struct cdrom_volctrl    cdrom_vol;
+//Andy    struct cdrom_volctrl    cdrom_vol;
     int                     mixer_fd = -1, cdrom_fd = -1;
 
     short ret = 0;      /* return value */
@@ -751,6 +753,7 @@
         uError("Unable to open `%s'", MIXER_DEV);
     }
     /* open the cdrom/dvdrom drive device */
+/***** Andy: No CD support
     if ( cdromDevice != NULL )
     {
         if ( (cdrom_fd = open( cdromDevice, O_RDONLY|O_NONBLOCK )) == -1 )
@@ -758,6 +761,7 @@
             uError("Unable to open `%s'", cdromDevice);
         }
     }
+END Andy *****/
 
     if ( muted )
     {
@@ -783,6 +787,7 @@
 #endif
             }
         }
+/***** Andy: No CD support
 #if 0
         if (SOUND_IOCTL(mixer_fd, SOUND_MIXER_WRITE_CD, &last_cd_vol) == -1)
         {
@@ -800,6 +805,7 @@
             } else
                 muted = False;
         }
+End Andy *****/
     }
     else    /* ! muted */
     {
@@ -837,6 +843,7 @@
                 }
             }
         }
+/***** Andy: No CD support
 #if 0
         if ( SOUND_IOCTL(mixer_fd, SOUND_MIXER_READ_CD, &last_cd_vol) == -1)
         {
@@ -853,7 +860,9 @@
                 muted = True;
         }
 #endif
+End Andy *****/
         /* read and store the cdrom volume */
+/***** Andy: No CD support
         if (cdrom_fd != -1)
         {
             if ( ioctl(cdrom_fd, CDROMVOLREAD, &last_cdrom_vol) == -1 )
@@ -863,8 +872,8 @@
             }
             else
             {
-                /* Set the volume to 0. FIXME: is this linux specific? Do
-                 * other platforms also have 4 channels? */
+                || Set the volume to 0. FIXME: is this linux specific? Do
+                 * other platforms also have 4 channels? ||
                 cdrom_vol.channel0 = cdrom_vol.channel1 = cdrom_vol.channel2 =
                     cdrom_vol.channel3 = 0;
                 if ( ioctl(cdrom_fd, CDROMVOLCTRL, &cdrom_vol) == -1 )
@@ -875,10 +884,11 @@
                     muted = True;
             }
         }
+End Andy *****/
     }
 
     if (mixer_fd != -1)   close(mixer_fd);
-    if (cdrom_fd != -1)   close(cdrom_fd);
+//Andy    if (cdrom_fd != -1)   close(cdrom_fd);
 
     return ret;
 }
@@ -886,19 +896,20 @@
 static int 
 ejectDisc(void)
 {
+/***** Andy: No CD support
     int fd, status;
 
     if ( cdromDevice == NULL )
         return 0;
 
-    /* the idea of this code is from xine's vcd plugin, mostly linux
-       specific FIXME */
+    || the idea of this code is from xine's vcd plugin, mostly linux
+       specific FIXME ||
     if ( (fd = open( cdromDevice, O_RDONLY | O_NONBLOCK)) > -1 ) {
         status = ioctl(fd, CDROM_DRIVE_STATUS, CDSL_CURRENT);
         switch (status)
         {
-            /* Looks like ATAPI drives doesn't return CDS_TRAY_OPEN,
-             * at least it's the case on my ASUS DVD drive... */
+            || Looks like ATAPI drives doesn't return CDS_TRAY_OPEN,
+             * at least it's the case on my ASUS DVD drive... ||
             case CDS_TRAY_OPEN:
 #ifdef HAVE_LIBXOSD
                 if ( osd )
@@ -929,7 +940,7 @@
             case CDS_NO_INFO:
             case CDS_DRIVE_NOT_READY:
             default:
-                /* Ignore */
+                || Ignore ||
                 break;
         }
         close(fd);
@@ -940,6 +951,7 @@
         SYSLOG(LOG_NOTICE, "CDROM_DRIVE_STATUS failed: %s\n", strerror(errno));
         return -1;
     }
+End Andy *****/
 }
 
 
@@ -1002,8 +1014,8 @@
 #ifdef HAVE_LIBXOSD
         if ( osd )
         {
-            xosd_display(osd, 0, XOSD_string, "Launching:");
-            xosd_display(osd, 1, XOSD_string, getConfig(type));
+            xosd_display(osd, 0, XOSD_string, type);
+            xosd_display(osd, 1, XOSD_string, "");
         }
 #endif
     }
@@ -1015,13 +1027,14 @@
 int
 sleepState(int mode)
 {
+/***** Andy: No APM support
 #ifdef USE_APMD
     switch (mode)
     {
-      case SUSPEND:
+    //  case SUSPEND:
         error = system("apm -s");
         break;
-      case STANDBY:
+    //  case STANDBY:
         error = system("apm -S");
         break;
       default:
@@ -1039,10 +1052,10 @@
     }
     switch (mode)
     {
-      case SUSPEND:
+     // case SUSPEND:
         error = apm_suspend(fd);
         break;
-      case STANDBY:
+     // case STANDBY:
         error = apm_standby(fd);
         break;
       default:
@@ -1050,7 +1063,9 @@
         break;
     }
     apm_close(fd);
-#endif /* USE_APMD */
+#endif 
+End Andy *****/
+/* USE_APMD */
 }
 
 
@@ -1105,8 +1120,8 @@
 #ifdef HAVE_LIBXOSD
                 if ( osd )
                 {
-                    xosd_display(osd, 0, XOSD_string, "Launching:");
-                    xosd_display(osd, 1, XOSD_string, kbd.customCmds[i].desc);
+                    xosd_display(osd, 0, XOSD_string, kbd.customCmds[i].desc);
+                    xosd_display(osd, 1, XOSD_string, "");
                 }
 #endif
                 break;  /* break the for loop */
@@ -1444,6 +1459,7 @@
                         3       /* shadow offset */,
                         3       /* number_lines */ 
                         );
+        xosd_set_align(osd, XOSD_center);
     }
 #endif
 }
@@ -1592,6 +1608,7 @@
                 doMute();
             } else
             /* APM stuffs */
+/**** Andy: No APM support
             if ( ev.message.keycode == (kbd.defCmds)[sleepKey].key ||
                  ev.message.keycode == (kbd.defCmds)[wakeupKey].key ) {
                 sleepState(STANDBY);
@@ -1601,8 +1618,9 @@
             }
             else
             {
+End Andy *****/
                 lookupUserCmd(ev.message.keycode);  /* User-defined stuffs */
-            }
+//Andy            }
         }
     }
 
