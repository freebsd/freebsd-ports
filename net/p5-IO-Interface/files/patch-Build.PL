--- Build.PL.orig	2014-12-09 10:41:30.000000000 -0600
+++ Build.PL	2015-02-06 08:31:48.718810053 -0600
@@ -15,6 +15,7 @@
     requires     => {
 	'perl'                => '5.005',
     },
+    extra_compiler_flags => '-D__USE_BSD -DUSE_GETIFADDRS -DHAVE_SOCKADDR_DL_STRUCT',
     );
 
 $build->create_build_script();
