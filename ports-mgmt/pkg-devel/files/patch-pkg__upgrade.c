--- ./pkg/upgrade.c.orig	2013-09-25 07:37:38.657129024 -0500
+++ ./pkg/upgrade.c	2013-09-25 07:37:52.227152887 -0500
@@ -151,7 +151,7 @@
 
 	if (!quiet || dry_run) {
 		print_jobs_summary(jobs,
-		    "Uprgades have been requested for the following %d "
+		    "Upgrades have been requested for the following %d "
 		    "packages:\n\n", nbactions);
 
 		if (!yes && !dry_run)
