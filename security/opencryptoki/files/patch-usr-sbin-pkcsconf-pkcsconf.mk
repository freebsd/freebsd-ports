--- usr/sbin/pkcsconf/pkcsconf.mk.orig	2022-04-25 11:04:51 UTC
+++ usr/sbin/pkcsconf/pkcsconf.mk
@@ -1,7 +1,7 @@
 sbin_PROGRAMS += usr/sbin/pkcsconf/pkcsconf
 noinst_HEADERS += usr/sbin/pkcsconf/pkcsconf_msg.h
 
-usr_sbin_pkcsconf_pkcsconf_LDFLAGS = -lpthread -ldl -lcrypto
+usr_sbin_pkcsconf_pkcsconf_LDFLAGS = -lpthread -lcrypto
 
 usr_sbin_pkcsconf_pkcsconf_CFLAGS = -D_THREAD_SAFE -DDEBUG -DDEV	\
 	-DAPI -I${srcdir}/usr/include -I${srcdir}/usr/lib/common	\
