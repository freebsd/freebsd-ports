--- drivers/mmc/mmc.c.orig	2016-04-12 02:22:25 UTC
+++ drivers/mmc/mmc.c
@@ -23,6 +23,7 @@
 
 static struct list_head mmc_devices;
 static int cur_dev_num = -1;
+static int mmc_error_print_max = -1;
 
 __weak int board_mmc_getwp(struct mmc *mmc)
 {
@@ -1586,9 +1587,14 @@ void mmc_destroy(struct mmc *mmc)
 struct blk_desc *mmc_get_dev(int dev)
 {
 	struct mmc *mmc = find_mmc_device(dev);
-	if (!mmc || mmc_init(mmc))
+	if (!mmc)
 		return NULL;
 
+	/* If mmc_init fails, mmc->block_dev will be of type
+	 * DEV_TYPE_UNKNOWN with blksz and lba set to zero.
+	 */
+	mmc_init(mmc);
+
 	return &mmc->block_dev;
 }
 #endif
@@ -1623,7 +1629,7 @@ int mmc_start_init(struct mmc *mmc)
 	err = mmc->cfg->ops->init(mmc);
 
 	if (err)
-		return err;
+		goto done;
 
 	mmc->ddr_mode = 0;
 	mmc_set_bus_width(mmc, 1);
@@ -1633,7 +1639,7 @@ int mmc_start_init(struct mmc *mmc)
 	err = mmc_go_idle(mmc);
 
 	if (err)
-		return err;
+		goto done;
 
 	/* The internal partition reset to user partition(0) at every CMD0*/
 	mmc->block_dev.hwpart = 0;
@@ -1650,15 +1656,31 @@ int mmc_start_init(struct mmc *mmc)
 
 		if (err) {
 #if !defined(CONFIG_SPL_BUILD) || defined(CONFIG_SPL_LIBCOMMON_SUPPORT)
-			printf("Card did not respond to voltage select!\n");
+			if (mmc_error_print_max < 4) {
+				mmc_error_print_max++;
+				printf("Card did not respond to voltage select!\n");
+				if (mmc_error_print_max == 4) {
+					printf("Discarding further error messages\n");
+				}
+			}
 #endif
-			return UNUSABLE_ERR;
+			goto done;
 		}
 	}
 
 	if (!err)
 		mmc->init_in_progress = 1;
 
+done:
+	if (err) {
+		mmc->has_init = 0;
+		mmc->block_dev.type = DEV_TYPE_UNKNOWN;
+		mmc->block_dev.blksz = 0;
+		mmc->block_dev.lba = 0;
+	} else {
+		mmc->has_init = 1;
+	}
+
 	return err;
 }
 
