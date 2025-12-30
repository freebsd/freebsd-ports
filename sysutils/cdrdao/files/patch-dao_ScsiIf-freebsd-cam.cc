--- dao/ScsiIf-freebsd-cam.cc.orig	2025-12-05 11:17:35 UTC
+++ dao/ScsiIf-freebsd-cam.cc
@@ -115,8 +115,8 @@ int ScsiIf::sendCmd(const unsigned char *cmd, int cmdL
 	u_int8_t *	data_ptr = NULL;
 	size_t		data_len = 0;
 
-	bzero(impl_->ccb, sizeof(union ccb));
-	bcopy(cmd, &impl_->ccb->csio.cdb_io.cdb_bytes, cmdLen);
+	memset(impl_->ccb, 0, sizeof(union ccb));
+	memmove(&impl_->ccb->csio.cdb_io.cdb_bytes, cmd, cmdLen);
 
 	if (dataOut && dataOutLen > 0) {
 		data_ptr = (u_int8_t*) dataOut;
@@ -176,8 +176,8 @@ int ScsiIf::inquiry()
 	int i;
 	struct scsi_inquiry_data inq_data;
 
-	bzero(impl_->ccb, sizeof(union ccb));
-	bzero(&inq_data, sizeof(inq_data));
+	memset(impl_->ccb, 0, sizeof(union ccb));
+	memset(&inq_data, 0, sizeof(inq_data));
 
 	scsi_inquiry(&impl_->ccb->csio,
 		     DEF_RETRY_COUNT,
