--- general/zstr.hpp.orig	2020-03-11 15:50:47 UTC
+++ general/zstr.hpp
@@ -69,7 +69,7 @@ static std::string strerror()
    {
       buff = "Unknown error";
    }
-#elif (_POSIX_C_SOURCE >= 200112L || _XOPEN_SOURCE >= 600) && ! _GNU_SOURCE || defined(__APPLE__)
+#elif (_POSIX_C_SOURCE >= 200112L || _XOPEN_SOURCE >= 600) && ! _GNU_SOURCE || defined(__APPLE__) || defined(__FreeBSD__) || defined(__OpenBSD__) || defined(__NetBSD__) || defined(__DragonFly__)
    // XSI-compliant strerror_r()
    if (strerror_r(errno, &buff[0], buff.size()) != 0)
    {
