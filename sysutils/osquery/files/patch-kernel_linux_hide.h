--- kernel/linux/hide.h.orig	2015-05-05 00:16:41 UTC
+++ kernel/linux/hide.h
@@ -1,6 +0,0 @@
-// Copyright 2004-present Facebook. All Rights Reserved.
-
-void rm_mod_from_list(void);
-void rm_mod_from_sysfs(void);
-void rm_mod_from_ddebug_tables(void);
-void hide_me(void);
