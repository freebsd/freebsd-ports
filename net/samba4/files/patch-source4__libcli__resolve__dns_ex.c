https://bugzilla.samba.org/show_bug.cgi?id=9656

From 30d391abd0909b4838b87ddedf4d5fe037c514cf Mon Sep 17 00:00:00 2001
From: Landon Fuller <landonf@bikemonkey.org>
Date: Sat, 16 Feb 2013 22:57:40 -0500
Subject: [PATCH] Fallback to the internal resolver on EAI_FAIL.

On Linux, non-RFC 1034-complaint names (such as gc._msdsc.example.org)
will result in the resolver returning the non-POSIX EAI_NODATA. In that
case, the case statement here would fall back on the internal resolver,
allowing resolution to complete successfully.

On FreeBSD, the libc resolver uses the same validation code, but
the POSIX result of EAI_FAIL is returned instead of EAI_NODATA. Since
there was no case for this error code, no fallback to the internal
resolver would occur. This led to replication failing on FreeBSD.
---
 source4/libcli/resolve/dns_ex.c | 4 +++-
 1 file changed, 3 insertions(+), 1 deletion(-)

diff --git a/source4/libcli/resolve/dns_ex.c b/source4/libcli/resolve/dns_ex.c
index bc64e8d..3f47898 100644
--- ./source4/libcli/resolve/dns_ex.c
+++ ./source4/libcli/resolve/dns_ex.c
@@ -400,8 +400,10 @@ static void run_child_getaddrinfo(struct dns_ex_state *state, int fd)
 #ifdef EAI_NODATA
 		case EAI_NODATA:
 #endif
+		case EAI_FAIL:
+			/* Linux returns EAI_NODATA on non-RFC1034-compliant names. FreeBSD returns EAI_FAIL */
 		case EAI_NONAME:
-			/* getaddrinfo() doesn't handle CNAME records */
+			/* getaddrinfo() doesn't handle CNAME or non-RFC1034 compatible records */
 			run_child_dns_lookup(state, fd);
 			return;
 		default:
-- 
1.8.1.3

