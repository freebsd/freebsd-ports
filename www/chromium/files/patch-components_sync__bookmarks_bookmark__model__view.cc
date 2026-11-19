--- components/sync_bookmarks/bookmark_model_view.cc.orig	2026-11-19 12:25:27 UTC
+++ components/sync_bookmarks/bookmark_model_view.cc
@@ -10,7 +10,7 @@
 #include "components/bookmarks/browser/bookmark_node.h"
 #include "components/bookmarks/common/bookmark_metrics.h"
 #include "components/sync_bookmarks/scoped_bookmark_extensive_changes.h"
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "base/metrics/histogram_base.h"
 #include "base/metrics/histogram_functions.h"
 #include "base/time/time.h"
@@ -252,7 +252,7 @@ void BookmarkModelViewUsingAccountNodes::RemoveAllSync
 
 void BookmarkModelViewUsingAccountNodes::
     MaybeRemoveUnderlyingModelDuplicatesUponInitialSync() {
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   const base::Time deduplication_start_time = base::Time::Now();
 
   InitialAccountBookmarkDeduplicator initial_account_bookmark_deduplicator(
