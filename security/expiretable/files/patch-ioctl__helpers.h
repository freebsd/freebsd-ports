--- ioctl_helpers.h.orig	2021-04-19 18:12:20 UTC
+++ ioctl_helpers.h
@@ -31,6 +31,5 @@ int	radix_get_tstats(int dev, struct pfr_tstats **tsta
 int	radix_get_tables(int dev, struct pfr_table **tables, const struct pfr_table *filter, int flags);
 int	radix_get_addrs(int dev, const struct pfr_table *table, struct pfr_addr **addrs, int flags);
 int	radix_del_addrs(int dev, const struct pfr_table *table, struct pfr_addr *addrs, int addr_count, int flags);
-int	get_states(int dev, struct pf_state **states);
 
 #endif /*_IOCTL_HELPERS_H_*/
