--- chrome/browser/sync/profile_sync_components_factory_impl.cc.orig	2015-04-14 18:31:21.000000000 -0400
+++ chrome/browser/sync/profile_sync_components_factory_impl.cc	2015-04-28 10:10:08.900489000 -0400
@@ -396,7 +396,7 @@
   }
 #endif
 
-#if defined(OS_LINUX) || defined(OS_WIN) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_WIN) || defined(OS_CHROMEOS) || defined(OS_BSD)
   // Dictionary sync is enabled by default.
   if (!disabled_types.Has(syncer::DICTIONARY)) {
     pss->RegisterDataTypeController(
