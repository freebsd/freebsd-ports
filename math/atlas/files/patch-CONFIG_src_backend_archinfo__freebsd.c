--- CONFIG/src/backend/archinfo_freebsd.c.orig	2016-07-28 19:43:01 UTC
+++ CONFIG/src/backend/archinfo_freebsd.c
@@ -62,7 +62,7 @@ enum MACHTYPE ProbeArch()
    switch(fam)
    {
    case AFPPC: /* don't know */
-      res = atlsys_1L(NULL, "sysctl hw.model", 0, 0);
+      res = atlsys_1L(NULL, "sysctl -n hw.model", 0, 0);
       if (res)
       {
          if (strstr(res, "PowerMac"))
@@ -115,7 +115,7 @@ enum MACHTYPE ProbeArch()
    case AFIA64: /* don't know */
       break;
    case AFX86:
-      res = atlsys_1L(NULL, "sysctl hw.model", 0, 0);
+      res = atlsys_1L(NULL, "sysctl -n hw.model", 0, 0);
       if (res)
       {
          if (strstr(res, "Pentium Pro")) mach = IntPPRO;
@@ -140,7 +140,7 @@ int ProbeNCPU()
    int ncpu = 0;
    char *res;
 
-   res = atlsys_1L(NULL, "sysctl hw.ncpu", 0, 0);
+   res = atlsys_1L(NULL, "sysctl -n hw.ncpu", 0, 0);
    if (res)
    {
       ncpu = GetLastInt(res);
@@ -185,7 +185,8 @@ int ProbePointerBits(int *sure)
  *    If uname is a known 64-bit platform, we're sure we've got OS support
  *    for 64bits (may not have compiler support, but that's not our fault)
  */
-      if (strstr(res, "x86_64") || strstr(res, "ppc64") || strstr(res, "ia64"))
+      if (strstr(res, "amd64") || strstr(res, "ia64") || 
+	strstr(res, "powerpc64") || strstr(res, "sparc64"))
       {
          *sure = 1;
          free(res);
@@ -200,13 +201,13 @@ int ProbeMhz()
 {
    int mhz=0;
    char *res;
-   res = atlsys_1L(NULL, "sysctl hw.cpufrequency", 0, 0);
+   res = atlsys_1L(NULL, "sysctl -n dev.cpu.0.freq", 0, 0);
    if (res)
    {
-      mhz = GetFirstDouble(res) / 1000000;
+      mhz = GetFirstInt(res) / 1000000;
       free(res);
    }
-   else if ((res=atlsys_1L(NULL, "sysctl hw.clockrate", 0, 0)))
+   else if ((res=atlsys_1L(NULL, "sysctl -n hw.clockrate", 0, 0)))
    {
       mhz = GetFirstDouble(res);
       free(res);
@@ -219,28 +220,7 @@ int ProbeThrottle()
  * RETURNS: 1 if cpu throttling is detected, 0 otherwise
  */
 {
-   int iret=0;
-   int imax=0, imin=0, icur=0;
-   char *res;
-
-   res = atlsys_1L(NULL, "sysctl hw.cpufrequency_max", 0, 0);
-   if (res)
-   {
-      imax = GetFirstInt(res);
-      free(res);
-   }
-   res = atlsys_1L(NULL, "sysctl hw.cpufrequency_min", 0, 0);
-   if (res)
-   {
-      imin = GetFirstInt(res);
-      free(res);
-   }
-   if (imax)
-   {
-      if (imax != imin)
-         iret = 1;
-   }
-   return(iret);
+   return(0);
 }
 
 main(int nargs, char **args)
