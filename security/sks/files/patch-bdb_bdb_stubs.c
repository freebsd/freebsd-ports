--- bdb/bdb_stubs.c.orig	Thu Oct 21 04:56:02 2004
+++ bdb/bdb_stubs.c	Sat Nov 20 16:33:08 2004
@@ -223,7 +223,7 @@
 
 // Declaration of flag enums in ocaml must be in same order as in C
 
-static int dbenv_create_flags[] = { DB_CLIENT };
+static int dbenv_create_flags[] = { DB_RPCCLIENT };
 
 //+
 //+   type create_flag = CLIENT
