--- lxdvdrip.c.orig	Wed Jan 12 23:31:49 2005
+++ lxdvdrip.c	Wed Jan 26 21:31:51 2005
@@ -229,6 +229,11 @@
 #include <string.h>
 #include <sys/stat.h>
 #include <sys/types.h>
+#include <sys/param.h>
+#include <sys/mount.h>
+#ifndef __FreeBSD__
+#include <sys/statfs.h>
+#endif
 #include <stdio.h>
 #include <stdlib.h>
 #include <unistd.h>
@@ -621,16 +626,19 @@
 // Gibt die Groesse einer Datei zurueck, ohne die stat Beschraenkung auf < 2 GB
 long long filesize64 (char * szFileName)
 {
+#ifdef __FreeBSD__
+  struct stat buf;
+
+  if (stat(szFileName, &buf) < 0)
+    return 0LL;
+
+  return buf.st_size;
+#else
   FILE * fp;
   long long lSize;
   char szBuffer[128];
   char szTempl[32] = "/tmp/groesse.lxdvdrip";
-// FreeBSD hat fopen64 als Standard
-#ifdef _FREEBSD
-  fp = (FILE*)fopen (szFileName, "rb");
-#else
   fp = (FILE*)fopen64 (szFileName, "rb");
-#endif
   if (!fp)
   {
     return (long long)0;
@@ -644,39 +652,28 @@
   system ("rm /tmp/groesse.lxdvdrip");
   lSize = atoll (szBuffer);
   return lSize;
+#endif
 }
 
 // Berechnet freien Festplattenplatz
 long long calculate_discfree (char * szPfad, long lSprache)
 {
-  char szTempl[32] = "/tmp/lxdf.lxdvdrip";
-  char szBefehl[1024];
+  struct statfs buf;
   long long lGroesse=0;
-  sprintf (szBefehl, "stat -f %s -c ", szPfad);
-  strcat (szBefehl, "'%a %s' > ");
-  strcat (szBefehl, szTempl);
-  if (system (szBefehl) == 0)
+
+  if (statfs(szPfad, &buf) < 0)
+    return 0;
+
+  lGroesse = buf.f_bavail*buf.f_bsize;
+
+  switch (lSprache)
   {
-    FILE * fTmp;
-    long long lFrei;
-    long long lBlockGroesse;
-    fTmp = fopen(szTempl,"r");
-    if (fTmp)
-    {
-      fscanf (fTmp, "%lld %lld", &lFrei, &lBlockGroesse);
-      fclose (fTmp);
-      lGroesse = lFrei * lBlockGroesse;
-    }
-    system ("rm /tmp/lxdf.lxdvdrip");
-    switch (lSprache)
-    {
-      case 0: printf ("Frei in %s: %lld Bytes\n", szPfad, lGroesse);
-        break;
-      case 1: printf ("Free in %s: %lld Bytes\n", szPfad, lGroesse);
-        break;
-      case 2: printf ("Espace libre sur %s: %lld octets\n", szPfad, lGroesse);
-        break;
-    }
+    case 0: printf ("Frei in %s: %lld Bytes\n", szPfad, lGroesse);
+      break;
+    case 1: printf ("Free in %s: %lld Bytes\n", szPfad, lGroesse);
+      break;
+    case 2: printf ("Espace libre sur %s: %lld octets\n", szPfad, lGroesse);
+      break;
   }
   return lGroesse;
 }
