--- xa_vid_codec.c.orig	2002-04-20 23:20:46 UTC
+++ xa_vid_codec.c
@@ -169,7 +169,9 @@ static void Check_For_Video_Modules()
   if ((mod_path == 0) || (*mod_path==0))
 			mod_path = "/usr/local/xanim/mods";
 
+#ifndef __FreeBSD__
   fprintf(stderr,"ModPath: %s\n",mod_path);/*CLEAN*/
+#endif
 
   len = strlen( mod_path );
   what_fun = (double)cos(45.0);
@@ -186,7 +188,9 @@ static void Check_For_Video_Modules()
 
   dp = path_buf;
 
+#ifndef __FreeBSD__
   fprintf(stderr,"PathBuf: %s\n",dp);/*CLEAN*/
+#endif
 
   while( dp && *dp )
   { char *t1p, *t2p;
@@ -211,10 +215,14 @@ char	*dir_name;
   char *end_of_dir;
   int len;
 
+#ifndef __FreeBSD__
   fprintf(stderr,"ScanDir: a\n");/*CLEAN*/
+#endif
   if (dir_name == 0) return;
 
+#ifndef __FreeBSD__
   fprintf(stderr,"ScanDir: %s\n",dir_name);/*CLEAN*/
+#endif
 
   DEBUG_LEVEL1 fprintf(stderr,"dirname: %s\n", dir_name );
 
@@ -416,6 +424,7 @@ CODEC_LIST	**list;
  ****--------------------------------------------------------------------****/
 static void Video_Add_Codec_To_List( list, id, init_func, dec_func)
 CODEC_LIST	**list;
+xaULONG		id;
 xaLONG		(*init_func)();
 xaULONG		(*dec_func)();
 {
