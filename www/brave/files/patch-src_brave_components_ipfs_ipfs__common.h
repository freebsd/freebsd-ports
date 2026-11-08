--- src/brave/components/ipfs/ipfs_common.h.orig	2026-06-01 00:00:00 UTC
+++ src/brave/components/ipfs/ipfs_common.h
@@ -20,7 +20,11 @@
 static const base::FilePath::StringViewType kIpfsClientComponentId =
     FILE_PATH_LITERAL("nljcddpbnaianmglkpkneakjaapinabi");
 #endif
-#elif BUILDFLAG(IS_LINUX)
+// FreeBSD has no component of its own; the ids below only name a stale
+// directory left in the profile by a Brave that still shipped IPFS, and
+// the Linux ones are the closest thing to what such a profile would hold.
+// Without a branch here nothing declares kIpfsClientComponentId at all.
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #if defined(ARCH_CPU_ARM64)
 static const base::FilePath::StringViewType kIpfsClientComponentId =
     FILE_PATH_LITERAL("fmmldihckdnognaabhligdpckkeancng");
