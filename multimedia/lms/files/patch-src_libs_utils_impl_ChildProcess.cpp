--- src/libs/utils/impl/ChildProcess.cpp.orig	2022-02-02 17:25:04 UTC
+++ src/libs/utils/impl/ChildProcess.cpp
@@ -68,6 +68,7 @@ ChildProcess::ChildProcess(boost::asio::io_context& io
 	if (res < 0)
 		throw SystemException {errno, "pipe2 failed!"};
 
+#if !defined(__FreeBSD__) // see https://github.com/epoupon/lms/issues/144
 	{
 #if defined(__linux__) && defined(F_SETPIPE_SZ)
 		// Just a hint here to prevent the writer from writing too many bytes ahead of the reader
@@ -79,6 +80,7 @@ ChildProcess::ChildProcess(boost::asio::io_context& io
 			throw SystemException {errno, "fcntl failed!"};
 #endif
 	}
+#endif
 
 	res = fork();
 	if (res == -1)
