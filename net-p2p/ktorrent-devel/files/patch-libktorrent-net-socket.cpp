--- src/libktorrent/net/socket.cpp.orig	Mon Jul 31 16:11:04 2006
+++ src/libktorrent/net/socket.cpp	Mon Jul 31 17:53:08 2006
@@ -32,7 +32,7 @@
 #ifdef Q_OS_LINUX
 #include <asm/ioctls.h>
 #endif
-#if defined(Q_OS_MACX) || defined(Q_OS_DARWIN)
+#if defined(Q_OS_MACX) || defined(Q_OS_DARWIN) || (defined(Q_OS_FREEBSD) && __FreeBSD_version < 600020)
 #define MSG_NOSIGNAL 0
 #endif
 #include <unistd.h>
@@ -49,7 +49,7 @@
 
 	Socket::Socket(int fd) : m_fd(fd),m_state(IDLE)
 	{
-#if defined(Q_OS_MACX) || defined(Q_OS_DARWIN)
+#if defined(Q_OS_MACX) || defined(Q_OS_DARWIN) || (defined(Q_OS_FREEBSD) && __FreeBSD_version < 600020)
 		if (setsockopt(m_fd,SOL_SOCKET,SO_NOSIGPIPE,0L,0) < 0)
 		{
 			Out(SYS_CON|LOG_NOTICE) << QString("Failed to set the NOSIGPIPE option : %1").arg(strerror(errno)) << endl;
@@ -65,7 +65,7 @@
 			Out(SYS_GEN|LOG_IMPORTANT) << QString("Cannot create socket : %1").arg(strerror(errno)) << endl;
 		}
 		m_fd = fd;
- #if defined(Q_OS_MACX) || defined(Q_OS_DARWIN)
+#if defined(Q_OS_MACX) || defined(Q_OS_DARWIN) || (defined(Q_OS_FREEBSD) && __FreeBSD_version < 600020)
 		if (setsockopt(m_fd,SOL_SOCKET,SO_NOSIGPIPE,0L,0) < 0)
 		{
 			Out(SYS_CON|LOG_NOTICE) << QString("Failed to set the NOSIGPIPE option : %1").arg(strerror(errno)) << endl;
