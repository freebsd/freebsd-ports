--- src/portscan-pilot.adb.orig	2016-03-27 14:03:52 UTC
+++ src/portscan-pilot.adb
@@ -275,9 +275,6 @@ package body PortScan.Pilot is
         (repository => JT.USS (PM.configuration.dir_repository),
          dry_run    => dry_run, suppress_remote => block_remote);
       bld_counter := (OPS.queue_length, 0, 0, 0, 0);
-      if PKG.queue_is_empty then
-         return False;
-      end if;
       if dry_run then
          return True;
       end if;
