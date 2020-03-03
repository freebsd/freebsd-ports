--- lib/sg_pt_freebsd.c.orig	2019-02-11 01:43:25 UTC
+++ lib/sg_pt_freebsd.c
@@ -1181,8 +1181,12 @@ nvme_pt_low(struct freebsd_dev_channel *fdc_p, void * 
     err = ioctl(fdc_p->dev_fd, NVME_PASSTHROUGH_CMD, npcp);
     if (err < 0)
         return -errno;  /* Assume Unix error in normal place */
+#if __FreeBSD_version <= 1200058
+    sct_sc = ((npcp->cpl.status.sct << 8) | npcp->cpl.status.sc);
+#else
     sct_sc = (NVME_STATUS_GET_SCT(npcp->cpl.status) << 8) |
              NVME_STATUS_GET_SC(npcp->cpl.status);
+#endif
     fdc_p->nvme_result = npcp->cpl.cdw0;
     sg_put_unaligned_le32(npcp->cpl.cdw0,
                           fdc_p->cq_dw0_3 + SG_NVME_PT_CQ_RESULT);
