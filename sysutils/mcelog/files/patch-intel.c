--- intel.c.orig	2010-01-20 18:36:52.000000000 -0800
+++ intel.c	2012-09-22 01:58:40.204115724 -0700
@@ -43,7 +43,7 @@
 			return CPU_CORE2;
 		else if (model == 0x1d)
 			return CPU_DUNNINGTON;
-		else if (model == 0x1a)
+		else if (model == 0x1a || model == 0x2c) /* Nehalem/Westmere */
 			return CPU_NEHALEM;
 		else if (model == 0x2e)
 			return CPU_XEON75XX;
@@ -94,14 +94,18 @@
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
