--- lib/vty.h.orig	2018-03-12 00:53:37 UTC
+++ lib/vty.h
@@ -189,45 +189,6 @@ struct vty_arg {
 /* Integrated configuration file. */
 #define INTEGRATE_DEFAULT_CONFIG "frr.conf"
 
-#if CONFDATE > 20180401
-CPP_NOTICE("It's probably time to remove VTY_NEWLINE compatibility foo.")
-#endif
-
-/* for compatibility */
-#define VNL "\n" CPP_WARN("VNL has been replaced with \\n.")
-#define VTYNL "\n" CPP_WARN("VTYNL has been replaced with \\n.")
-#define VTY_NEWLINE "\n" CPP_WARN("VTY_NEWLINE has been replaced with \\n.")
-#define VTY_GET_INTEGER(desc, v, str)                                          \
-	{                                                                      \
-		(v) = strtoul((str), NULL, 10);                                \
-	}                                                                      \
-	CPP_WARN("VTY_GET_INTEGER is no longer useful, use strtoul() or DEFPY.")
-#define VTY_GET_INTEGER_RANGE(desc, v, str, min, max)                          \
-	{                                                                      \
-		(v) = strtoul((str), NULL, 10);                                \
-	}                                                                      \
-	CPP_WARN(                                                              \
-		"VTY_GET_INTEGER_RANGE is no longer useful, use strtoul() or DEFPY.")
-#define VTY_GET_ULONG(desc, v, str)                                            \
-	{                                                                      \
-		(v) = strtoul((str), NULL, 10);                                \
-	}                                                                      \
-	CPP_WARN("VTY_GET_ULONG is no longer useful, use strtoul() or DEFPY.")
-#define VTY_GET_ULL(desc, v, str)                                              \
-	{                                                                      \
-		(v) = strtoull((str), NULL, 10);                               \
-	}                                                                      \
-	CPP_WARN("VTY_GET_ULL is no longer useful, use strtoull() or DEFPY.")
-#define VTY_GET_IPV4_ADDRESS(desc, v, str)                                     \
-	inet_aton((str), &(v)) CPP_WARN(                                       \
-		"VTY_GET_IPV4_ADDRESS is no longer useful, use inet_aton() or DEFPY.")
-#define VTY_GET_IPV4_PREFIX(desc, v, str)                                      \
-	str2prefix_ipv4((str), &(v)) CPP_WARN(                                 \
-		"VTY_GET_IPV4_PREFIX is no longer useful, use str2prefix_ipv4() or DEFPY.")
-#define vty_outln(vty, str, ...)                                               \
-	vty_out(vty, str "\n", ##__VA_ARGS__) CPP_WARN(                        \
-		"vty_outln is no longer useful, use vty_out(...\\n...)")
-
 /* Default time out value */
 #define VTY_TIMEOUT_DEFAULT 600
 
