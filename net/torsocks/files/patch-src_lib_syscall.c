Patch by Stefan Ehmann, see https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=233736

--- src/lib/syscall.c.orig	2022-05-25 14:36:05 UTC
+++ src/lib/syscall.c
@@ -84,7 +84,7 @@ static LIBC_ACCEPT_RET_TYPE handle_accept(va_list args
 	return tsocks_accept(sockfd, addr, &addrlen);
 }
 
-#if !((defined(__NetBSD__) || defined(__FreeBSD__) || defined(__FreeBSD_kernel__)) && defined(__x86_64))
+#if defined(__FreeBSD__)
 /*
  * Handle mmap(2) syscall.
  */
@@ -498,7 +498,7 @@ LIBC_SYSCALL_RET_TYPE tsocks_syscall(long int number, 
 		ret = handle_close(args);
 		break;
 	case TSOCKS_NR_MMAP:
-#if (defined(__NetBSD__) || defined(__FreeBSD__) || defined(__FreeBSD_kernel__)) && defined(__x86_64)
+#if defined(badbadbad)
 		/*
 		 * On an 64 bit *BSD system, __syscall(2) should be used for mmap().
 		 * This is NOT suppose to happen but for protection we deny that call.
@@ -606,6 +606,14 @@ LIBC_SYSCALL_RET_TYPE tsocks_syscall(long int number, 
 		ret = handle_getdents64(args);
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
 		DBG("[syscall] Unsupported __syscall number %ld. Passing through",
 				number);
@@ -675,6 +683,14 @@ LIBC___SYSCALL_RET_TYPE tsocks___syscall(quad_t number
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
