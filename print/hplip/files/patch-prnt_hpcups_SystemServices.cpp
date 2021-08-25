--- prnt/hpcups/SystemServices.cpp.orig	2022-02-23 07:41:04 UTC
+++ prnt/hpcups/SystemServices.cpp
@@ -42,7 +42,7 @@ SystemServices::SystemServices(int iLogLevel, int job_
         createTempFile(fname, &m_fp);
         if (m_fp)
         {
-            chmod(fname, S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH);
+            chmod(fname, S_IRUSR | S_IWUSR | S_IRGRP | 0 | S_IROTH);
         }
     }
 }
