--- ./src/umplayer.cpp.orig	2011-03-29 07:43:57.000000000 -0500
+++ ./src/umplayer.cpp	2011-06-03 01:07:11.292091723 -0500
@@ -443,13 +443,13 @@ void UMPlayer::showInfo() {
             .arg(umplayerVersion())
 #ifdef Q_OS_LINUX
            .arg("Linux")
-#else
-#ifdef Q_OS_WIN
+#elif defined(Q_OS_FREEBSD)
+           .arg("FreeBSD")
+#elif defined(Q_OS_WIN)
            .arg("Windows ("+win_ver+")")
 #else
 		   .arg("Other OS")
 #endif
-#endif
            ;
 
 	printf("%s\n", s.toLocal8Bit().data() );
