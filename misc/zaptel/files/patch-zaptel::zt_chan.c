
$FreeBSD$

--- zaptel/zt_chan.c
+++ zaptel/zt_chan.c
@@ -1267,7 +1267,7 @@
 	struct zt_chan *chan;
 	int channo = 0;
 	int res;
-	int flags;
+	unsigned long flags;
 
 	chan = (struct zt_chan *) (dev->si_drv1);
 
@@ -1282,7 +1282,7 @@
 			return EINVAL;
 		if (channo > ZT_MAX_CHANNELS)
 			return EINVAL;
-		flags = (int)dev->si_drv1;
+		flags = (unsigned long)dev->si_drv1;
 		res = zt_specchan_open(dev, channo, 0);
 		if (!res) {
 			/* Setup the pointer for future stuff */
