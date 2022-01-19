--- core/DesktopEditor/common/Types.h.orig	2021-09-30 12:13:32 UTC
+++ core/DesktopEditor/common/Types.h
@@ -78,7 +78,7 @@ typedef int				INT;
 typedef unsigned int	UINT, *PUINT;
 typedef wchar_t			WCHAR;
 
-#ifdef __linux__
+#if defined(__linux__) || defined(__FreeBSD__)
 #include <inttypes.h>
 typedef int64_t     T_LONG64;
 typedef uint64_t    T_ULONG64;
