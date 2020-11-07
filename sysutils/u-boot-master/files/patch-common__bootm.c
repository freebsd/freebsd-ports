From 7d25c0b01248fbfbbcdf668cc1c080fe0b54978f Mon Sep 17 00:00:00 2001
From: Emmanuel Vadot <manu@FreeBSD.org>
Date: Sat, 7 Nov 2020 19:42:31 +0100
Subject: [PATCH 2/2] Add FreeBSD hack that does not disable usb when
 efi_exit_boot_service is called
Content-Type: text/plain; charset=UTF-8

---
 common/bootm.c | 5 +++++
 1 file changed, 5 insertions(+)

diff --git a/common/bootm.c b/common/bootm.c
index b3377490b3..22476fc7c9 100644
--- common/bootm.c
+++ common/bootm.c
@@ -458,7 +458,12 @@ ulong bootm_disable_interrupts(void)
 	 * updated every 1 ms within the HCCA structure in SDRAM! For more
 	 * details see the OpenHCI specification.
 	 */
+	/*
+	 * FreeBSD Hack, on some board this cause efi_exit_bootservice to hang
+	 * for some yet unknown reason.
+	 * This only does this when doing netboot ???
 	usb_stop();
+	*/
 #endif
 	return iflag;
 }
-- 
2.28.0

