
$FreeBSD$

--- libnautilus-private/nautilus-volume-monitor.c	2001/10/26 06:06:21	1.1
+++ libnautilus-private/nautilus-volume-monitor.c	2001/10/26 07:39:01
@@ -60,6 +60,18 @@
 #include <sys/types.h>
 #include <unistd.h>
 
+#ifdef __FreeBSD__
+#include <sys/param.h>
+#include <sys/ucred.h>
+#include <sys/mount.h>
+
+#define HAVE_GETMNTINFO
+#define HAVE_SETFSENT
+#define HAVE_FSTAB_H
+#define FREEBSD_MNT
+#define setmntent(f,m) setfsent()
+#endif
+
 #ifdef HAVE_SYS_VFSTAB_H
 #include <sys/vfstab.h>
 #else
@@ -104,7 +116,7 @@
 #define MNTOPT_RO "ro"
 #endif
 
-#ifndef HAVE_SETMNTENT
+#if !defined(HAVE_SETMNTENT) &&  !defined(HAVE_SETFSENT)
 #define setmntent(f,m) fopen(f,m)
 #endif
 
@@ -495,6 +507,11 @@
 		return TRUE;
 	}
 #endif
+#ifdef __FreeBSD__
+	if (eel_str_has_prefix (ent->f_mntonname, "/.amd_mnt/")) {
+		return TRUE;
+	}
+#endif
 	
 	return FALSE;
 }
@@ -510,16 +527,18 @@
 static GList *
 get_removable_volumes (NautilusVolumeMonitor *monitor)
 {
+#ifndef HAVE_SETFSENT
 	FILE *file;
-	GList *volumes;
-	MountTableEntry *ent;
-	NautilusVolume *volume;
+#else
+	int file;
+	struct fstab *fsent;
+#endif
+	GList *volumes = NULL;
+	MountTableEntry *ent = NULL;
+	NautilusVolume *volume = NULL;
 #ifdef HAVE_SYS_MNTTAB_H
         MountTableEntry ent_storage;
 #endif
-	ent = NULL;
-	volume = NULL;
-	volumes = NULL;
 
 #ifdef HAVE_GETMNTINFO
 	int count, index;
@@ -529,16 +548,20 @@
 	for (index = 0; index < count; index++) {
 		if (has_removable_mntent_options (ent + 1)) {
 			volume = create_volume (ent[index].f_mntfromname,
-						ent[index].f_mntoname);
+						ent[index].f_mntonname);
 			volume->is_removable = TRUE;
 			volumes = finish_creating_volume_and_prepend
-				(monitor, volume, ent[index].f_fstyename, volumes);
+				(monitor, volume, ent[index].f_fstypename, volumes);
 		}
 	}
 #endif
 	
 	file = setmntent (MOUNT_TABLE_PATH, "r");
+#ifndef HAVE_SETFSENT
 	if (file == NULL) {
+#else
+	if (file == 0) {
+#endif
 		return NULL;
 	}
 	
@@ -560,9 +583,21 @@
 				(monitor, volume, ent->mnt_type, volumes);
 		}
 	}
+#elif defined (HAVE_SETFSENT)
+	while ((fsent = getfsent ()) != NULL) {
+		if (strstr (fsent->fs_mntops, "noauto") == 0) {
+			volume = create_volume (fsent->fs_spec, fsent->fs_file);
+			volumes = finish_creating_volume_and_prepend
+				(monitor, volume, fsent->fs_vfstype, volumes);
+		}
+	}
 #endif
 			
+#ifndef HAVE_SETFSENT
 	fclose (file);
+#else
+	endfsent();
+#endif
 	
 #ifdef HAVE_CDDA
 	volume = create_volume (CD_AUDIO_PATH, CD_AUDIO_PATH);
@@ -575,7 +610,7 @@
 	return g_list_sort (g_list_reverse (volumes), (GCompareFunc) floppy_sort);
 }
 
-#ifndef SOLARIS_MNT
+#if !defined(SOLARIS_MNT) && !defined(FREEBSD_MNT)
 
 static gboolean
 volume_is_removable (const NautilusVolume *volume)
@@ -907,23 +942,33 @@
 
 
 
-#ifdef SOLARIS_MNT
+#if defined(SOLARIS_MNT) || defined(FREEBSD_MNT)
 
 static GList *
 get_mount_list (NautilusVolumeMonitor *monitor) 
 {
-        FILE *fh;
         GList *volumes;
+#ifndef HAVE_SETFSENT
+        FILE *fh;
         MountTableEntry ent;
+#else
+	int fh;
+	struct fstab *ent;
+#endif
         NautilusVolume *volume;
 
 	volumes = NULL;
         
 	fh = setmntent (MOUNT_TABLE_PATH, "r");
+#ifndef HAVE_SETFSENT
 	if (fh == NULL) {
+#else
+	if (fh == 0) {
+#endif
 		return NULL;
 	}
 
+#ifndef HAVE_SETFSENT
         while (! getmntent(fh, &ent)) {
                 volume = create_volume (ent.mnt_special, ent.mnt_mountp);
                 volume->is_removable = has_removable_mntent_options (&ent);
@@ -932,6 +977,20 @@
         }
 
 	fclose (fh);
+#else
+	while ((ent = getfsent ()) != NULL) {
+		volume = create_volume (ent->fs_spec, ent->fs_file);
+		if (strstr (ent->fs_mntops, "noauto") == 0)
+			volume->is_removable = TRUE;
+		else
+			volume->is_removable = FALSE;
+		volumes = finish_creating_volume_and_prepend
+			(monitor, volume, ent->fs_vfstype, volumes);
+	}
+
+	endfsent();
+#endif
+
 
         return volumes;
 }
@@ -1668,7 +1727,7 @@
 	for (node = volume_list; node != NULL; node = node->next) {
 		volume = node->data;
 		
-#ifndef SOLARIS_MNT
+#if !defined(SOLARIS_MNT) && !defined(FREEBSD_MNT)
 		/* These are set up by get_current_mount_list for Solaris. */
 		volume->is_removable = volume_is_removable (volume);
 #endif
