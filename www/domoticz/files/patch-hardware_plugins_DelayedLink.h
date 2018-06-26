--- hardware/plugins/DelayedLink.h.orig	2018-06-23 14:18:06 UTC
+++ hardware/plugins/DelayedLink.h
@@ -143,6 +143,12 @@ namespace Plugins {
 				if (!shared_lib_) FindLibrary("python3.6", true);
 				if (!shared_lib_) FindLibrary("python3.5", true);
 				if (!shared_lib_) FindLibrary("python3.4", true);
+#ifdef __FreeBSD__
+				if (!shared_lib_) FindLibrary("python3.7m", true);
+				if (!shared_lib_) FindLibrary("python3.6m", true);
+				if (!shared_lib_) FindLibrary("python3.5m", true);
+				if (!shared_lib_) FindLibrary("python3.4m", true);
+#endif /* FreeBSD */
 #endif
 				if (shared_lib_)
 				{
