--- suphp.c.orig	Wed Dec 25 14:21:27 2002
+++ suphp.c	Sat Jun 28 12:02:12 2003
@@ -68,6 +68,7 @@
 {
  // Check, if program has been started by Apache
  struct passwd *apacheuser;
+ struct group *apachegroup;
  struct passwd *calluser;
  struct passwd *targetuser;
  struct group *targetgroup;
@@ -76,6 +77,7 @@
  path_translated = getenv("SCRIPT_FILENAME");
   
  apacheuser = getpwnam(OPT_APACHE_USER);
+ apachegroup = getgrnam(OPT_APACHE_GROUP);
  calluser = getpwuid(getuid());
  
  if (calluser->pw_uid!=apacheuser->pw_uid)
@@ -105,13 +107,13 @@
  
  // Get gid and uid of the file and check it
  targetuser = getpwuid(file_get_uid(path_translated));
- if (targetuser->pw_uid < OPT_MIN_UID)
+ if (targetuser->pw_uid < OPT_MIN_UID && targetuser->pw_uid != apacheuser->pw_uid )
  {
   log_error ("UID of %s or its target (%d / %s) < %d", path_translated, targetuser->pw_uid, targetuser->pw_name, OPT_MIN_UID);
   error_exit(ERRCODE_LOW_UID);
  }
  targetgroup = getgrgid(file_get_gid(path_translated));
- if (targetgroup->gr_gid < OPT_MIN_GID)
+ if (targetgroup->gr_gid < OPT_MIN_GID && targetgroup->gr_gid != apachegroup->gr_gid )
  {
   log_error ("GID of %s or its target (%d / %s) < %d", path_translated, targetgroup->gr_gid, targetgroup->gr_name, OPT_MIN_GID);
   error_exit(ERRCODE_LOW_GID);
