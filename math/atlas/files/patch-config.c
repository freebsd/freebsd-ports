--- config.c.orig	Mon Dec 22 23:06:32 2003
+++ config.c	Sat Mar 27 14:47:04 2004
@@ -666,7 +666,9 @@
    sprintf(ln, "%s --version", gcc);
    if (CmndOneLine(NULL, ln, ln2) == 0)
    {
-      *major = GetIntVers(ln2, &j);
+      j=0;if(isalpha(ln2[0])){for(i=0;!isspace(ln2[i]);i++)j++;} /*skip gccXXX ; XXX is number*/
+      for (i=j; !isdigit(ln2[i]); i++) j++;
+      *major = GetIntVers(ln2+j, &i); j += i;
       if (*major != -1)
       {
          *minor = GetIntVers(ln2+j, &i); j += i;
@@ -1188,7 +1190,9 @@
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
@@ -1450,9 +1454,9 @@
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
@@ -1984,8 +1988,8 @@
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
@@ -2587,7 +2587,7 @@
       break;
    case IntP4:
       lf1 = l1 = 64;
-      lf2 = l2 = 512;
+      lf2 = l2 = 4096;
       s1 = 0;
       s2 = 0;
       break;
@@ -2687,6 +2687,7 @@
       l1 = l2 = s1 = s2 = 0;
       lf2 = 4096;
    }
+   s1 = 0; // XXX always calculate L1 cache size
    if (lvl == 1)
    {
       if (AmSure) *AmSure = s1;
@@ -2799,7 +2803,7 @@
       else if (strstr(ln, "ia64")) la = LAIA64;
       else if ( strstr(ln, "i686") || strstr(ln, "i586") ||
                 strstr(ln, "i486") || strstr(ln, "i386") ||
-                strstr(ln, "x86_64") ) la = LAX86;
+                strstr(ln, "x86_64") || strstr(ln, "amd64")  ) la = LAX86;
    }
    return(la);
 }
@@ -2835,12 +2839,22 @@
          }
          break;
       case LASPARC: /* don't know */
+         if (!CmndOneLine(targ, "sysctl hw.model", ln))
+         {
+            if (strstr(ln, "UltraSparc-II")) mach = SunUS2;
+            if (strstr(ln, "UltraSparc-I")) mach = SunUS1;
+            if (strstr(ln, "UltraSparc")) mach = SunUSX;
+            else mach = SunUSX;
+         }
          break;
       case LAALPHA:
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
@@ -2849,14 +2863,32 @@
          if (!CmndOneLine(targ, "sysctl hw.model", ln))
          {
             if (strstr(ln, "Pentium Pro")) mach = IntPPRO;
+            else if (strstr(ln, "Pentium(R) Pro")) mach = IntPPRO;
+            else if (strstr(ln, "Pentium 4")) mach = IntP4;
+            else if (strstr(ln, "Pentium(R) 4")) mach = IntP4;
+            else if (strstr(ln, "Pentium(R) M")) mach = IntP4;
             else if (strstr(ln, "Pentium III")) mach = IntPIII;
-            else if (strstr(ln, "Pentium II ")) mach = IntPII;
+            else if (strstr(ln, "Pentium III/Pentium III")) mach = IntPIII;
+            else if (strstr(ln, "Pentium(R) III")) mach = IntPIII;
+            else if (strstr(ln, "Pentium II")) mach = IntPII;
+            else if (strstr(ln, "Pentium II/PentiumII")) mach = IntPII;
+            else if (strstr(ln, "Pentium(R) II ")) mach = IntPII;
+            else if (strstr(ln, "Celeron")) mach = IntPII;
+            else if (strstr(ln, "Celeron(R)")) mach = IntPII;
+            else if (strstr(ln, "Opteron(tm)") && sizeof(void *)==4) mach = AmdHammer32;
+            else if (strstr(ln, "Opteron(tm)") && sizeof(void *)==8) mach = AmdHammer64;
+            else if (strstr(ln, "AMD Athlon(tm) 64") && sizeof(void *)==4) mach = AmdHammer32;
+            else if (strstr(ln, "AMD Athlon(tm) 64") && sizeof(void *)==8) mach = AmdHammer64;
+            else if (strstr(ln, "Athlon(tm)")) mach = AmdAthlon;
             else if (strstr(ln, "Athlon")) mach = AmdAthlon;
             else if (strstr(ln, "AMD-K7")) mach = AmdAthlon;
-            else if (strstr(ln, "32 bit Hammer")) mach = AmdHammer32;
-            else if (strstr(ln, "64 bit Hammer")) mach = AmdHammer64;
-            else if (strstr(ln, "Pentium/P55C")) mach = IntP5MMX; /* sent by */
-            else if (strstr(ln, "Pentium")) mach=IntP5;       /* Nakata Maho */
+            else if (strstr(ln, "AMD-K6(tm)")) mach = IntP5MMX;
+            else if (strstr(ln, "Pentium/P55C")) mach = IntP5MMX;
+            else if (strstr(ln, "Pentium/P54C")) mach=IntP5;
+            else if (strstr(ln, "Pentium")) mach=IntP5;
+            else if (strstr(ln, "VIA"))     mach=IntP5MMX;       
+            else if (strstr(ln, "Crusoe(tm)")) mach=IntP5MMX;       
+            else mach = IntP5;
          }
          break;
       default:;
@@ -3641,8 +3673,8 @@
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
@@ -4047,9 +4079,9 @@
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
@@ -4080,7 +4112,7 @@
    if (THREADS)
    {
       fprintf(fpout, " -DATL_NCPU=%d", ncpu);
-      if (OS == OSFreeBSD) fprintf(fpout, " -D_THREAD_SAFE -D_REENTRANT");
+      if (OS == OSFreeBSD) fprintf(fpout, " %%PTHREAD_CFLAGS%%");
       if (OS == OSAIX) fprintf(fpout, " -DIBM_PT_ERROR");
       if (OS == OSIRIX) fprintf(fpout, " -D_POSIX_C_SOURCE=199506L");
    }
