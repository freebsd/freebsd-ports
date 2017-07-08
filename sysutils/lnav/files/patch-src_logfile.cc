--- src/logfile.cc.orig	2017-05-23 18:53:47 UTC
+++ src/logfile.cc
@@ -92,10 +92,10 @@ throw (error)
 
         loo.loo_fd.close_on_exec();
 
-        log_info("Creating logfile: fd=%d; size=%d; mtime=%d; filename=%s",
+        log_info("Creating logfile: fd=%d; size=%" PRId64 "; mtime=%" PRId64 "; filename=%s",
                  (int) loo.loo_fd,
-                 this->lf_stat.st_size,
-                 this->lf_stat.st_mtime,
+                 (long long) this->lf_stat.st_size,
+                 (long long) this->lf_stat.st_mtime,
                  filename.c_str());
 
         this->lf_valid_filename = true;
