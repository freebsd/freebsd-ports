$FreeBSD$

--- source/smbd/trans2.c	2003/03/07 23:35:00	1.149.4.98
+++ source/smbd/trans2.c	2003/03/25 23:50:47	1.149.4.99
@@ -3043,7 +3043,7 @@
 {
 	char *params = *pparams;
 	enum remote_arch_types ra_type = get_remote_arch();
-	BOOL NT_arch = ((ra_type == RA_WINNT) || (ra_type == RA_WIN2K));
+	BOOL NT_arch = ((ra_type == RA_WINNT) || (ra_type == RA_WIN2K) || (ra_type == RA_WINXP) || (ra_type == RA_WIN2K3));
 	pstring pathname;
 	int reply_size = 0;
 	int max_referral_level;
