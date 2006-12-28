--- CONFIG/src/backend/archinfo_freebsd.c.orig	Tue Dec 19 06:47:11 2006
+++ CONFIG/src/backend/archinfo_freebsd.c	Wed Dec 27 11:29:26 2006
@@ -73,15 +73,26 @@
       }
       break;
    case AFSPARC: /* don't know */
+      if (!CmndOneLine(NULL, "sysctl hw.model", res))
+      {
+          if (strstr(res, "UltraSparc-IV"))  mach = SunUSIV;
+          if (strstr(res, "UltraSparc-II")) mach = SunUSII;
+          if (strstr(res, "UltraSparc-I")) mach = SunUSI;
+          if (strstr(res, "UltraSparc")) mach = SunUSI;
+          else mach = SunUSI;
+      }
       break;
    case AFALPHA:
-      #if 0
       if (!CmndOneLine(NULL, "sysctl hw.model", res))
       {
+#if 0
          if (strstr(res, "433au")) mach = Dec21164;
+         else if (strstr(res, "500au")) mach = Dec21164;
+         else if (strstr(res, "AlphaPC 164")) mach = Dec21164;
          else if (strstr(res, "XP1000")) mach = Dec21264;
+         else mach = Dec21264;
+#endif
       }
-      #endif
       break;
    case AFIA64: /* don't know */
       break;
@@ -89,15 +100,33 @@
       if (!CmndOneLine(NULL, "sysctl hw.model", res))
       {
          if (strstr(res, "Pentium Pro")) mach = IntPPRO;
+         else if (strstr(res, "Pentium(R) D")) mach = IntP4E;
+         else if (strstr(res, "Pentium(R) Pro")) mach = IntPPRO;
+         else if (strstr(res, "Pentium 4")) mach = IntP4;
+         else if (strstr(res, "Pentium(R) 4")) mach = IntP4;
+         else if (strstr(res, "Pentium(R) M")) mach = IntP4;
          else if (strstr(res, "Pentium III")) mach = IntPIII;
          else if (strstr(res, "Pentium II ")) mach = IntPII;
          else if (strstr(res, "Athlon")) mach = AmdAthlon;
+         else if (strstr(res, "Pentium III/Pentium III")) mach = IntPIII;
+         else if (strstr(res, "Pentium(R) III")) mach = IntPIII;
+         else if (strstr(res, "Pentium II")) mach = IntPII;
+         else if (strstr(res, "Pentium II/PentiumII")) mach = IntPII;
+         else if (strstr(res, "Pentium(R) II ")) mach = IntPII;
+         else if (strstr(res, "Celeron")) mach = IntPII;
+         else if (strstr(res, "Celeron(R)")) mach = IntPII;
+         else if (strstr(res, "Opteron(tm)")) mach = AmdHammer;
+         else if (strstr(res, "AMD Athlon(tm) 64")) mach = AmdHammer;
          else if (strstr(res, "AMD-K7")) mach = AmdAthlon;
-         else if (strstr(res, "32 bit Hammer")) mach = AmdHammer;
-         else if (strstr(res, "64 bit Hammer")) mach = AmdHammer;
-         else if (strstr(res, "Pentium/P55C")) mach = IntP5MMX; /* sent by */
-         else if (strstr(res, "Pentium")) mach=IntP5;       /* Nakata Maho */
          else if (strstr(res, "iMac4,1")) mach=IntCoreDuo;
+         else if (strstr(res, "Sempron(tm)")) mach = AmdAthlon;
+         else if (strstr(res, "AMD-K6(tm)")) mach = IntP5MMX;
+         else if (strstr(res, "Pentium/P55C")) mach = IntP5MMX;
+         else if (strstr(res, "Pentium/P54C")) mach=IntP5;
+         else if (strstr(res, "Pentium")) mach=IntP5;
+         else if (strstr(res, "VIA"))     mach=IntP5MMX;       
+         else if (strstr(res, "Crusoe(tm)")) mach=IntP5MMX;       
+         else mach = IntP5;
       }
       break;
    default:;
@@ -156,8 +185,8 @@
 {
    int mhz=0;
    char res[1024];
-   if (!CmndOneLine(NULL, "sysctl hw.cpufrequency", res) )
-      mhz = GetFirstLong(res) / 1000000;
+   if (!CmndOneLine(NULL, "sysctl kern.timecounter.choice dev.cpu.0.freq | grep dev", res) ) //requires cpufreq.ko
+      mhz = GetLastInt(res);
    return(mhz);
 }
 
@@ -166,20 +195,7 @@
  * RETURNS: 1 if cpu throttling is detected, 0 otherwise
  */
 {
-   int iret=0;
-   int imax=0, imin=0, icur=0;
-   char res[1024];
-
-   if (!CmndOneLine(NULL, "sysctl hw.cpufrequency_max", res) )
-      imax = GetFirstInt(res);
-   if (!CmndOneLine(NULL, "sysctl hw.cpufrequency_min", res) )
-      imin = GetFirstInt(res);
-   if (imax)
-   {
-      if (imax != imin)
-         iret = 1;
-   }
-   return(iret);
+  return 0;
 }
 
 main(int nargs, char **args)
