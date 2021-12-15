--- src/aircrack-ng.c.orig	2018-12-09 22:53:44 UTC
+++ src/aircrack-ng.c
@@ -149,7 +149,7 @@ struct WPA_data wpa_data[MAX_THREADS];
 int wpa_wordlists_done = 0;
 static pthread_mutex_t mx_nb = PTHREAD_MUTEX_INITIALIZER;
 static pthread_mutex_t mx_wpastats = PTHREAD_MUTEX_INITIALIZER;
-ac_cpuset_t * cpuset = NULL;
+static ac_cpuset_t * acng_cpuset = NULL;
 
 #define GOT_IV 0x00000001
 #define USE_IV 0x00000002
@@ -690,10 +690,10 @@ static void clean_exit(int ret)
 	dso_ac_crypto_engine_destroy(&engine);
 	ac_crypto_engine_loader_unload();
 
-	if (cpuset != NULL)
+	if (acng_cpuset != NULL)
 	{
-		ac_cpuset_destroy(cpuset);
-		ac_cpuset_free(cpuset);
+		ac_cpuset_destroy(acng_cpuset);
+		ac_cpuset_free(acng_cpuset);
 	}
 
 	if (opt.totaldicts)
@@ -5371,10 +5371,10 @@ static int perform_wpa_crack(struct AP_info * ap_cur)
 		return missing_wordlist_dictionary(ap_cur);
 	}
 
-	cpuset = ac_cpuset_new();
-	ALLEGE(cpuset);
-	ac_cpuset_init(cpuset);
-	ac_cpuset_distribute(cpuset, (size_t) opt.nbcpu);
+	acng_cpuset = ac_cpuset_new();
+	ALLEGE(acng_cpuset);
+	ac_cpuset_init(acng_cpuset);
+	ac_cpuset_distribute(acng_cpuset, (size_t) opt.nbcpu);
 
 	ap_cur = get_first_target();
 
@@ -5462,7 +5462,7 @@ static int perform_wpa_crack(struct AP_info * ap_cur)
 				return (FAILURE);
 			}
 
-			ac_cpuset_bind_thread_at(cpuset, tid[id], (size_t) i);
+			ac_cpuset_bind_thread_at(acng_cpuset, tid[id], (size_t) i);
 
 			id++;
 		}
