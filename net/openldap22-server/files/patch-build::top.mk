--- build/top.mk.orig	Wed Mar 24 22:51:22 2004
+++ build/top.mk	Wed Mar 31 22:28:53 2004
@@ -69,7 +69,7 @@
 LIBTOOL = @LIBTOOL@
 LIBRELEASE = @OPENLDAP_LIBRELEASE@
 LIBVERSION = @OPENLDAP_LIBVERSION@
-LTVERSION = -release $(LIBRELEASE) -version-info $(LIBVERSION)
+LTVERSION = -version-info $(LIBVERSION)
 
 # libtool --only flag for libraries: platform specific
 NT_LTONLY_LIB = # --only-$(BUILD_LIBS_DYNAMIC)
@@ -191,6 +191,8 @@
 
 SLAPD_LIBS = @SLAPD_LIBS@ @SLAPD_PERL_LDFLAGS@ @SLAPD_SQL_LDFLAGS@ @SLAPD_SQL_LIBS@ @SLAPD_SLP_LIBS@
 SLURPD_LIBS = @SLURPD_LIBS@
+
+SLAPI_LIBS = @SLAPI_LIBS@
 
 # Our Defaults
 CC = $(AC_CC)
