--- panel-plugin/libacpi.c.orig	2011-01-03 23:38:40.000000000 +1100
+++ panel-plugin/libacpi.c	2011-03-21 15:38:01.000000000 +1100
@@ -30,6 +30,16 @@
 #include <dirent.h>
 #include <glob.h>
 
+#ifdef __FreeBSD__
+#include <fcntl.h>
+#include <sys/ioctl.h>
+#include <dev/acpica/acpiio.h>
+#define ACPIDEV         "/dev/acpi"
+static int      acpifd;
+#define UNKNOWN_CAP 0xffffffff
+#define UNKNOWN_VOLTAGE 0xffffffff
+#endif
+
 #if HAVE_SYSCTL
 
 #if defined(__NetBSD__) || defined (__OpenBSD__)
@@ -484,6 +494,7 @@
   }
 
   return 1;
+
 #else
 #ifdef HAVE_SYSCTL
   static char buf[BUFSIZ];
@@ -730,6 +741,24 @@
 #endif
   }
   acpiinfo->present = retval;
+
+#ifdef __FreeBSD__
+  union acpi_battery_ioctl_arg battio;
+  acpifd = open(ACPIDEV, O_RDONLY);
+
+  battio.unit = battery;
+  if (ioctl(acpifd, ACPIIO_BATT_GET_BIF, &battio) == -1) {
+	  return 0;
+  }
+  close(acpifd);
+
+  acpiinfo->design_capacity = battio.bif.dcap;
+  acpiinfo->last_full_capacity = battio.bif.lfcap;
+  acpiinfo->battery_technology = battio.bif.btech;
+  acpiinfo->design_voltage = battio.bif.dvol;
+  acpiinfo->design_capacity_warning = battio.bif.wcap;
+  acpiinfo->design_capacity_low = battio.bif.lcap;
+#endif
   return 1;
 #else
   return 0;
@@ -966,6 +995,29 @@
 #endif
   }
   acpistate->percentage =retval;
+
+#ifdef __FreeBSD__
+  union acpi_battery_ioctl_arg battio;
+  acpifd = open(ACPIDEV, O_RDONLY);
+
+  battio.unit = battery;
+  if (ioctl(acpifd, ACPIIO_BATT_GET_BATTINFO, &battio) == -1) {
+	  return 0;
+  }
+
+  acpistate->state = battio.battinfo.state;
+  acpistate->prate = battio.battinfo.rate;
+  acpistate->rcapacity = acpiinfo->last_full_capacity * battio.battinfo.cap / 100;
+  acpistate->rtime = battio.battinfo.min;
+  acpistate->percentage = battio.battinfo.cap;
+
+  battio.unit = battery;
+  if (ioctl(acpifd, ACPIIO_BATT_GET_BATTINFO, &battio) == -1) {
+	  return 0;
+  }
+  close(acpifd);
+  acpistate->pvoltage = battio.bst.volt;
+#endif
   return 1;
 #else
   return 0;
