--- build/cmake/CondorPackageConfig.cmake.orig	2013-09-19 15:12:10.000000000 -0500
+++ build/cmake/CondorPackageConfig.cmake	2013-10-20 12:04:52.000000000 -0500
@@ -1,3 +1,4 @@
+
  ###############################################################
  #
  # Copyright 2011 Red Hat, Inc.
@@ -170,6 +171,23 @@
 	# enable if we desire native packaging.
 	# set ( CPACK_GENERATOR "${CPACK_GENERATOR};PackageMaker" ) ;
 	# set (CPACK_OSX_PACKAGE_VERSION)
+
+elseif ( ${OS_NAME} STREQUAL "FREEBSD" )
+
+	# Condor installs nothing useful to FreeBSD in C_INIT, so
+	# just tuck it out of the way.  FreeBSD RC scripts come from
+	# the port's "files" directory.
+	set( C_INIT		etc/condor )
+	set( C_ETC		etc/condor )
+	set( C_CONFIGD		etc/condor/config.d )
+	set( C_SYSCONFIG	etc/condor/sysconfig )
+	
+	set( C_ETC_EXAMPLES	etc/condor/examples )
+	# Condor installs an "examples" directory into C_SHARE_EXAMPLES
+	# so set it to share/condor instead of share/condor/examples.
+	set( C_SHARE_EXAMPLES	share/examples/condor )
+	set( C_DOC		share/doc/condor )
+	
 elseif ( ${OS_NAME} MATCHES "WIN" )
 
 	# override for windows.
