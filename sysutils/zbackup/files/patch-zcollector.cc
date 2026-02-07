--- zcollector.cc.orig	2016-01-02 22:43:40.800025000 +0800
+++ zcollector.cc	2016-01-02 22:44:51.222600000 +0800
@@ -1,6 +1,8 @@
 // Copyright (c) 2012-2014 Konstantin Isakov <ikm@zbackup.org> and ZBackup contributors, see CONTRIBUTORS
 // Part of ZBackup. Licensed under GNU GPLv2 or later + OpenSSL, see LICENSE
 
+#include <unistd.h>
+
 #include "zcollector.hh"
 
 #include "backup_restorer.hh"
