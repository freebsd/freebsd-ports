--- src/share/mk/bsd.sys.mk.orig	2016-08-02 11:51:10 UTC
+++ src/share/mk/bsd.sys.mk
@@ -83,7 +83,7 @@ CFLAGS+=	-Wreturn-type -Wswitch -Wshadow
 .endif
 .if ${WARNS} > 2
 CFLAGS+=	-Wcast-qual -Wwrite-strings
-CFLAGS+=	-Wextra -Wno-unused-parameter
+CFLAGS+=	-Wextra -Wno-unused-parameter -Wno-address-of-packed-member -Wno-varargs
 # Readd -Wno-sign-compare to override -Wextra with clang
 CFLAGS+=	-Wno-sign-compare
 CXXFLAGS+=	-Wabi
