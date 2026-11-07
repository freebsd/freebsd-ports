--- source/ni_nvme.c.orig	2026-10-17 00:01:03 UTC
+++ source/ni_nvme.c
@@ -36,7 +36,7 @@
 #include <ntddstor.h>
 #include <winioctl.h>
 #include <Ntddscsi.h>
-#elif __linux__ || __APPLE__
+#elif __linux__ || __APPLE__ || __FreeBSD__
 #if __linux__
 #include <linux/types.h>
 #endif
@@ -107,7 +107,7 @@ ni_retcode_t ni_nvme_check_error_code(int rc, int opco
     }
 }
 
-#ifdef __linux__
+#if defined(__linux__) || defined(__FreeBSD__)
 
 /*!******************************************************************************
  *  \brief  Submit a nvme admin passthrough command to the driver
@@ -433,7 +433,7 @@ int32_t ni_nvme_send_io_cmd(ni_nvme_opcode_t opcode, n
 }
 #endif
 
-#ifdef __linux__
+#if defined(__linux__) || defined(__FreeBSD__)
 
 /*!******************************************************************************
  *  \brief  Compose a nvme io through admin command
@@ -807,5 +807,73 @@ int32_t ni_nvme_batch_cmd_aio(ni_aio_context_t ctx, ni
     }
 
     return rc;
+}
+#endif
+
+#ifdef __FreeBSD__
+// POSIX AIO (aio(4))
+void ni_nvme_setup_aio_iocb(ni_device_handle_t handle, ni_iocb_t *iocb,
+                            void *p_data, uint32_t data_len, uint32_t lba,
+                            int write)
+{
+    memset(iocb, 0, sizeof(ni_iocb_t));
+    iocb->aio_fildes = handle;
+    iocb->aio_lio_opcode = write ? LIO_WRITE : LIO_READ;
+    iocb->aio_reqprio = 0;
+    iocb->aio_buf = p_data;
+    iocb->aio_nbytes = data_len;
+    iocb->aio_offset = (off_t)((uint64_t)lba << LBA_BIT_OFFSET);
+}
+
+// Submit the whole batch and wait for all of it: same semantics as Linux
+// io_submit() followed by io_getevents() with min_nr == nr. A batch is at
+// most NI_MAX_SEGMENT_NUM (4) requests, below AIO_LISTIO_MAX (16).
+int32_t ni_nvme_batch_cmd_aio(ni_aio_context_t ctx, ni_iocb_t **iocbs,
+                              ni_io_event_t *events, int iocb_num)
+{
+    int i;
+
+    (void)ctx;
+    (void)events;
+
+    for (i = 0; i < iocb_num; i++) {
+        ni_iocb_t *iocb = iocbs[i];
+        ni_log(NI_LOG_TRACE, "%s: iocb %d, fdes %d, opcode %d, buf %p,"
+                " nbytes %zu, offset 0x%jx\n", __func__, i, iocb->aio_fildes,
+                iocb->aio_lio_opcode, (void *)iocb->aio_buf, iocb->aio_nbytes,
+                (uintmax_t)iocb->aio_offset);
+    }
+
+    if (iocb_num > AIO_LISTIO_MAX) {
+        ni_log(NI_LOG_ERROR, "%s: ERROR: batch of %d exceeds AIO_LISTIO_MAX\n",
+               __func__, iocb_num);
+        return NI_RETCODE_ERROR_NVME_CMD_FAILED;
+    }
+
+    if (lio_listio(LIO_WAIT, iocbs, iocb_num, NULL) != 0) {
+        ni_log(NI_LOG_ERROR, "%s: ERROR: lio_listio failed, errno=%d\n",
+               __func__, errno);
+        /* fall through: aio_error() below reports which request failed */
+    }
+
+    for (i = 0; i < iocb_num; i++) {
+        ni_iocb_t *iocb = iocbs[i];
+        int err = aio_error(iocb);
+        ssize_t res;
+
+        if (err != 0) {
+            ni_log(NI_LOG_ERROR, "ERROR %s(): aio request %d failed, errno=%d\n",
+                   __func__, i, err);
+            return NI_RETCODE_ERROR_NVME_CMD_FAILED;
+        }
+        res = aio_return(iocb);
+        if (res < 0 || (size_t)res != iocb->aio_nbytes) {
+            ni_log(NI_LOG_ERROR, "ERROR %s(): failed to transfer data, size %zu, res %zd\n",
+                   __func__, iocb->aio_nbytes, res);
+            return NI_RETCODE_ERROR_NVME_CMD_FAILED;
+        }
+    }
+
+    return NI_RETCODE_SUCCESS;
 }
 #endif
