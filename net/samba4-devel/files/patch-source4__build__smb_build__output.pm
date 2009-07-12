--- ./source4/build/smb_build/output.pm.orig	2009-06-19 04:36:48.000000000 +0000
+++ ./source4/build/smb_build/output.pm	2009-07-12 02:39:36.000000000 +0000
@@ -48,7 +48,7 @@
 	$lib->{LIBRARY_DEBUGNAME} = $lib->{LIBRARY_REALNAME};
 
 	$lib->{LIBRARY_SONAME} = "\$(if \$($lib->{NAME}_SOVERSION),$lib->{LIBRARY_REALNAME}.\$($lib->{NAME}_SOVERSION),$lib->{LIBRARY_REALNAME})";
-	$lib->{LIBRARY_REALNAME} = "\$(if \$($lib->{NAME}_VERSION),$lib->{LIBRARY_REALNAME}.\$($lib->{NAME}_VERSION),$lib->{LIBRARY_REALNAME})";
+	$lib->{LIBRARY_REALNAME} = "\$(if \$($lib->{NAME}_SOVERSION),$lib->{LIBRARY_REALNAME}.\$($lib->{NAME}_SOVERSION),$lib->{LIBRARY_REALNAME})";
 	
 	$lib->{RESULT_SHARED_LIBRARY} = "$lib->{SHAREDDIR}/$lib->{LIBRARY_REALNAME}";
 	$lib->{OUTPUT_SHARED_LIBRARY} = "-l$link_name";
