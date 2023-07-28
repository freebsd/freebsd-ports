--- console/linphonec.c.orig	2023-07-28 13:53:32 UTC
+++ console/linphonec.c
@@ -4,7 +4,7 @@
  * Copyright (C) 2002  Florian Winterstein <flox@gmx.net>
  * Copyright (C) 2000  Simon MORLAT <simon.morlat@free.fr>
  *
- * This file is part of Liblinphone 
+ * This file is part of Liblinphone
  * (see https://gitlab.linphone.org/BC/public/liblinphone).
  *
  * This program is free software: you can redistribute it and/or modify
@@ -962,7 +962,7 @@ static int
  *
  */
 static int
-linphonec_idle_call ()
+linphonec_idle_call (void)
 {
 	LinphoneCore *opm=linphonec;
 
@@ -1272,7 +1272,7 @@ static int
  *	-1 on error
  */
 static int
-handle_configfile_migration()
+handle_configfile_migration(void)
 {
 #if !defined(_WIN32_WCE)
 	char *old_cfg_gui;
