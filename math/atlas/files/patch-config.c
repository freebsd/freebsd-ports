--- config.c.orig	Sun May  4 06:09:23 2003
+++ config.c	Wed Jun 11 12:01:08 2003
@@ -697,7 +697,7 @@
          else if (mach == IA64Itan || MachIsUS(mach) ||
                   mach == Dec21164 || mach == Dec21264)
          {
-            if (major == 3)
+            if ((major == 2 && minor < 96) || (major == 3)) /* Nasty hack for FreeBSD/Alpha STABLE */
             {
                strcpy(goodgcc, files[i]);
                return(0);
@@ -1102,7 +1102,9 @@
    switch(OS)
    {
    case OSOSX:  /* don't know answer */
-   case OSFreeBSD:  /* don't know answer */
+   case OSFreeBSD:
+     if (THREADS) strcpy(LIBS, "%%PTHREAD_LIBS%% -lm");
+     break;
    case OSLinux:
       break;
    case OSSunOS:
@@ -1240,6 +1242,11 @@
                "-mcpu=ultrasparc -mtune=ultrasparc -fomit-frame-pointer -O3");
       }
       if (OS == OSFreeBSD && F77) strcpy(F77, "f77");
+      if (OS == OSFreeBSD && THREADS) { 
+              strcat(F77FLAGS, "%%PTHREAD_CFLAGS%%");
+              strcat(CCFLAGS, "%%PTHREAD_CFLAGS%%");
+              strcat(MMFLAGS, "%%PTHREAD_CFLAGS%%");
+     }
       break;
    case OSSunOS:
       np = 3;
@@ -2104,7 +2111,10 @@
          if (!CmndOneLine(targ, "sysctl hw.model", ln))
          {
             if (strstr(ln, "433au")) mach = Dec21164;
+            else if (strstr(ln, "500au")) mach = Dec21164;
+            else if (strstr(ln, "AlphaPC 164")) mach = Dec21164;
             else if (strstr(ln, "XP1000")) mach = Dec21264;
+            else mach = Dec21264;
          }
          break;
       case LAIA64: /* don't know */
@@ -2113,14 +2123,22 @@
          if (!CmndOneLine(targ, "sysctl hw.model", ln))
          {
             if (strstr(ln, "Pentium Pro")) mach = IntPPRO;
+            else if (strstr(ln, "Pentium(R) Pro")) mach = IntPPRO;
+            else if (strstr(ln, "Pentium 4")) mach = IntP4;
+	    else if (strstr(ln, "Pentium(R) 4")) mach = IntP4;
             else if (strstr(ln, "Pentium III")) mach = IntPIII;
+            else if (strstr(ln, "Pentium(R) III")) mach = IntPIII;
             else if (strstr(ln, "Pentium II ")) mach = IntPII;
+            else if (strstr(ln, "Pentium(R) II ")) mach = IntPII;
+            else if (strstr(ln, "Celeron")) mach = IntPII;
+            else if (strstr(ln, "Celeron(R)")) mach = IntPII;
             else if (strstr(ln, "Athlon")) mach = AmdAthlon;
             else if (strstr(ln, "AMD-K7")) mach = AmdAthlon;
             else if (strstr(ln, "32 bit Hammer")) mach = AmdHammer32;
             else if (strstr(ln, "64 bit Hammer")) mach = AmdHammer64;
             else if (strstr(ln, "Pentium/P55C")) mach = IntP5MMX; /* sent by */
             else if (strstr(ln, "Pentium")) mach=IntP5;       /* Nakata Maho */
+            else mach = IntP5;
          }
          break;
       default:;
@@ -3124,6 +3142,9 @@
    }
    if (USEWINF77) strcpy(F77, "$(BINdir)/winf77.exe");
 
+   fpout = fopen("ARCHNAME", "w");
+   fprintf(fpout, "%s", ARCH);
+   fclose(fpout);
    ATL_mprintf(2, fplog, stdout,"\nCreating make include file Make.%s\n", ARCH);
    sprintf(ln, "Make.%s", ARCH);
    fpout = fopen(ln, "w");
