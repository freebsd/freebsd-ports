--- freebsd/drivers/dahdi/wct4xxp/base.c.orig	2010-03-03 19:04:37.000000000 +0600
+++ freebsd/drivers/dahdi/wct4xxp/base.c	2010-03-03 19:04:51.000000000 +0600
@@ -3070,7 +3070,6 @@
 {
 	struct t4 *wc = (struct t4 *)data;
 
-	DPRINTF(wc->dev, "%s\n", __FUNCTION__);
 #ifdef VPM_SUPPORT
 	if (wc->vpm) {
 		if (test_and_clear_bit(T4_CHECK_VPM, &wc->checkflag)) {
@@ -3214,7 +3213,6 @@
 	res = FILTER_HANDLED;
 #endif
 	if (unlikely(test_bit(T4_CHECK_VPM, &wc->checkflag))) {
-		DPRINTF(wc->dev, "scheduling filter thread\n");
 #if defined(__FreeBSD__)
 		res |= FILTER_SCHEDULE_THREAD;
 #else
