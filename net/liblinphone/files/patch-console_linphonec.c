--- console/linphonec.c.orig	2023-02-11 23:13:07 UTC
+++ console/linphonec.c
@@ -965,7 +965,7 @@ static int
  *
  */
 static int
-linphonec_idle_call ()
+linphonec_idle_call (void)
 {
 	LinphoneCore *opm=linphonec;
 
@@ -1274,7 +1274,7 @@ static int
  *	-1 on error
  */
 static int
-handle_configfile_migration()
+handle_configfile_migration(void)
 {
 #if !defined(_WIN32_WCE)
 	char *old_cfg_gui;
@@ -1555,4 +1555,3 @@ lpc_strip_blanks(char *input)
  *
  *
  ****************************************************************************/
-
