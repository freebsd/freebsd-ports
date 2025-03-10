--- WinPort/src/Backend/WinPortMain.cpp.orig	2024-11-18 06:57:59 UTC
+++ WinPort/src/Backend/WinPortMain.cpp
@@ -480,6 +480,7 @@ extern "C" int WinPortMain(const char *full_exe_path, 
 #endif
 	}
 
+#ifdef __linux__
 	bool wsl_clipboard_workaround = (arg_opts.ext_clipboard.empty()
 		&& getenv("WSL_DISTRO_NAME")
 		&& !getenv("FAR2L_WSL_NATIVE"));
@@ -498,6 +499,7 @@ extern "C" int WinPortMain(const char *full_exe_path, 
 			arg_opts.ext_clipboard.clear();
 		}
 	}
+#endif
 
 	int result = -1;
 	if (!arg_opts.tty) {
@@ -518,9 +520,11 @@ extern "C" int WinPortMain(const char *full_exe_path, 
 				if (!WinPortMainBackend_p(&a) ) {
 					fprintf(stderr, "Cannot use GUI backend\n");
 					arg_opts.tty = !arg_opts.notty;
+#ifdef __linux__
 					if (wsl_clipboard_workaround) {
 						//arg_opts.ext_clipboard.clear();
 					}
+#endif
 				}
 			} else {
 				fprintf(stderr, "Cannot find backend entry point, error %s\n", dlerror());
