--- components/sync_bookmarks/bookmark_model_view.cc.orig	2025-12-05 10:12:50 UTC
+++ components/sync_bookmarks/bookmark_model_view.cc
@@ -9,7 +9,7 @@
 #include "components/bookmarks/browser/bookmark_model.h"
 #include "components/bookmarks/browser/bookmark_node.h"
 #include "components/bookmarks/common/bookmark_metrics.h"
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "base/metrics/histogram_base.h"
 #include "base/metrics/histogram_functions.h"
 #include "base/time/time.h"
@@ -253,7 +253,7 @@ void BookmarkModelViewUsingAccountNodes::RemoveAllSync
 
 void BookmarkModelViewUsingAccountNodes::
     MaybeRemoveUnderlyingModelDuplicatesUponInitialSync() {
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   BeginExtensiveChanges();
 
   const base::Time deduplication_start_time = base::Time::Now();
