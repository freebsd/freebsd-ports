--- build/top.mk.orig	Wed Mar 17 21:15:31 2004
+++ build/top.mk	Wed Mar 24 03:37:31 2004
@@ -68,7 +68,7 @@
 
 LIBTOOL = @LIBTOOL@
 LIBVERSION = @OPENLDAP_LIBVERSION@
-LTVERSION = -release $(LIBVERSION)
+LTVERSION = -version-info $(LIBVERSION)
 
 # libtool --only flag for libraries: platform specific
 NT_LTONLY_LIB = # --only-$(BUILD_LIBS_DYNAMIC)
@@ -190,6 +190,8 @@
 
 SLAPD_LIBS = @SLAPD_LIBS@ @SLAPD_PERL_LDFLAGS@ @SLAPD_SQL_LDFLAGS@ @SLAPD_SQL_LIBS@ @SLAPD_SLP_LIBS@
 SLURPD_LIBS = @SLURPD_LIBS@
+
+SLAPI_LIBS = @SLAPI_LIBS@
 
 # Our Defaults
 CC = $(AC_CC)
