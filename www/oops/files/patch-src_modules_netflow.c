-- src/modules/netflow.c.orig	2012-02-02 19:12:00.000000000 +0400
+++ src/modules/netflow.c	2012-02-02 19:13:28.000000000 +0400
@@ -165,22 +165,22 @@
 char            buf[1024];
 route_entry_t  *rt, *rt_ptr;
 
-    if ( 0 == file_name[0] ) return;
+    if ( 0 == file_name[0] ) return(0);
     rc = stat(file_name, &sb);
     if ( rc < 0 ) {
         my_xlog(OOPS_LOG_NOTICE|OOPS_LOG_DBG|OOPS_LOG_INFORM, "netflow: can't stat(`%s'): %s\n", file_name, strerror(errno));
-        return;
+        return(0);
     }
     if ( sb.st_mtime <= file_mtime ) {
         my_xlog(OOPS_LOG_DBG, "netflow: %s already seen\n", file_name);
-        return;
+        return(0);
     }
     /* reload */
     my_xlog(OOPS_LOG_NOTICE|OOPS_LOG_DBG, "netflow: reload from `%s'\n", file_name);
     file = fopen(file_name, "r");
     if ( file == NULL ) {
         my_xlog(OOPS_LOG_SEVERE, "netflow: can't fopen(`%s'): %s\n", file_name, strerror(errno));
-        return;
+        return(0);
     }
     NF_WRLOCK_CL;
     /* allocate tables once and forever to avoid memory fragmentation */
@@ -191,7 +191,7 @@
     if ( NULL == rt_ptr ) {
         fclose(file);
         NF_UNLOCK_CL;
-        return;
+        return(0);
     }
     while(fgets(buf, sizeof(buf) - 1, file) && (new_rt_entries < MAXRTTABLESZ)) {
         char        *p = buf, *d;
