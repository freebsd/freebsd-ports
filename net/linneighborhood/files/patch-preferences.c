--- src/preferences.c.orig	Sun Jun  9 09:58:43 2002
+++ src/preferences.c	Sun Apr  6 13:03:32 2003
@@ -29,6 +29,8 @@
 #include "data.h"
 #include "utility.h"
 #include "samba.h"
+#include <sys/types.h>
+#include <netinet/in.h>
 
 
 #define LVERSION(major,minor,patch) (((((major)<<8)+(minor))<<8)+(patch))
@@ -359,8 +361,8 @@
   strcpy(pref->v.filemanager_exe, "xterm -e mc $MOUNTPOINT");
   strcpy(pref->v.smbclient_exe, "smbclient");
   strcpy(pref->v.nmblookup_exe, "nmblookup");
-  strcpy(pref->v.smbmount_exe, "smbmount");
-  strcpy(pref->v.smbumount_exe, "smbumount");
+  strcpy(pref->v.smbmount_exe, "mount_smbfs");
+  strcpy(pref->v.smbumount_exe, "umount");
   pref->v.smbclient_arg[0] = 0;
   pref->v.nmblookup_arg[0] = 0;
   pref->v.smbmount_arg[0] = 0;
