--- config.c.orig	Sun Dec 28 12:44:08 2003
+++ config.c	Sun Dec 28 12:54:09 2003
@@ -1188,7 +1188,9 @@
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
@@ -1450,9 +1452,9 @@
          if (THREADS && OS == OSFreeBSD)
          {
             if (which == CPF77)
-               strcat(flag, " -pthread");
+               strcat(flag, " %%PTHREAD_LIBS%%");
             else
-               strcat(flag, " -pthread -D_REENTRANT -D_THREAD_SAFE");
+               strcat(flag, " %%PTHREAD_LIBS%%  %%PTHREAD_CFLAGS%%");
          }
          break;
       case OSSunOS4:
@@ -1984,8 +1986,8 @@
       if (OS == OSFreeBSD)
       {
          if (strstr(comp, "cc"))
-            strcat(flag, " -pthread -D_REENTRANT -D_THREAD_SAFE");
-         else strcat(flag, " -pthread");
+            strcat(flag, " %%PTHREAD_LIBS%% %%PTHREAD_CFLAGS%%");
+         else strcat(flag, " %%PTHREAD_LIBS%%");
       }
    }
    return(*comp ? comp : NULL);
@@ -2801,7 +2801,7 @@
       else if (strstr(ln, "ia64")) la = LAIA64;
       else if ( strstr(ln, "i686") || strstr(ln, "i586") ||
                 strstr(ln, "i486") || strstr(ln, "i386") ||
-                strstr(ln, "x86_64") ) la = LAX86;
+                strstr(ln, "x86_64") || strstr(ln, "amd64")  ) la = LAX86;
    }
    return(la);
 }
@@ -2840,7 +2842,10 @@
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
@@ -2849,14 +2854,22 @@
          if (!CmndOneLine(targ, "sysctl hw.model", ln))
          {
             if (strstr(ln, "Pentium Pro")) mach = IntPPRO;
+            else if (strstr(ln, "Pentium(R) Pro")) mach = IntPPRO;
+            else if (strstr(ln, "Pentium 4")) mach = IntP4;
+            else if (strstr(ln, "Pentium(R) 4")) mach = IntP4;
             else if (strstr(ln, "Pentium III")) mach = IntPIII;
+            else if (strstr(ln, "Pentium(R) III")) mach = IntPIII;
             else if (strstr(ln, "Pentium II ")) mach = IntPII;
+            else if (strstr(ln, "Pentium(R) II ")) mach = IntPII;
+            else if (strstr(ln, "Celeron")) mach = IntPII;
+            else if (strstr(ln, "Celeron(R)")) mach = IntPII;
             else if (strstr(ln, "Athlon")) mach = AmdAthlon;
             else if (strstr(ln, "AMD-K7")) mach = AmdAthlon;
-            else if (strstr(ln, "32 bit Hammer")) mach = AmdHammer32;
-            else if (strstr(ln, "64 bit Hammer")) mach = AmdHammer64;
+            else if (strstr(ln, "Opteron(tm)") && sizeof(void *)==4) mach = AmdHammer32;
+            else if (strstr(ln, "Opteron(tm)") && sizeof(void *)==8) mach = AmdHammer64;
             else if (strstr(ln, "Pentium/P55C")) mach = IntP5MMX; /* sent by */
             else if (strstr(ln, "Pentium")) mach=IntP5;       /* Nakata Maho */
+            else mach = IntP5;
          }
          break;
       default:;
@@ -3654,8 +3654,8 @@
    }
    if (THREADS) /* add ncpu to ARCH */
    {
-      for (i=0; ARCH[i]; i++);
-      sprintf(ARCH+i, "_%d", ncpu);
+//      for (i=0; ARCH[i]; i++); // do not add number of cpu for ARCHNAME
+//      sprintf(ARCH+i, "_%d", ncpu); // #cpu can be different in general
    }
    do
    {
@@ -4064,9 +4063,9 @@
    if (mach == IA64Itan || mach == IA64Itan2 )
       fprintf(fpout, " -DATL_MAXNREG=128");
    if (ASMD != ASM_None) fprintf(fpout, " -DATL_%s", ASMNAM[ASMD]);
-   if (mach == AmdHammer32 && (OS != OSWinNT && OS != OSWin9x))
+   if (mach == AmdHammer32 && (OS != OSWinNT && OS != OSWin9x && OS != OSFreeBSD))
       fprintf(fpout, " -m32");
-   else if (mach == AmdHammer64) fprintf(fpout, " -m64");
+   else if (mach == AmdHammer64 && (OS != OSFreeBSD)) fprintf(fpout, " -m64");
    if (mach == IA64Itan2 && strstr(CC, "icc"))
       fprintf(fpout, " -DATL_IntelIccBugs");
    fprintf(fpout, "\n\n");
@@ -4080,7 +4095,7 @@
    if (THREADS)
    {
       fprintf(fpout, " -DATL_NCPU=%d", ncpu);
-      if (OS == OSFreeBSD) fprintf(fpout, " -D_THREAD_SAFE -D_REENTRANT");
+      if (OS == OSFreeBSD) fprintf(fpout, " %%PTHREAD_CFLAGS%%");
       if (OS == OSAIX) fprintf(fpout, " -DIBM_PT_ERROR");
       if (OS == OSIRIX) fprintf(fpout, " -D_POSIX_C_SOURCE=199506L");
    }
