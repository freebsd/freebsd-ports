--- src/sonypi.h.orig	Sat Aug 17 20:38:56 2002
+++ src/sonypi.h	Sat Aug 17 20:38:56 2002
@@ -0,0 +1,84 @@
+#include <stdio.h>
+#include <stdlib.h>
+#include <unistd.h>
+#include <fcntl.h>
+#include <errno.h>
+#include <sys/mman.h>
+#include <dirent.h>
+#include <ctype.h>
+#include <string.h>
+#include <signal.h>
+#include <sys/pciio.h>
+#define O_SYNC O_FSYNC
+#include <sys/stat.h>
+#include <sys/time.h>
+
+typedef unsigned char u8;
+typedef unsigned short u16;
+typedef unsigned u32;
+
+#define PAGE_SIZE 0x1000
+
+#define SONYPI_DEV "/proc/bus/pci/00/07.3"
+
+#define SPIC_PCI_VENDOR 0x8086
+#define SPIC_PCI_DEVICE 0x7113
+
+/* the irq selection is 2 bits in the following port */
+#define SPI_IRQ_PORT 0x8034
+#define SPI_IRQ_SHIFT 22
+
+#define SPI_BASE 0x50
+
+#define SPI_G10A (SPI_BASE+0x14)
+#define SPI_G10L (SPI_BASE+0x16) /* 4 bits at this offset - the port offset of
+				    2nd port from first */
+#define SPIC_PORT1 0x10a0
+#define SPIC_PORT2 0x10a4
+
+#define SPIC_CAMERA_BRIGHTNESS 0
+#define SPIC_CAMERA_CONTRAST 1
+#define SPIC_CAMERA_HUE 2
+#define SPIC_CAMERA_COLOR 3
+#define SPIC_CAMERA_SHARPNESS 4
+
+#define SPIC_CAMERA_PICTURE 5
+#define SPIC_CAMERA_EXPOSURE_MASK 0xC
+#define SPIC_CAMERA_WHITE_BALANCE_MASK 0x3
+#define SPIC_CAMERA_PICTURE_MODE_MASK 0x30
+#define SPIC_CAMERA_MUTE_MASK 0x40
+
+/* the rest don't need a loop until not 0xff */
+#define SPIC_CAMERA_AGC 6
+#define SPIC_CAMERA_AGC_MASK 0x30
+#define SPIC_CAMERA_SHUTTER_MASK 0x7
+
+#define SPIC_CAMERA_SHUTDOWN_REQUEST 7
+#define SPIC_CAMERA_CONTROL 0x10
+
+#define SPIC_CAMERA_STATUS 7
+#define SPIC_CAMERA_STATUS_READY 0x2
+#define SPIC_CAMERA_STATUS_POSITION 0x4
+
+#define SPIC_DIRECTION_BACKWARDS 0x4
+
+#define SPIC_CAMERA_REVISION 8
+#define SPIC_CAMERA_ROMVERSION 9
+
+
+#define SPIC_EVENT_CAPTURE_BUTTON 0x20
+#define SPIC_EVENT_CAPTURE_PARTIAL 0x05
+#define SPIC_EVENT_CAPTURE_FULL 0x07
+
+#define JOGGER_V1 0x1
+#define JOGGER_V2 0x19
+
+#define BRIGHTNESS_V1 0x15
+#define BRIGHTNESS_V2 0x29
+
+#define VOLUME_V1 0x14
+#define VOLUME_V2 0x29
+
+#define MUTE_V1 0x13
+#define MUTE_V2 0x29
+
