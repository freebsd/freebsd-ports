--- src/plugins/job_container/tmpfs/job_container_tmpfs.c.orig	2023-11-21 22:33:29 UTC
+++ src/plugins/job_container/tmpfs/job_container_tmpfs.c
@@ -612,7 +612,7 @@ static int _create_ns(uint32_t job_id, stepd_step_rec_
 			goto exit1;
 		}
 
-		xstrfmtcat(proc_path, "/proc/%u/ns/mnt", cpid);
+		xstrfmtcat(proc_path, "/compat/linux/proc/%u/ns/mnt", cpid);
 
 		/*
 		 * Bind mount /proc/pid/ns/mnt to hold namespace active
