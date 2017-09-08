--- base/process/internal_linux.cc.orig	2017-08-10 00:00:17.842158000 +0200
+++ base/process/internal_linux.cc	2017-08-10 00:02:37.838081000 +0200
@@ -60,10 +60,13 @@
   // Synchronously reading files in /proc is safe.
   ThreadRestrictions::ScopedAllowIO allow_io;
 
+#if !defined(OS_BSD)
   if (!ReadFileToString(file, buffer)) {
     DLOG(WARNING) << "Failed to read " << file.MaybeAsASCII();
     return false;
   }
+#endif
+
   return !buffer->empty();
 }
 
