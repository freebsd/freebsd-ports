--- lib/functions.php.orig	2016-05-28 10:58:17.522042409 +0100
+++ lib/functions.php	2016-05-28 11:00:31.399032747 +0100
@@ -670,8 +670,10 @@
 	$issue_log_message   = false;
 	$ping_failure_count  = read_config_option("ping_failure_count");
 	$ping_recovery_count = read_config_option("ping_recovery_count");
-	$hosts[$host_id]["status_fail_date"] = '0000-00-00 00:00:00';
-	$hosts[$host_id]["status_rec_date"] = '0000-00-00 00:00:00';
+	if ((!isset($hosts[$host_id]["status_fail_date"])) || ($hosts[$host_id]["status_fail_date"] == ""))
+		$hosts[$host_id]["status_fail_date"] = '0000-00-00 00:00:00';
+	if ((!isset($hosts[$host_id]["status_rec_date"])) || ($hosts[$host_id]["status_rec_date"] == ""))
+		$hosts[$host_id]["status_rec_date"] = '0000-00-00 00:00:00';
 
 	if ($status == HOST_DOWN) {
 		/* update total polls, failed polls and availability */
