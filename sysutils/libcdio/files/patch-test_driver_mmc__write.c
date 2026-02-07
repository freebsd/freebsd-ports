Fix segmentation fault

--- test/driver/mmc_write.c.orig	2018-03-30 10:51:54 UTC
+++ test/driver/mmc_write.c
@@ -118,7 +118,7 @@ handle_outcome(CdIo_t *p_cdio, driver_return_code_t i_
     print_status_sense(i_status, *pi_sense_avail, p_temp_sense_reply, i_flag & 1);
     if (18 <= *pi_sense_avail) {
         memset(p_sense_reply, 0, sizeof(cdio_mmc_request_sense_t));
-        memcpy(p_sense_reply, p_temp_sense_reply, *pi_sense_avail);
+        memcpy(p_sense_reply, p_temp_sense_reply, sizeof(cdio_mmc_request_sense_t));
     } else
         memset(p_sense_reply, 0, sizeof(cdio_mmc_request_sense_t));
     cdio_free(p_temp_sense_reply);
