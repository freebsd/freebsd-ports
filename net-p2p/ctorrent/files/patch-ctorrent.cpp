--- ctorrent.cpp.orig	2009-11-13 10:20:39.377057366 +0300
+++ ctorrent.cpp	2009-11-13 10:21:01.916290662 +0300
@@ -98,11 +98,11 @@
     exit(0);
   }
 
-  if( arg_daemon ) CONSOLE.Daemonize();
-
   if( !arg_flg_exam_only && (!arg_flg_check_only || arg_flg_force_seed_mode) )
     if( arg_ctcs ) CTCS.Initial();
   
+  if( arg_daemon ) CONSOLE.Daemonize();
+
   if( BTCONTENT.InitialFromMI(arg_metainfo_file, arg_save_as) < 0){
     CONSOLE.Warning(1, "error, initial meta info failed.");
     exit(1);

