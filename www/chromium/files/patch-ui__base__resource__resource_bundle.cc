--- ui/base/resource/resource_bundle.cc.orig	2015-04-14 18:18:59.000000000 -0400
+++ ui/base/resource/resource_bundle.cc	2015-04-28 08:51:21.756989000 -0400
@@ -611,7 +611,7 @@
 #elif defined(OS_CHROMEOS)
   // TODO(oshima): Include 200P only if the device support 200P
   supported_scale_factors.push_back(SCALE_FACTOR_200P);
-#elif defined(OS_LINUX) && defined(ENABLE_HIDPI)
+#elif (defined(OS_LINUX) || defined(OS_BSD)) && defined(ENABLE_HIDPI)
   supported_scale_factors.push_back(SCALE_FACTOR_200P);
 #elif defined(OS_WIN)
   bool default_to_100P = true;
