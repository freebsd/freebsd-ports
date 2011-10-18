--- content/browser/zygote_host_linux.cc.orig	2011-10-02 18:12:41.000000000 +0300
+++ content/browser/zygote_host_linux.cc	2011-10-02 18:11:51.000000000 +0300
@@ -259,8 +259,10 @@
       return base::kNullProcessHandle;
   }
 
+#if !defined(OS_FREEBSD)
   const int kRendererScore = 5;
   AdjustRendererOOMScore(pid, kRendererScore);
+#endif
 
   return pid;
 }
