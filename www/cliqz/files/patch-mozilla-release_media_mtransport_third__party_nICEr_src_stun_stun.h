Firefox pulls in if_var.h which causes "class thread" conflicts with
"struct thread" in sys/lock.h.

https://lists.freebsd.org/pipermail/svn-src-all/2019-August/184844.html

--- mozilla-release/media/mtransport/third_party/nICEr/src/stun/stun.h.orig	2019-08-23 20:05:51 UTC
+++ mozilla-release/media/mtransport/third_party/nICEr/src/stun/stun.h
@@ -41,7 +41,7 @@ OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY O
 #include <sys/socket.h>
 #ifndef LINUX
 #include <net/if.h>
-#if !defined(__OpenBSD__) && !defined(__NetBSD__)
+#if !defined(__OpenBSD__) && !defined(__NetBSD__) && !defined(__FreeBSD__)
 #include <net/if_var.h>
 #endif
 #include <net/if_dl.h>
