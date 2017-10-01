--- src/FileWatcher/FileWatcherOSX.cpp.orig	2017-10-01 03:38:27 UTC
+++ src/FileWatcher/FileWatcherOSX.cpp
@@ -229,7 +229,11 @@ namespace FW
 		void addAll()
 		{
 			// add base dir
+#ifdef O_EVTONLY
 			int fd = open(mDirName.c_str(), O_RDONLY | O_EVTONLY);
+#else
+			int fd = open(mDirName.c_str(), O_RDONLY );
+#endif
 			EV_SET(&mChangeList[0], fd, EVFILT_VNODE,
 				   EV_ADD | EV_ENABLE | EV_ONESHOT,
 				   NOTE_DELETE | NOTE_EXTEND | NOTE_WRITE | NOTE_ATTRIB,
