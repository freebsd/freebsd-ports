--- src/kristall.pro.orig	2021-11-20 14:16:34 UTC
+++ src/kristall.pro
@@ -19,7 +19,6 @@ DEFINES += KRISTALL_VERSION="\"$(shell cd $$PWD; git d
 !win32: LIBS += -lcrypto
 
 # We need iconv on non-linux platforms
-!linux: LIBS += -liconv
 
 # Initialize build flags from environment variables.
 QMAKE_CFLAGS   *= $$(CFLAGS)
