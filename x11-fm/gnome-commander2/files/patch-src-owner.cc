--- src/owner.cc.orig	2009-06-29 06:57:46.000000000 -0300
+++ src/owner.cc	2009-08-10 20:51:05.000000000 -0300
@@ -62,7 +62,13 @@
 
     if (!buff)
     {
-        buffsize = max(sysconf(_SC_GETPW_R_SIZE_MAX), sysconf(_SC_GETGR_R_SIZE_MAX));
+        long int pw_size = sysconf(_SC_GETPW_R_SIZE_MAX);
+        long int gr_size = sysconf(_SC_GETGR_R_SIZE_MAX);
+
+        if (pw_size==-1)    pw_size = 4096;     // `sysconf' does not support _SC_GETPW_R_SIZE_MAX. Try a moderate value.
+        if (gr_size==-1)    gr_size = 4096;     // `sysconf' does not support _SC_GETGR_R_SIZE_MAX. Try a moderate value.
+
+        buffsize = max(pw_size, gr_size);
         buff = g_new0 (char, buffsize);
     }
 
