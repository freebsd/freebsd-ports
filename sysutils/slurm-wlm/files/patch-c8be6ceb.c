diff --git a/src/scancel/scancel.c b/src/scancel/scancel.c
index 4448b75599..23594fe0bf 100644
--- src/scancel/scancel.c
+++ src/scancel/scancel.c
@@ -99,6 +99,7 @@ static	pthread_cond_t   num_active_threads_cond;
 static	pthread_mutex_t  max_delay_lock;
 static	uint32_t max_resp_time = 0;
 static	int request_count = 0;
+opt_t opt;
 
 int
 main (int argc, char **argv)
diff --git a/src/scancel/scancel.h b/src/scancel/scancel.h
index a0c9d8a829..678bcd7616 100644
--- src/scancel/scancel.h
+++ src/scancel/scancel.h
@@ -75,7 +75,7 @@ typedef struct scancel_options {
 	bool *job_pend;		/* Set fi job is pending	*/
 } opt_t;
 
-opt_t opt;
+extern opt_t opt;
 
 /* process options:
  * 1. set defaults
