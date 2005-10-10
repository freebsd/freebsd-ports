--- os_freebsd.h.orig	Sun Sep  5 09:16:07 2004
+++ os_freebsd.h	Sat Aug  6 21:08:54 2005
@@ -261,6 +261,262 @@
 
 #endif
 
+#ifdef  HAVE_SYS_TW_OSL_IOCTL_H
+#include <sys/tw_osl_ioctl.h>
+#else
+/*
+ * Following cut out of tw_osl_types.h
+ *
+ */
+
+typedef void			TW_VOID;
+typedef char			TW_INT8;
+typedef unsigned char		TW_UINT8;
+typedef short			TW_INT16;
+typedef unsigned short		TW_UINT16;
+typedef int			TW_INT32;
+typedef unsigned int		TW_UINT32;
+typedef long long		TW_INT64;
+typedef unsigned long long	TW_UINT64;
+
+/*
+ * Following cut out of tw_cl_share.h
+ *
+ */
+
+#pragma pack(1)
+
+struct tw_cl_event_packet {
+	TW_UINT32	sequence_id;
+	TW_UINT32	time_stamp_sec;
+	TW_UINT16	aen_code;
+	TW_UINT8	severity;
+	TW_UINT8	retrieved;
+	TW_UINT8	repeat_count;
+	TW_UINT8	parameter_len;
+	TW_UINT8	parameter_data[98];
+	TW_UINT32	event_src;
+	TW_UINT8	severity_str[20];
+};
+
+#pragma pack()
+
+/*
+ * Following cut out of tw_cl_fwif.h
+ *
+ */
+
+#define TWA_FW_CMD_ATA_PASSTHROUGH		0x11
+
+#define TWA_SENSE_DATA_LENGTH		18
+
+#pragma pack(1)
+/* 7000 structures. */
+struct tw_cl_command_init_connect {
+	TW_UINT8	res1__opcode;	/* 3:5 */
+	TW_UINT8	size;
+	TW_UINT8	request_id;
+	TW_UINT8	res2;
+	TW_UINT8	status;
+	TW_UINT8	flags;
+	TW_UINT16	message_credits;
+	TW_UINT32	features;
+	TW_UINT16	fw_srl;
+	TW_UINT16	fw_arch_id;
+	TW_UINT16	fw_branch;
+	TW_UINT16	fw_build;
+	TW_UINT32	result;
+};
+
+
+/* Structure for downloading firmware onto the controller. */
+struct tw_cl_command_download_firmware {
+	TW_UINT8	sgl_off__opcode;/* 3:5 */
+	TW_UINT8	size;
+	TW_UINT8	request_id;
+	TW_UINT8	unit;
+	TW_UINT8	status;
+	TW_UINT8	flags;
+	TW_UINT16	param;
+	TW_UINT8	sgl[1];
+};
+
+
+/* Structure for hard resetting the controller. */
+struct tw_cl_command_reset_firmware {
+	TW_UINT8	res1__opcode;	/* 3:5 */
+	TW_UINT8	size;
+	TW_UINT8	request_id;
+	TW_UINT8	unit;
+	TW_UINT8	status;
+	TW_UINT8	flags;
+	TW_UINT8	res2;
+	TW_UINT8	param;
+};
+
+
+/* Structure for sending get/set param commands. */
+struct tw_cl_command_param {
+	TW_UINT8	sgl_off__opcode;/* 3:5 */
+	TW_UINT8	size;
+	TW_UINT8	request_id;
+	TW_UINT8	host_id__unit;	/* 4:4 */
+	TW_UINT8	status;
+	TW_UINT8	flags;
+	TW_UINT16	param_count;
+	TW_UINT8	sgl[1];
+};
+
+
+/* Generic command packet. */
+struct tw_cl_command_generic {
+	TW_UINT8	sgl_off__opcode;/* 3:5 */
+	TW_UINT8	size;
+	TW_UINT8	request_id;
+	TW_UINT8	host_id__unit;	/* 4:4 */
+	TW_UINT8	status;
+	TW_UINT8	flags;
+	TW_UINT16	count;	/* block cnt, parameter cnt, message credits */
+};
+
+
+/* Command packet header. */
+struct tw_cl_command_header {
+	TW_UINT8	sense_data[TWA_SENSE_DATA_LENGTH];
+	struct {
+		TW_INT8		reserved[4];
+		TW_UINT16	error;
+		TW_UINT8	padding;
+		TW_UINT8	res__severity;	/* 5:3 */
+	} status_block;
+	TW_UINT8	err_specific_desc[98];
+	struct {
+		TW_UINT8	size_header;
+		TW_UINT16	reserved;
+		TW_UINT8	size_sense;
+	} header_desc;
+};
+
+
+/* 7000 Command packet. */
+union tw_cl_command_7k {
+	struct tw_cl_command_init_connect	init_connect;
+	struct tw_cl_command_download_firmware	download_fw;
+	struct tw_cl_command_reset_firmware	reset_fw;
+	struct tw_cl_command_param		param;
+	struct tw_cl_command_generic		generic;
+	TW_UINT8	padding[1024 - sizeof(struct tw_cl_command_header)];
+};
+
+
+/* 9000 Command Packet. */
+struct tw_cl_command_9k {
+	TW_UINT8	res__opcode;	/* 3:5 */
+	TW_UINT8	unit;
+	TW_UINT16	lun_l4__req_id;	/* 4:12 */
+	TW_UINT8	status;
+	TW_UINT8	sgl_offset; /* offset (in bytes) to sg_list, from the
+					end of sgl_entries */
+	TW_UINT16	lun_h4__sgl_entries;
+	TW_UINT8	cdb[16];
+	TW_UINT8	sg_list[872];/* total struct size =
+					1024-sizeof(cmd_hdr) */
+};
+
+
+/* Full command packet. */
+struct tw_cl_command_packet {
+	struct tw_cl_command_header	cmd_hdr;
+	union {
+		union tw_cl_command_7k	cmd_pkt_7k;
+		struct tw_cl_command_9k cmd_pkt_9k;
+	} command;
+};
+
+#pragma pack()
+
+/*
+ * Following cut out of tw_cl_ioctl.h
+ *
+ */
+
+#pragma pack(1)
+
+/* Structure used to handle GET/RELEASE LOCK ioctls. */
+struct tw_cl_lock_packet {
+	TW_UINT32	timeout_msec;
+	TW_UINT32	time_remaining_msec;
+	TW_UINT32	force_flag;
+};
+
+
+/* Structure used to handle GET COMPATIBILITY INFO ioctl. */
+struct tw_cl_compatibility_packet {
+	TW_UINT8	driver_version[32];/* driver version */
+	TW_UINT16	working_srl;	/* driver & firmware negotiated srl */
+	TW_UINT16	working_branch;	/* branch # of the firmware that the
+					driver is compatible with */
+	TW_UINT16	working_build;	/* build # of the firmware that the
+					driver is compatible with */
+};
+
+
+/* Driver understandable part of the ioctl packet built by the API. */
+struct tw_cl_driver_packet {
+	TW_UINT32	control_code;
+	TW_UINT32	status;
+	TW_UINT32	unique_id;
+	TW_UINT32	sequence_id;
+	TW_UINT32	os_status;
+	TW_UINT32	buffer_length;
+};
+
+#pragma pack()
+
+/*
+ * Following cut out of tw_osl_ioctl.h
+ *
+ */
+
+#pragma pack(1)
+/*
+ * We need the structure below to ensure that the first byte of
+ * data_buf is not overwritten by the kernel, after we return
+ * from the ioctl call.  Note that cmd_pkt has been reduced
+ * to an array of 1024 bytes even though it's actually 2048 bytes
+ * in size.  This is because, we don't expect requests from user
+ * land requiring 2048 (273 sg elements) byte cmd pkts.
+ */
+typedef struct tw_osli_ioctl_no_data_buf {
+	struct tw_cl_driver_packet	driver_pkt;
+	TW_VOID				*pdata; /* points to data_buf */
+	TW_INT8				padding[488 - sizeof(TW_VOID *)];
+	struct tw_cl_command_packet	cmd_pkt;
+} TW_OSLI_IOCTL_NO_DATA_BUF;
+
+#pragma pack()
+
+#define TW_OSL_IOCTL_FIRMWARE_PASS_THROUGH		\
+	_IOWR('T', 202, TW_OSLI_IOCTL_NO_DATA_BUF)
+
+#pragma pack(1)
+
+typedef struct tw_osli_ioctl_with_payload {
+	struct tw_cl_driver_packet	driver_pkt;
+	TW_INT8				padding[488];
+	struct tw_cl_command_packet	cmd_pkt;
+	union {
+		struct tw_cl_event_packet		event_pkt;
+		struct tw_cl_lock_packet		lock_pkt;
+		struct tw_cl_compatibility_packet	compat_pkt;
+		TW_INT8					data_buf[1];
+	} payload;
+} TW_OSLI_IOCTL_WITH_PAYLOAD;
+
+#pragma pack()
+
+#endif
+
 /* 
    The following definitions/macros/prototypes are used for three
    different interfaces, referred to as "the three cases" below.
