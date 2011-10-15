--- ./intel.c.orig	2009-12-15 07:18:40.000000000 -0500
+++ ./intel.c	2011-10-14 22:36:47.000000000 -0400
@@ -38,7 +38,7 @@
 			return CPU_CORE2;
 		else if (model == 0x1d)
 			return CPU_DUNNINGTON;
-		else if (model == 0x1a)
+		else if (model == 0x1a || model == 0x2c) /* Nehalem/Westmere */
 			return CPU_NEHALEM;
 
 		if (model >= 0x1a) 
@@ -79,7 +79,9 @@
  			corr_err_cnt = EXTRACT(m->status, 38, 52);
 		memory_error(m, channel, dimm, corr_err_cnt, recordlen);
 
+#ifdef __Linux__
 		account_page_error(m, channel, dimm, corr_err_cnt);
+#endif
 
 		return 1;
 	}
