--- ./src/apcaccess.c.orig	2008-01-27 18:22:58.000000000 +0200
+++ ./src/apcaccess.c	2008-06-29 14:17:12.000000000 +0300
@@ -68,11 +68,19 @@
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
@@ -94,8 +102,23 @@
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
 
+
    if (!*host || strcmp(host, "0.0.0.0") == 0)
       host = "localhost";
 
@@ -108,5 +131,7 @@
       return 1;
    }
 
+   detach_ups(ups);
+
    return 0;
 }
