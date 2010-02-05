--- ./source4/build/smb_build/output.pm.orig	2010-01-11 05:35:28.000000000 +0000
+++ ./source4/build/smb_build/output.pm	2010-01-24 21:49:26.000000000 +0000
@@ -48,7 +48,7 @@
 	$lib->{LIBRARY_DEBUGNAME} = $lib->{LIBRARY_REALNAME};
 
 	$lib->{LIBRARY_SONAME} = "\$(if \$($lib->{NAME}_SOVERSION),$lib->{LIBRARY_REALNAME}.\$($lib->{NAME}_SOVERSION),$lib->{LIBRARY_REALNAME})";
-	$lib->{LIBRARY_REALNAME} = "\$(if \$($lib->{NAME}_VERSION),$lib->{LIBRARY_REALNAME}.\$($lib->{NAME}_VERSION),$lib->{LIBRARY_REALNAME})";
+	$lib->{LIBRARY_REALNAME} = "\$(if \$($lib->{NAME}_SOVERSION),$lib->{LIBRARY_REALNAME}.\$($lib->{NAME}_SOVERSION),$lib->{LIBRARY_REALNAME})";
 	
 	$lib->{RESULT_SHARED_LIBRARY} = "$lib->{SHAREDDIR}/$lib->{LIBRARY_REALNAME}";
 	$lib->{OUTPUT_SHARED_LIBRARY} = "-l$link_name";
