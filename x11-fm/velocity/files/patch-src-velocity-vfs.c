--- src/velocity-vfs.c.orig	Tue Aug 26 04:23:50 2003
+++ src/velocity-vfs.c	Mon Mar  1 19:23:34 2004
@@ -31,6 +31,7 @@
 #include <config.h>
 #include <unistd.h>
 #include <sys/types.h>
+#include <sys/param.h> /* for NGROUPS */
 #include <glib.h>
 #include <libgnome/gnome-desktop-item.h>
 #include "velocity-vfs.h"
@@ -240,7 +241,18 @@
 	return((vfsobj->info->uid==getuid()));
 }
 gboolean velocity_vfs_is_in_group(velocity_vfs_obj*vfsobj){
-	return((vfsobj->info->gid==getgid()));
+	/* 24 feb 2004 : Henri Michelon hmichelon at e-cml dot org
+	   A patch to use the full list of groups on *BSD */
+	int cnt, ngroups;
+	gid_t groups[NGROUPS];
+	if ((ngroups = getgroups(NGROUPS, groups))) {
+		for (cnt = 0; cnt < ngroups; cnt++) {
+			if (vfsobj->info->gid==groups[cnt]) {
+				return(TRUE);
+			}
+		}
+	}
+	return(FALSE);
 }
 gboolean velocity_vfs_is_local(velocity_vfs_obj*vfsobj){
 	return(GNOME_VFS_FILE_INFO_LOCAL(vfsobj->info));
