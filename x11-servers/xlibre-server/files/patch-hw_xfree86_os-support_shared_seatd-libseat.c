From edf810adf72ea32de2e75d39e4cba2dabd28ddb1 Mon Sep 17 00:00:00 2001
From: polaris <251053665+9olaris@users.noreply.github.com>
Date: Mon, 22 Dec 2025 19:30:55 +0000
Subject: [PATCH] Only call xf86platformVTProbe() when defined

Signed-off-by: 9olaris <251053665+9olaris@users.noreply.github.com>
---
 hw/xfree86/os-support/shared/seatd-libseat.c | 6 +++++-
 1 file changed, 5 insertions(+), 1 deletion(-)

diff --git a/hw/xfree86/os-support/shared/seatd-libseat.c b/hw/xfree86/os-support/shared/seatd-libseat.c
index 4eddc05e22..4d9c3ad86f 100644
--- hw/xfree86/os-support/shared/seatd-libseat.c
+++ hw/xfree86/os-support/shared/seatd-libseat.c
@@ -38,14 +38,16 @@
 #include "os.h"
 #include "xf86.h"
 #include "xf86_priv.h"
+#ifdef XSERVER_PLATFORM_BUS
+#include "xf86platformBus_priv.h"
 #include "xf86platformBus.h"
+#endif
 #include "xf86Xinput.h"
 #include "xf86Xinput_priv.h"
 #include "xf86Priv.h"
 #include "globals.h"
 
 #include "config/hotplug_priv.h"
-#include "xf86platformBus_priv.h"
 
 #include "seatd-libseat.h"
 
@@ -89,7 +91,9 @@ enable_seat(struct libseat *seat, void *userdata)
             }
         }
     xf86InputEnableVTProbe(); /* Add any paused input devices */
+    #ifdef XSERVER_PLATFORM_BUS
     xf86platformVTProbe(); /* Probe for outputs */
+    #endif
 }
 
 /*
