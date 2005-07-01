--- config.c.orig	Sun Apr 24 22:31:53 2005
+++ config.c	Tue Jun 28 16:46:54 2005
@@ -686,7 +686,10 @@
    {
       if (strstr(ln2, "Apple Computer"))
          *comp = 3;
-      *major = GetIntVers(ln2, &j);
+
+      j=0;if(isalpha(ln2[0])){for(i=0;!isspace(ln2[i]);i++)j++;} /*skip gccXXX ; XXX is number*/
+      for (i=j; !isdigit(ln2[i]); i++) j++;
+      *major = GetIntVers(ln2+j, &i); j += i;
       if (*major != -1)
       {
          *minor = GetIntVers(ln2+j, &i); j += i;
@@ -1044,6 +1044,8 @@
    {
       if (strstr(ln, "x86_64"))
          iret = 1;
+      if (strstr(ln, "amd64"))
+         iret = 1;
       else if (strstr(ln, "ppc64"))
          iret = 2;
    }
@@ -1229,7 +1232,9 @@
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
@@ -1494,9 +1499,9 @@
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
@@ -2113,8 +2118,8 @@
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
@@ -2756,7 +2761,7 @@
       break;
    case IntP4:
       lf1 = l1 = 64;
-      lf2 = l2 = 512;
+      lf2 = l2 = 4096;
       s1 = 0;
       s2 = 0;
       break;
@@ -2860,6 +2865,7 @@
       l1 = l2 = s1 = s2 = 0;
       lf2 = 4096;
    }
+   s1 = 0; // XXX always calculate L1 cache size
    if (lvl == 1)
    {
       if (AmSure) *AmSure = s1;
@@ -2977,7 +2983,7 @@
       else if (strstr(ln, "ia64")) la = LAIA64;
       else if ( strstr(ln, "i686") || strstr(ln, "i586") ||
                 strstr(ln, "i486") || strstr(ln, "i386") ||
-                strstr(ln, "x86_64") ) la = LAX86;
+                strstr(ln, "x86_64") || strstr(ln, "amd64")  ) la = LAX86;
    }
    return(la);
 }
@@ -3006,6 +3012,9 @@
    else
       sprintf(ln2,
          "cd CONFIG ; make IRunx86Info mydir=%s/CONFIG | fgrep cpu", TOPdir);
+
+   if (%%HAVE_ARCH%%) {mach = %%PORTS_ARCH%%; return(mach); }
+
    if ( !CmndOneLine(NULL, ln2, ln) )
    {
       if (strstr(ln, "Pentium 4E64"))
@@ -3047,12 +3056,22 @@
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
@@ -3060,15 +3079,35 @@
       case LAX86:
          if (!CmndOneLine(targ, "sysctl hw.model", ln))
          {
+//         mach = Use64Bits ? IntP4E64 : IntP4E; #EM64T
+//         mach = IntP4E;                #prescott
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
@@ -3922,8 +3961,8 @@
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
@@ -4371,7 +4410,7 @@
    if (THREADS)
    {
       fprintf(fpout, " -DATL_NCPU=%d", ncpu);
-      if (OS == OSFreeBSD) fprintf(fpout, " -D_THREAD_SAFE -D_REENTRANT");
+      if (OS == OSFreeBSD) fprintf(fpout, " %%PTHREAD_CFLAGS%%");
       if (OS == OSAIX) fprintf(fpout, " -DIBM_PT_ERROR");
       if (OS == OSIRIX) fprintf(fpout, " -D_POSIX_C_SOURCE=199506L");
    }
