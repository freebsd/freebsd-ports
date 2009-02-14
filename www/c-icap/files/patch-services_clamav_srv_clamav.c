diff -ruN work/c_icap-030606rc1/services/clamav/srv_clamav.c work.patched/c_icap-030606rc1/services/clamav/srv_clamav.c
--- services/clamav/srv_clamav.c	2006-06-06 22:08:13.000000000 +0500
+++ services/clamav/srv_clamav.c	2009-02-13 11:33:57.000000000 +0400
@@ -137,17 +137,18 @@
 
 
 int srvclamav_init_service(service_module_t *this,struct icap_server_conf *server_conf){
-     int ret,no=0,i;
+     int ret,i;
+     unsigned int no = 0;
+     unsigned int options = 0;
+     options = options | CL_DB_STDOPT;
      magic_db=server_conf->MAGIC_DB;
      scantypes=(int *)malloc(ci_magic_types_num(magic_db)*sizeof(int));
      scangroups=(int *)malloc(ci_magic_groups_num(magic_db)*sizeof(int));
 
      for(i=0;i<ci_magic_types_num(magic_db);i++)  scantypes[i]=0;
      for(i=0;i<ci_magic_groups_num(magic_db);i++)  scangroups[i]=0;
-
-
      ci_debug_printf(10,"Going to initialize srvclamav\n");;
-     if((ret = cl_loaddbdir(cl_retdbdir(), &root, &no))) {
+     if((ret = cl_load(cl_retdbdir(), &root, &no, options))) {
 	  ci_debug_printf(1,"cl_loaddbdir: %s\n", cl_perror(ret));
 	  return 0;
      }
@@ -161,7 +162,7 @@
      limits.maxfiles = 0/*1000*/; /* max files */
      limits.maxfilesize = 100 * 1048576; /* maximal archived file size == 100 Mb */
      limits.maxreclevel = 5; /* maximal recursion level */
-     limits.maxratio = 200; /* maximal compression ratio */
+     //limits.maxratio = 200; /* maximal compression ratio */
      limits.archivememlim = 0; /* disable memory limit for bzip2 scanner */
      return 1;
 }
