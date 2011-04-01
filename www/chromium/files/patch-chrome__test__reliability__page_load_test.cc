--- ./chrome/test/reliability/page_load_test.cc.orig	2010-12-16 02:12:11.000000000 +0100
+++ ./chrome/test/reliability/page_load_test.cc	2010-12-20 20:15:08.000000000 +0100
@@ -165,7 +165,7 @@
     scoped_ptr<FileVersionInfo> file_info;
     file_info.reset(FileVersionInfo::CreateFileVersionInfo(kChromeDll));
     last_change = WideToASCII(file_info->last_change());
-#elif defined(OS_LINUX) || defined(OS_MACOSX)
+#elif defined(OS_LINUX) || defined(OS_FREEBSD) || defined(OS_MACOSX)
     // TODO(fmeawad): On Mac, the version retrieved here belongs to the test
     // module and not the chrome binary, need to be changed to chrome binary
     // instead.
