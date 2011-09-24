--- CONFIG/src/backend/archinfo_freebsd.c.orig	2011-05-14 13:33:24.000000000 -0400
+++ CONFIG/src/backend/archinfo_freebsd.c	2011-09-20 07:05:52.000000000 -0400
@@ -62,7 +62,7 @@
    switch(fam)
    {
    case AFPPC: /* don't know */
-      if (!CmndOneLine(NULL, "sysctl hw.model", res))
+      if (!CmndOneLine(NULL, "sysctl -n hw.model", res))
       {
          if (strstr(res, "PowerMac"))
          {
@@ -97,32 +97,57 @@
          }
       }
       break;
-   case AFSPARC: /* don't know */
-      break;
-   case AFALPHA:
-      #if 0
-      if (!CmndOneLine(NULL, "sysctl hw.model", res))
+   case AFSPARC: /* from src/sys/sparc64/sparc64/identcpu.c */
+      if (!CmndOneLine(NULL, "sysctl -n hw.model", res))
       {
-         if (strstr(res, "433au")) mach = Dec21164;
-         else if (strstr(res, "XP1000")) mach = Dec21264;
+          if (strstr(res, "UltraSparc-IV"))  mach = SunUSIV;
+          else if (strstr(res, "UltraSparc-III"))  mach = SunUSIII;
+          else if (strstr(res, "UltraSparc-II")) mach = SunUSII;
+          else mach = SunUSI;
       }
-      #endif
       break;
-   case AFIA64: /* don't know */
+   case AFIA64: /* from src/sys/ia64/ia64/machdep.c */
+	if (!CmndOneLine(NULL, "sysctl -n hw.model", res))
+      {
+	 if (strstr(res, "Deerfield")) mach = IA64Itan2;
+	 else if (strstr(res, "McKinley")) mach = IA64Itan2;
+	 else if (strstr(res, "Madison")) mach = IA64Itan2;
+	 else if (strstr(res, "Montecito")) mach = IA64Itan2;
+	 else if (strstr(res, "Montvale")) mach = IA64Itan2;
+         else if (strstr(res, "Merced")) mach = IA64Itan;
+      }	   
       break;
    case AFX86:
-      if (!CmndOneLine(NULL, "sysctl hw.model", res))
+      if (!CmndOneLine(NULL, "sysctl -n hw.model", res))
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
@@ -135,7 +160,7 @@
    int ncpu = 0;
    char *reslns, res[1024];
 
-   if (!CmndOneLine(NULL, "sysctl hw.ncpu", res)) ncpu = GetLastInt(res);
+   if (!CmndOneLine(NULL, "sysctl -n hw.ncpu", res)) ncpu = GetFirstInt(res);
    return(ncpu);
 }
 
@@ -169,7 +194,8 @@
  *    If uname is a known 64-bit platform, we're sure we've got OS support
  *    for 64bits (may not have compiler support, but that's not our fault)
  */
-      if (strstr(res, "x86_64") || strstr(res, "ppc64") || strstr(res, "ia64"))
+      if (strstr(res, "amd64") || strstr(res, "ia64") || 
+	strstr(res, "powerpc64") || strstr(res, "sparc64"))
       {
          iret = 64;
          *sure = 1;
@@ -182,8 +208,10 @@
 {
    int mhz=0;
    char res[1024];
-   if (!CmndOneLine(NULL, "sysctl hw.cpufrequency", res) )
-      mhz = GetFirstDouble(res) / 1000000;
+   if (!CmndOneLine(NULL, "sysctl -n dev.cpu.0.freq", res) )
+      mhz = GetFirstInt(res);
+   else if (!CmndOneLine(NULL, "sysctl -n hw.freq.cpu", res) )
+      mhz = GetFirstInt(res);
    return(mhz);
 }
 
@@ -192,20 +220,7 @@
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
+   return(0);
 }
 
 main(int nargs, char **args)
