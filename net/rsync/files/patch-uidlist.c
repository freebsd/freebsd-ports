#
# Fixed the use of an uninitialized variable in map_uid() and map_gid().
# <http://lists.samba.org/archive/rsync/2004-April/009334.html>
#
--- uidlist.c	20 Feb 2004 17:09:30 -0000	1.23
+++ uidlist.c	28 Apr 2004 17:04:55 -0000
@@ -81,7 +81,7 @@ static char *gid_to_name(gid_t gid)
 static int map_uid(int id, char *name)
 {
 	uid_t uid;
-	if (uid != 0 && name_to_uid(name, &uid))
+	if (id != 0 && name_to_uid(name, &uid))
 		return uid;
 	return id;
 }
@@ -89,7 +89,7 @@ static int map_uid(int id, char *name)
 static int map_gid(int id, char *name)
 {
 	gid_t gid;
-	if (gid != 0 && name_to_gid(name, &gid))
+	if (id != 0 && name_to_gid(name, &gid))
 		return gid;
 	return id;
 }
