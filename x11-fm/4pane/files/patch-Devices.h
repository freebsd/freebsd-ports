--- Devices.h.orig	2020-11-22 11:43:42 UTC
+++ Devices.h
@@ -13,7 +13,11 @@
 #include "wx/config.h"
 
 #include <fstab.h>
+#ifdef __linux__
 #include <mntent.h>
+#else
+#include <sys/mount.h>
+#endif
 
 #include "Externs.h"
 
@@ -310,7 +314,11 @@ void OnUnMountNetwork();
 void OnMountSshfs();
 void OnMountSamba();
 void OnUnMountNetwork();
+#ifdef __linux__
 static struct mntent* ReadMtab(const wxString& partition, bool DvdRamFS=false); // Goes thru mtab, to find if 'partition' currently mounted. If DvdRamFS, ignores eg subfs mounts (used for DVD-RAM)
+#else
+static struct statfs* ReadMtab(const wxString& partition, bool DvdRamFS=false);
+#endif
 static struct fstab* ReadFstab(const wxString& dev, const wxString& uuid = "", const wxString& label = ""); // Search fstab for a line for this device
 static struct fstab* ReadFstab(const PartitionStruct* ps) { return ReadFstab(ps->device, ps->uuid, ps->label); }
 static bool FindUnmountedFstabEntry(wxString& dev, wxArrayString& answerarray); // Ditto but only returning Unmounted entries.  Used for DVD-RAM
