--- net/dns/address_info.cc.orig	2023-09-13 12:11:42 UTC
+++ net/dns/address_info.cc
@@ -77,7 +77,7 @@ AddressInfo::AddressInfoAndResult AddressInfo::Get(
     // error.
     // http://crbug.com/134142
     err = ERR_NAME_NOT_RESOLVED;
-#elif BUILDFLAG(IS_POSIX) && !BUILDFLAG(IS_FREEBSD)
+#elif BUILDFLAG(IS_POSIX)
     if (os_error != EAI_NONAME && os_error != EAI_NODATA)
       err = ERR_NAME_RESOLUTION_FAILED;
 #endif
