--- ctorrent.cpp.orig	2008-06-15 00:00:19 UTC
+++ ctorrent.cpp
@@ -98,11 +98,11 @@ int main(int argc, char **argv)
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
