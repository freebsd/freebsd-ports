--- src/plugins/select/cons_res/dist_tasks.c.orig	2013-09-10 16:44:33.000000000 -0500
+++ src/plugins/select/cons_res/dist_tasks.c	2013-11-14 10:23:02.000000000 -0600
@@ -271,6 +271,30 @@
 	return SLURM_SUCCESS;
 }
 
+// These were nested below, which is not legal in standard C
+
+	/* qsort compare function for ascending int list */
+	int _cmp_int_ascend (const void *a, const void *b)
+	{
+		return (*(int*)a - *(int*)b);
+	}
+
+	/* qsort compare function for descending int list */
+	int _cmp_int_descend (const void *a, const void *b)
+	{
+		return (*(int*)b - *(int*)a);
+	}
+
+	int* sockets_cpu_cnt;
+
+	/* qsort compare function for board combination socket
+	 * list */
+	int _cmp_sock (const void *a, const void *b)
+	{
+		 return (sockets_cpu_cnt[*(int*)b] -
+				 sockets_cpu_cnt[*(int*)a]);
+	}
+
 /* sync up core bitmap with new CPU count using a best-fit approach
  * on the available resources on each node
  *
@@ -298,7 +322,6 @@
 	int elig_idx, comb_brd_idx, sock_list_idx, comb_min, board_num;
 	int* boards_cpu_cnt;
 	int* sort_brds_cpu_cnt;
-	int* sockets_cpu_cnt;
 	int* board_combs;
 	int* socket_list;
 	int* elig_brd_combs;
@@ -316,26 +339,6 @@
 	uint64_t ncomb_brd;
 	bool sufficient,best_fit_sufficient;
 
-	/* qsort compare function for ascending int list */
-	int _cmp_int_ascend (const void *a, const void *b)
-	{
-		return (*(int*)a - *(int*)b);
-	}
-
-	/* qsort compare function for descending int list */
-	int _cmp_int_descend (const void *a, const void *b)
-	{
-		return (*(int*)b - *(int*)a);
-	}
-
-	/* qsort compare function for board combination socket
-	 * list */
-	int _cmp_sock (const void *a, const void *b)
-	{
-		 return (sockets_cpu_cnt[*(int*)b] -
-				 sockets_cpu_cnt[*(int*)a]);
-	}
-
 	if (!job_res)
 		return;
 
