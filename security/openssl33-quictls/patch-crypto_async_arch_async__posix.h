commit e883812f463c1623249e038698ccaddf2baa34d8
Author: Warner Losh <imp@FreeBSD.org>
Date:   Mon Mar 18 19:48:22 2024 -0600

    posix_async: FreeBSD also defines {make|swap|get|set}context

    FreeBSD also defines {make|swap|get|set}context for backward
    compatibility, despite also exposing POSIX_VERSION 200809L
    in FreeBSD 15-current.

    Note: There's no fallback for POSIX_VERSION 200809 without these
    routines, so maybe that should be a #error? ... But that's a questionf
    or upstream.

    FreeBSD has defined these interfaces since FreeBSD 4.7, released over 20
    years ago, so no further nuance in FreeBSD version number is necessary.

    Pull Request:           https://github.com/openssl/openssl/pull/23885

diff --git a/crypto/async/arch/async_posix.h b/crypto/async/arch/async_posix.h
index a17c6b8e68af..2d97ec3acc9b 100644
--- crypto/async/arch/async_posix.h
+++ crypto/async/arch/async_posix.h
@@ -18,7 +18,7 @@
 # include <unistd.h>
 
 # if _POSIX_VERSION >= 200112L \
-     && (_POSIX_VERSION < 200809L || defined(__GLIBC__))
+     && (_POSIX_VERSION < 200809L || defined(__GLIBC__) || defined(__FreeBSD__))
 
 # include <pthread.h>
 
