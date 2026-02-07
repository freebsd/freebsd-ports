--- wmmaiload/Init.make.orig	2005-08-28 19:14:57 UTC
+++ wmmaiload/Init.make
@@ -45,13 +45,13 @@ endif
 # SPECIFIC INFORMATIONS :
 #
 
-LIB_SSL = $(shell grep -q '^OPTIONS.*HAVE_SSL' ../Config.make && echo '-lssl')
+LIB_SSL = $(shell grep -q '^OPTIONS.*HAVE_SSL' ../Config.make && echo '-lssl -lcrypto')
 LIB_THREADS = $(shell grep -q '^OPTIONS.*HAVE_THREADS' ../Config.make && echo '-lpthread')
 
 CROSS_COMPILE =
 USER_CPPFLAGS = $(OPTIONS)
 USER_CFLAGS   =
-USER_LDFLAGS  = -L/usr/X11R6/lib -lX11 -lXext -lXpm $(LIB_THREADS) $(LIB_SSL)
+USER_LDFLAGS  =  -lX11 -lXext -lXpm $(LIB_THREADS) $(LIB_SSL)
 
 
 #*****************************************************************
