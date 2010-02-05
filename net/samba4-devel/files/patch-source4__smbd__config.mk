--- ./source4/smbd/config.mk.orig	2010-01-11 05:35:28.000000000 +0000
+++ ./source4/smbd/config.mk	2010-01-24 21:49:26.000000000 +0000
@@ -20,7 +20,7 @@
 
 $(eval $(call proto_header_template,$(smbdsrcdir)/pidfile.h,$(PIDFILE_OBJ_FILES:.o=.c)))
 
-[BINARY::samba]
+[BINARY::samba4]
 INSTALLDIR = SBINDIR
 PRIVATE_DEPENDENCIES = \
 		LIBEVENTS \
@@ -38,7 +38,7 @@
 		share \
 		CLUSTER
 
-samba_OBJ_FILES = $(smbdsrcdir)/server.o
-$(samba_OBJ_FILES): CFLAGS+=-DSTATIC_service_MODULES="$(service_INIT_FUNCTIONS)NULL"
+samba4_OBJ_FILES = $(smbdsrcdir)/server.o
+$(samba4_OBJ_FILES): CFLAGS+=-DSTATIC_service_MODULES="$(service_INIT_FUNCTIONS)NULL"
 
-MANPAGES += $(smbdsrcdir)/samba.8
+MANPAGES += $(smbdsrcdir)/samba4.8
