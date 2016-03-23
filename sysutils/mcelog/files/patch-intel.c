--- intel.c.orig	2016-02-10 18:38:43 UTC
+++ intel.c
@@ -141,14 +141,18 @@ static int intel_memory_error(struct mce
 		if (recordlen > offsetof(struct mce, mcgcap) && m->mcgcap & MCG_CMCI_P)
  			corr_err_cnt = EXTRACT(m->status, 38, 52);
 		memory_error(m, channel[0], dimm[0], corr_err_cnt, recordlen);
+#ifdef __Linux__
 		account_page_error(m, channel[0], dimm[0]);
+#endif
 
 		/* 
 		 * When both DIMMs have a error account the error twice to the page.
 		 */
 		if (channel[1] != -1) {
 			memory_error(m, channel[1], dimm[1], corr_err_cnt, recordlen);
+#ifdef __Linux__
 			account_page_error(m, channel[1], dimm[1]);
+#endif
 		}
 
 		return 1;
