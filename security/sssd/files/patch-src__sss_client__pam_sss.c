From 86816db5982df0c1b0c5f5722e23111c62ff362e Mon Sep 17 00:00:00 2001
From: Lukas Slebodnik <lukas.slebodnik@intrak.sk>
Date: Sat, 27 Jul 2013 15:02:31 +0200
Subject: [PATCH 31/34] patch-src__sss_client__pam_sss.c

---
 src/sss_client/pam_sss.c | 2 ++
 1 file changed, 2 insertions(+)

diff --git src/sss_client/pam_sss.c src/sss_client/pam_sss.c
index 3734c8f..7110d38 100644
--- src/sss_client/pam_sss.c
+++ src/sss_client/pam_sss.c
@@ -125,10 +125,12 @@ static void free_exp_data(pam_handle_t *pamh, void *ptr, int err)
 
 static void close_fd(pam_handle_t *pamh, void *ptr, int err)
 {
+#ifdef PAM_DATA_REPLACE
     if (err & PAM_DATA_REPLACE) {
         /* Nothing to do */
         return;
     }
+#endif /* PAM_DATA_REPLACE */
 
     D(("Closing the fd"));
     sss_pam_close_fd();
-- 
1.8.0

