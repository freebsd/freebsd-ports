--- libnautilus-private/nautilus-volume-monitor.c.orig	Wed Aug 28 09:37:20 2002
+++ libnautilus-private/nautilus-volume-monitor.c	Tue Sep 10 16:37:32 2002
@@ -59,6 +59,18 @@
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
@@ -103,7 +115,7 @@
 #define MNTOPT_RO "ro"
 #endif
 
-#ifndef HAVE_SETMNTENT
+#if !defined(HAVE_SETMNTENT) &&  !defined(HAVE_SETFSENT)
 #define setmntent(f,m) fopen(f,m)
 #endif
 
@@ -501,6 +513,11 @@
 		return TRUE;
 	}
 #endif
+#ifdef __FreeBSD__
+	if (eel_str_has_prefix (ent->f_mntonname, "/mnt/")) {
+	    	return TRUE;
+	}
+#endif
 
 #ifdef SOLARIS_MNT
 	if (eel_str_has_prefix (ent->mnt_special, "/vol/")) {
@@ -522,10 +539,15 @@
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
 	char * fs_opt;
 #ifdef HAVE_SYS_MNTTAB_H
         MountTableEntry ent_storage;
@@ -533,26 +555,27 @@
 #ifdef HAVE_GETMNTINFO
 	int count, index;
 #endif
-	ent = NULL;
-	volume = NULL;
-	volumes = NULL;
 
 #ifdef HAVE_GETMNTINFO
 	count = getmntinfo (&ent, MNT_WAIT);
 	/* getmentinfo returns a pointer to static data. Do not free. */
 	for (index = 0; index < count; index++) {
-		if (has_removable_mntent_options (&ent[index])) {
+		if (has_removable_mntent_options (ent + index)) {
 			volume = create_volume (ent[index].f_mntfromname,
 						ent[index].f_mntonname);
 			volume->is_removable = TRUE;
 			volumes = finish_creating_volume_and_prepend
-				(monitor, volume, ent[index].f_fstypename, volumes);
+		    		(monitor, volume, ent[index].f_fstypename, volumes);
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
 	
@@ -587,9 +610,21 @@
 				(monitor, volume, ent->mnt_type, volumes);
 		}
 	}
+#elif defined (HAVE_SETFSENT)
+	while ((fsent = getfsent ()) != NULL) {
+	    	if (strstr (fsent->fs_mntops, "noauto") != NULL) {
+		    	volume = create_volume (fsent->fs_spec, fsent->fs_file);
+			volumes = finish_creating_volume_and_prepend
+				(monitor, volume, fsent->fs_vfstype, volumes);
+		}
+	}
 #endif
-			
+
+#ifndef HAVE_SETFSENT
 	fclose (file);
+#else
+	endfsent();
+#endif
 	
 #ifdef HAVE_CDDA
 	volume = create_volume (CD_AUDIO_PATH, CD_AUDIO_PATH);
@@ -619,7 +654,7 @@
       return result;
 }
 
-#ifndef SOLARIS_MNT
+#if !defined(SOLARIS_MNT) && !defined(FREEBSD_MNT)
 
 static gboolean
 volume_is_removable (const NautilusVolume *volume)
@@ -963,23 +998,34 @@
 
 
 
-#ifdef SOLARIS_MNT
+#if defined(SOLARIS_MNT) || defined(FREEBSD_MNT)
 
 static GList *
 get_mount_list (NautilusVolumeMonitor *monitor) 
 {
-        FILE *fh;
         GList *volumes;
+#ifndef HAVE_SETFSENT
         MountTableEntry ent;
+	FILE *fh;
+#else
+        MountTableEntry *ent;
+	int fh, index;
+#endif
         NautilusVolume *volume;
 
 	volumes = NULL;
         
+#ifndef HAVE_SETFSENT
 	fh = setmntent (MOUNT_TABLE_PATH, "r");
 	if (fh == NULL) {
+#else
+        fh = getmntinfo (&ent, MNT_WAIT);
+	if (fh == 0) {
+#endif
 		return NULL;
 	}
 
+#ifndef HAVE_SETFSENT
         while (! getmntent(fh, &ent)) {
                 volume = create_volume (ent.mnt_special, ent.mnt_mountp);
                 volume->is_removable = has_removable_mntent_options (&ent);
@@ -988,6 +1034,16 @@
         }
 
 	fclose (fh);
+#else
+        /* getmentinfo returns a pointer to static data. Do not free. */
+        for (index = 0; index < fh; index++) {
+		volume = create_volume (ent[index].f_mntfromname,
+					ent[index].f_mntonname);
+                volume->is_removable = has_removable_mntent_options (ent + index);
+                volumes = finish_creating_volume_and_prepend
+					(monitor, volume, ent[index].f_fstypename, volumes);
+        }
+#endif
 
         return volumes;
 }
@@ -1765,7 +1821,7 @@
 	for (node = volume_list; node != NULL; node = node->next) {
 		volume = node->data;
 		
-#ifndef SOLARIS_MNT
+#if !defined(SOLARIS_MNT) && !defined(FREEBSD_MNT)
 		/* These are set up by get_current_mount_list for Solaris. */
 		volume->is_removable = volume_is_removable (volume);
 #endif
@@ -1794,7 +1850,7 @@
 		ok = mount_volume_auto_add (volume);
 	} else if (strcmp (file_system_type_name, "cdda") == 0) {
 		ok = mount_volume_cdda_add (volume);
-	} else if (strcmp (file_system_type_name, "iso9660") == 0) {
+	} else if (strcmp (file_system_type_name, "cd9660") == 0) {
 		ok = mount_volume_iso9660_add (volume);
 	} else if (strcmp (file_system_type_name, "nfs") == 0) {
 		ok = mount_volume_nfs_add (volume);
@@ -1823,8 +1879,8 @@
 	}
 
 	/* Identify device type */
-	if (eel_str_has_prefix (volume->mount_path, "/mnt/")) {		
-		name = volume->mount_path + strlen ("/mnt/");
+	if (eel_str_has_prefix (volume->mount_path, "/")) {		
+		name = volume->mount_path + strlen ("/");
 		
 		if (eel_str_has_prefix (name, "cdrom")
 				|| eel_str_has_prefix (name, "burn")) {
