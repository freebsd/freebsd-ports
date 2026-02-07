--- mdnsd/mdns.c.orig	2017-03-10 09:24:12 UTC
+++ mdnsd/mdns.c
@@ -45,6 +45,9 @@ extern struct mdnsd_conf	*conf;
 struct question_tree		 question_tree;
 struct cache_tree		 cache_tree;
 
+pg_q pg_queue;
+pge_q pge_queue;
+
 /*
  * RR cache
  */
@@ -155,8 +158,10 @@ cache_process(struct rr *rr)
 					/* TODO Cancel possible deletion */
 					log_warnx("cache_process: recover %s",
 					    rrs_str(&rr->rrs));
+					free(rr);
 					return (0);
 				}
+				free(rr);
 				return (0);
 			}
 			/*
@@ -167,6 +172,7 @@ cache_process(struct rr *rr)
 				log_warnx("cache_process: conflict for %s",
 				    rrs_str(&rr->rrs));
 				conflict_resolve_by_rr(rr_aux);
+				free(rr);
 				return (-1);
 			}
 		}
@@ -178,6 +184,7 @@ cache_process(struct rr *rr)
 					log_warnx("cache_process: goodbye %s",
 					    rrs_str(&rr->rrs));
 					cache_delete(rr_aux);
+					free(rr);
 					return (0);
 				}
 				/* Cache refresh */
@@ -186,14 +193,17 @@ cache_process(struct rr *rr)
 				rr_aux->ttl = rr->ttl;
 				rr_aux->revision = 0;
 				cache_schedrev(rr_aux);
+				free(rr);
 
 				return (0);
 			}
 		}
 	}
 	/* Got a goodbye for a record we don't have */
-	if (rr->ttl == 0)
+	if (rr->ttl == 0) {
+		free(rr);
 		return (0);
+	}
 
 	return (cache_insert(rr));
 }
