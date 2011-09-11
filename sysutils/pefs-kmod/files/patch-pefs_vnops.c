commit 7c69f523b561e4a983582b7e874ac28956171b43
Author: Gleb Kurtsou <gleb.kurtsou@gmail.com>
Date:   Sun Sep 11 17:38:36 2011 +0300

    Use vm_page_aflag_set(PGA_WRITEABLE)
    
    PG_WRITEABLE was removed in r225418
    __FreeBSD_version was bumped 4 days later

diff --git a/sys/fs/pefs/pefs_vnops.c b/sys/fs/pefs/pefs_vnops.c
index 6255831..bda625c 100644
--- sys/fs/pefs/pefs_vnops.c
+++ sys/fs/pefs/pefs_vnops.c
@@ -1808,8 +1808,12 @@ lookupvpg:
 			 * sleeping so that the page daemon is less
 			 * likely to reclaim it.
 			 */
+#if __FreeBSD_version >= 900044
+			vm_page_aflag_set(m, PGA_REFERENCED);
+#else
 			vm_page_lock_queues();
 			vm_page_flag_set(m, PG_REFERENCED);
+#endif
 			vm_page_sleep(m, "pefsmr");
 			goto lookupvpg;
 		}
@@ -1840,8 +1844,12 @@ lookupvpg:
 			 * sleeping so that the page daemon is less
 			 * likely to reclaim it.
 			 */
+#if __FreeBSD_version >= 900044
+			vm_page_aflag_set(m, PGA_REFERENCED);
+#else
 			vm_page_lock_queues();
 			vm_page_flag_set(m, PG_REFERENCED);
+#endif
 			vm_page_sleep(m, "pefsmr");
 			goto lookupvpg;
 		}
@@ -2012,8 +2020,12 @@ lookupvpg:
 			 * sleeping so that the page daemon is less
 			 * likely to reclaim it.
 			 */
+#if __FreeBSD_version >= 900044
+			vm_page_aflag_set(m, PGA_REFERENCED);
+#else
 			vm_page_lock_queues();
 			vm_page_flag_set(m, PG_REFERENCED);
+#endif
 			vm_page_sleep(m, "pefsmw");
 			goto lookupvpg;
 		}
