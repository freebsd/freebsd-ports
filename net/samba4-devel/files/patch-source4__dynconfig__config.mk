--- ./source4/dynconfig/config.mk.orig	2010-01-11 05:35:28.000000000 +0000
+++ ./source4/dynconfig/config.mk	2010-01-24 02:32:34.000000000 +0000
@@ -5,8 +5,8 @@
 # set these to where to find various files
 # These can be overridden by command line switches (see samba(8))
 # or in smb.conf (see smb.conf(5))
-CONFIG4FILE = $(sysconfdir)/smb.conf
-pkgconfigdir = $(libdir)/pkgconfig
+CONFIG4FILE = $(sysconfdir)/%%SAMBA_CONFIG%%
+pkgconfigdir = $(prefix)/libdata/pkgconfig
 LMHOSTSFILE4 = $(sysconfdir)/lmhosts
 
 $(dynconfigsrcdir)/dynconfig.o: CFLAGS+=-DCONFIGFILE=\"$(CONFIG4FILE)\" -DBINDIR=\"$(bindir)\" \
