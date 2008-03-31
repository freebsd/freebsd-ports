--- src/apcaccess.c.orig	2007-08-03 18:17:38.000000000 +0300
+++ src/apcaccess.c	2008-02-27 09:30:39.352400647 +0200
@@ -62,11 +62,19 @@
 int main(int argc, char **argv)
 {
    int mode = 0;
+   UPSINFO *ups = NULL;
+
+   char *cfgfile = APCCONF;
+   struct stat cfgstat;
 
 #ifdef HAVE_MINGW
    WSA_Init();                   /* init MS networking */
 #endif
 
+   ups = attach_ups(ups);
+   if (!ups)
+      Error_abort0(_("Cannot attach SYSV IPC.\n"));
+
    if (argc < 2) {
       /* Assume user wants "status" */
       mode = 2;
@@ -87,6 +95,20 @@
          *p++ = 0;
          port = atoi(p);
       }
+   } else {
+      /* check configuration so local NISIP and NISPORT variables can be used as
+ defaults */
+      if (!stat(cfgfile, &cfgstat)) {
+         check_for_config(ups, cfgfile);
+
+         if (ups) {
+            if (ups->nisip && ups->nisip[0])
+               host = ups->nisip;
+
+            if (ups->statusport)
+               port = ups->statusport;
+         }
+      }
    }
 
    if (!*host || strcmp(host, "0.0.0.0") == 0)
@@ -101,5 +123,7 @@
       Error_abort0(_("Strange mode\n"));
    }
 
+   detach_ups(ups);
+
    return 0;
 }
