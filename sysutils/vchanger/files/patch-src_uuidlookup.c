--- src/uuidlookup.c.orig	2017-01-06 15:55:06 UTC
+++ src/uuidlookup.c
@@ -215,7 +215,7 @@ static int GetDevMountpoint(char *mountp
    for (n = 0; n < mcount; n++)
    {
       if (strcasecmp(devname, fs[n].f_mntfromname) == 0) {
-         strncpy(mountp, fs[n].f_mnttoname, mountp_sz);
+         strncpy(mountp, fs[n].f_mntonname, mountp_sz);
          rc = 0;
       }
    }
