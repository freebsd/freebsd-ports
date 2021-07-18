--- src/libs/utils/impl/ChildProcess.cpp.orig	2021-04-25 18:33:13 UTC
+++ src/libs/utils/impl/ChildProcess.cpp
@@ -68,6 +68,7 @@ ChildProcess::ChildProcess(boost::asio::io_context& io
 	if (res < 0)
 		throw SystemException {errno, "pipe2 failed!"};
 
+#if !defined(__FreeBSD__) // see https://github.com/epoupon/lms/issues/144
 	{
 		const std::size_t pipeSize {65536*8};
 
@@ -77,6 +78,7 @@ ChildProcess::ChildProcess(boost::asio::io_context& io
 		if (fcntl(pipe[1], F_SETPIPE_SZ, pipeSize) == -1)
 			throw SystemException {errno, "fcntl failed!"};
 	}
+#endif
 
 	res = fork();
 	if (res == -1)
