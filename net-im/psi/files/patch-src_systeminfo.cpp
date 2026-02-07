--- src/systeminfo.cpp.orig	2018-11-02 00:15:39 UTC
+++ src/systeminfo.cpp
@@ -191,6 +191,16 @@ SystemInfo::SystemInfo() : QObject(QCoreApplication::i
 	}
 #endif
 
+#ifdef __FreeBSD__
+	// QSysInfo::productVersion() on FreeBSD currently does not return
+	// correct OS version (see PR 237075)
+	if (os_version_str_ == "unknown") {
+		struct utsname u;
+		uname(&u);
+		os_version_str_ = u.release;
+	}
+#endif
+
 	if (!os_version_str_.isEmpty() && os_name_str_.contains(os_version_str_)) {
 		os_version_str_.clear();
 	}
