--- frontpage/version5.0/apache2/mod_fpcgid.h.orig	Thu Jan  9 12:19:29 2003
+++ frontpage/version5.0/apache2/mod_fpcgid.h	Wed Feb 12 10:31:06 2003
@@ -24,6 +24,17 @@
 #ifndef MOD_FPCGID_H
 #define MOD_FPCGID_H
 
+typedef struct {
+    int fp_status;
+    int fp_admin_status;
+    const char *sockname;
+    const char *logname;
+    long logbytes;
+    int bufbytes;
+} cgid_server_conf;
+
+module AP_MODULE_DECLARE_DATA frontpage_module;
+
 void  fpcgid_init_pool(int* first_time, const char* userdata_key);
 int   fpcgid_init(apr_pool_t* p, apr_pool_t* plog, apr_pool_t* ptemp,
                   server_rec* main_server);
