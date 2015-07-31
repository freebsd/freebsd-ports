--- src/umplayer.cpp.orig	2011-09-13 08:33:08 UTC
+++ src/umplayer.cpp
@@ -447,13 +447,13 @@ void UMPlayer::showInfo() {
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
