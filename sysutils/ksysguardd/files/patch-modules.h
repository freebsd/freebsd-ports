--- modules.h	2011-03-17 20:50:04.000000000 +0200
+++ modules.h	2011-01-28 10:05:57.000000000 +0200
@@ -23,7 +23,6 @@
 #ifndef KSG_MODULES_H
 #define KSG_MODULES_H
 
-#include <config-ksysguardd.h>
 #include "Command.h"
 #include "conf.h"
 #include "ksysguardd.h"
@@ -49,16 +48,19 @@
 
 #if defined(OSTYPE_FreeBSD) || defined(OSTYPE_DragonFly)
 #include <grp.h>
+#include "acpi.h"
 #ifdef __i386__
  #include "apm.h"
 #endif
-#include "CPU.h"
+#include "cpuinfo.h"
 #include "diskstat.h"
 #include "loadavg.h"
 #include "logfile.h"
 #include "Memory.h"
 #include "netdev.h"
 #include "ProcessList.h"
+#include "stat.h"
+#include "uptime.h"
 #endif /* OSTYPE_FreeBSD */
 
 #ifdef OSTYPE_Irix
@@ -134,6 +136,7 @@
 #endif /* OSTYPE_Linux */
 
 #if defined OSTYPE_FreeBSD || defined OSTYPE_DragonFly
+  { "Acpi", initACPI, exitACPI, updateACPI, NULLVVFUNC, 0, NULLTIME },
   #ifdef __i386__
     { "Apm", initApm, exitApm, updateApm, NULLVVFUNC, 0, NULLTIME },
   #endif
@@ -144,6 +147,8 @@
   { "Memory", initMemory, exitMemory, updateMemory, NULLVVFUNC, 0, NULLTIME },
   { "NetDev", initNetDev, exitNetDev, updateNetDev, checkNetDev, 0, NULLTIME },
   { "ProcessList", initProcessList, exitProcessList, updateProcessList, NULLVVFUNC, 0, NULLTIME },
+  { "Stat", initStat, exitStat, updateStat, NULLVVFUNC, 0, NULLTIME },
+  { "Uptime", initUptime, exitUptime, NULLIVFUNC, NULLVVFUNC, 0, NULLTIME },
 #endif /* OSTYPE_FreeBSD */
 
 #ifdef OSTYPE_Irix
