--- t/05_register.t.orig	Mon May 17 22:48:40 2004
+++ t/05_register.t	Mon May 17 22:49:30 2004
@@ -1,4 +1,4 @@
-use Test::More qw[no_plan];
+use Test::More tests => 3;
 
 use Email::FolderType::Register qw[register_type];
 use Email::FolderType qw[folder_type];
