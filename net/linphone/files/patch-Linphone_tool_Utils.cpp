--- Linphone/tool/Utils.cpp.orig
+++ Linphone/tool/Utils.cpp
@@ -1665,7 +1665,7 @@
 		CloseHandle(pi.hThread);
 	} else {
 		lWarning() << "Failed to start process. GetLastError() =" << (int)GetLastError();
 	}
-#elif defined(Q_OS_MACOS) || defined(Q_OS_LINUX)
+#elif defined(Q_OS_MACOS) || defined(Q_OS_LINUX) || defined(Q_OS_FREEBSD)
 	QProcess::startDetached("/bin/sh", {"-c", command});
 #else
 	lWarning() << "Unsupported OS!";
