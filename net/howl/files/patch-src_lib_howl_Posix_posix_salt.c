--- src/lib/howl/Posix/posix_salt.c.orig	Fri Jul  2 00:46:53 2004
+++ src/lib/howl/Posix/posix_salt.c	Fri Jul  2 00:47:30 2004
@@ -450,12 +450,14 @@
 				sw_debug("sw_salt_run() : fd %d is readable\n", psocket->m_super.m_fd);
 				events |= SW_SOCKET_READ;
 				num--;
+				FD_CLR(psocket->m_super.m_fd, &readfds);
 			}
 		
 			if (FD_ISSET(psocket->m_super.m_fd, &writefds))
 			{
 				sw_debug("sw_salt_run() : fd %d is writable\n", psocket->m_super.m_fd);
 				events |= SW_SOCKET_WRITE;
+				FD_CLR(psocket->m_super.m_fd, &writefds);
 				num--;
 			}
 		
@@ -463,6 +465,7 @@
 			{
 				sw_debug("sw_salt_run() : fd %d is oobable\n", psocket->m_super.m_fd);
 				events |= SW_SOCKET_OOB;
+				FD_CLR(psocket->m_super.m_fd, &oobfds);
 				num--;
 			}
 
