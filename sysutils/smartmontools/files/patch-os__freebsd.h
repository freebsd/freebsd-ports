--- os_freebsd.h.orig	2018-08-19 18:45:53 UTC
+++ os_freebsd.h
@@ -606,4 +606,164 @@ HPT_PASS_THROUGH_HEADER, *PHPT_PASS_THROUGH_HEADER;
 #define __unused __attribute__ ((__unused__))
 #endif
 
+// MFI definition from the kernel sources, see sys/dev/mfi
+
+#define MFI_STAT_OK          0x00
+#define MFI_DCMD_PD_GET_LIST 0x02010000
+
+#define MFI_CTRLR_PREFIX	"/dev/mfi"
+#define MRSAS_CTRLR_PREFIX	"/dev/mrsas"
+
+/*
+ * MFI Frame flags
+ */
+#define MFI_FRAME_POST_IN_REPLY_QUEUE           0x0000
+#define MFI_FRAME_DONT_POST_IN_REPLY_QUEUE      0x0001
+#define MFI_FRAME_SGL32                         0x0000
+#define MFI_FRAME_SGL64                         0x0002
+#define MFI_FRAME_SENSE32                       0x0000
+#define MFI_FRAME_SENSE64                       0x0004
+#define MFI_FRAME_DIR_NONE                      0x0000
+#define MFI_FRAME_DIR_WRITE                     0x0008
+#define MFI_FRAME_DIR_READ                      0x0010
+#define MFI_FRAME_DIR_BOTH                      0x0018
+#define MFI_FRAME_IEEE_SGL                      0x0020
+#define MFI_FRAME_FMT "\20" \
+    "\1NOPOST" \
+    "\2SGL64" \
+    "\3SENSE64" \
+    "\4WRITE" \
+    "\5READ" \
+    "\6IEEESGL"
+
+/* MFI Commands */
+typedef enum {
+    MFI_CMD_INIT =              0x00,
+    MFI_CMD_LD_READ,
+    MFI_CMD_LD_WRITE,
+    MFI_CMD_LD_SCSI_IO,
+    MFI_CMD_PD_SCSI_IO,
+    MFI_CMD_DCMD,
+    MFI_CMD_ABORT,
+    MFI_CMD_SMP,
+    MFI_CMD_STP
+} mfi_cmd_t;
+
+/* Scatter Gather elements */
+struct mfi_sg32 {
+    uint32_t    addr;
+    uint32_t    len;
+} __packed;
+
+struct mfi_sg64 {
+    uint64_t    addr;
+    uint32_t    len;
+} __packed;
+
+struct mfi_sg_skinny {
+    uint64_t    addr;
+    uint32_t    len;
+    uint32_t    flag;
+} __packed;
+
+union mfi_sgl {
+    struct mfi_sg32             sg32[1];
+    struct mfi_sg64             sg64[1];
+    struct mfi_sg_skinny        sg_skinny[1];
+} __packed;
+
+/* Message frames.  All messages have a common header */
+struct mfi_frame_header {
+    uint8_t             cmd;
+    uint8_t             sense_len;
+    uint8_t             cmd_status;
+    uint8_t             scsi_status;
+    uint8_t             target_id;
+    uint8_t             lun_id;
+    uint8_t             cdb_len;
+    uint8_t             sg_count;
+    uint32_t    context;
+    /*
+     * pad0 is MSI Specific. Not used by Driver. Zero the value before
+     * sending the command to f/w.
+     */
+    uint32_t    pad0;
+    uint16_t    flags;
+#define MFI_FRAME_DATAOUT       0x08
+#define MFI_FRAME_DATAIN        0x10
+    uint16_t    timeout;
+    uint32_t    data_len;
+} __packed;
+
+#define MFI_PASS_FRAME_SIZE 48
+struct mfi_pass_frame {
+    struct mfi_frame_header header;
+    uint32_t    sense_addr_lo;
+    uint32_t    sense_addr_hi;
+    uint8_t             cdb[16];
+    union mfi_sgl       sgl;
+} __packed;
+
+#define MFI_DCMD_FRAME_SIZE     40
+#define MFI_MBOX_SIZE           12
+
+struct mfi_dcmd_frame {
+    struct mfi_frame_header header;
+    uint32_t	opcode;
+    uint8_t		mbox[MFI_MBOX_SIZE];
+    union mfi_sgl	sgl;
+} __packed;
+
+#define MAX_IOCTL_SGE   16
+struct mfi_ioc_packet {
+    uint16_t    mfi_adapter_no;
+    uint16_t    mfi_pad1;
+    uint32_t    mfi_sgl_off;
+    uint32_t    mfi_sge_count;
+    uint32_t    mfi_sense_off;
+    uint32_t    mfi_sense_len;
+    union {
+        uint8_t raw[128];
+        struct mfi_frame_header hdr;
+    } mfi_frame;
+
+    struct iovec mfi_sgl[MAX_IOCTL_SGE];
+} __packed;
+
+#ifdef COMPAT_FREEBSD32
+struct mfi_ioc_packet32 {
+    uint16_t    mfi_adapter_no;
+    uint16_t    mfi_pad1;
+    uint32_t    mfi_sgl_off;
+    uint32_t    mfi_sge_count;
+    uint32_t    mfi_sense_off;
+    uint32_t    mfi_sense_len;
+    union {
+        uint8_t raw[128];
+        struct mfi_frame_header hdr;
+    } mfi_frame;
+
+    struct iovec32 mfi_sgl[MAX_IOCTL_SGE];
+} __packed;
+#endif
+
+struct mfi_pd_address {
+    uint16_t		device_id;
+    uint16_t		encl_device_id;
+    uint8_t			encl_index;
+    uint8_t			slot_number;
+    uint8_t			scsi_dev_type;	/* 0 = disk */
+    uint8_t			connect_port_bitmap;
+    uint64_t		sas_addr[2];
+} __packed;
+
+#define MAX_SYS_PDS 240
+struct mfi_pd_list {
+    uint32_t		size;
+    uint32_t		count;
+    struct mfi_pd_address	addr[MAX_SYS_PDS];
+} __packed;
+
+#define MFI_CMD		_IOWR('M', 1, struct mfi_ioc_packet)
+
 #endif /* OS_FREEBSD_H_ */
