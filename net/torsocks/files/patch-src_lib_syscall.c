--- src/lib/syscall.c.orig	2015-05-27 18:54:22 UTC
+++ src/lib/syscall.c
@@ -84,7 +84,7 @@ static LIBC_ACCEPT_RET_TYPE handle_accep
 	return tsocks_accept(sockfd, addr, &addrlen);
 }
 
-#if (defined(__linux__) || defined(__darwin__) || (defined(__FreeBSD_kernel__) && defined(__i386__)) || defined(__NetBSD__))
+#if defined(__FreeBSD__)
 /*
  * Handle mmap(2) syscall.
  */
@@ -372,7 +372,7 @@ LIBC_SYSCALL_RET_TYPE tsocks_syscall(lon
 		ret = handle_close(args);
 		break;
 	case TSOCKS_NR_MMAP:
-#if (defined(__NetBSD__) || defined(__FreeBSD__) || defined(__FreeBSD_kernel__)) && defined(__x86_64)
+#if defined(badbadbad)
 		/*
 		 * On an 64 bit *BSD system, __syscall(2) should be used for mmap().
 		 * This is NOT suppose to happen but for protection we deny that call.
@@ -456,6 +456,14 @@ LIBC_SYSCALL_RET_TYPE tsocks_syscall(lon
 		ret = handle_inotify_rm_watch(args);
 		break;
 #endif /* __linux__ */
+#if defined(__FreeBSD__)
+	case TSOCKS_NR_FORK:
+		ret = tsocks_libc_syscall(TSOCKS_NR_FORK);
+		break;
+	case TSOCKS_NR_GETPID:
+		ret = tsocks_libc_syscall(TSOCKS_NR_GETPID);
+		break;
+#endif
 	default:
 		/*
 		 * Because of the design of syscall(), we can't pass a va_list to it so
@@ -530,6 +538,14 @@ LIBC___SYSCALL_RET_TYPE tsocks___syscall
 		 */
 		ret = handle_bsd_mmap(args);
 		break;
+#if defined(__FreeBSD__)
+	case TSOCKS_NR_FORK:
+		ret = tsocks_libc_syscall(TSOCKS_NR_FORK);
+		break;
+	case TSOCKS_NR_GETPID:
+		ret = tsocks_libc_syscall(TSOCKS_NR_GETPID);
+		break;
+#endif
 	default:
 		/*
 		 * Because of the design of syscall(), we can't pass a va_list to it so
