--- src/rss.c.orig
+++ src/rss.c
@@ -67,7 +67,7 @@ static void rss_process_info(char *p, int p_max_size, char *uri, char *action, i
 		curloc->result = malloc(sizeof(PRSS));
 		memset(curloc->result, 0, sizeof(PRSS));
 		curloc->process_function = &prss_parse_data;
-		ccurl_init_thread(curloc, interval);
+		ccurl_init_thread(curloc, interval * 60);
 		if (!curloc->p_timed_thread) {
 			NORM_ERR("error setting up RSS thread");
 		}
