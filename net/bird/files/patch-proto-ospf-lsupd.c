diff --git a/proto/ospf/lsupd.c b/proto/ospf/lsupd.c
index a5da425..b19f261 100644
--- proto/ospf/lsupd.c
+++ proto/ospf/lsupd.c
@@ -205,7 +205,7 @@ ospf_lsupd_flood(struct proto_ospf *po,
 	    en->lsa_body = NULL;
 	    DBG("Removing from lsreq list for neigh %R\n", nn->rid);
 	    ospf_hash_delete(nn->lsrqh, en);
-	    if (EMPTY_SLIST(nn->lsrql))
+	    if ((EMPTY_SLIST(nn->lsrql)) && (nn->state == NEIGHBOR_LOADING))
 	      ospf_neigh_sm(nn, INM_LOADDONE);
 	    continue;
 	    break;
@@ -216,7 +216,7 @@ ospf_lsupd_flood(struct proto_ospf *po,
 	    en->lsa_body = NULL;
 	    DBG("Removing from lsreq list for neigh %R\n", nn->rid);
 	    ospf_hash_delete(nn->lsrqh, en);
-	    if (EMPTY_SLIST(nn->lsrql))
+	    if ((EMPTY_SLIST(nn->lsrql)) && (nn->state == NEIGHBOR_LOADING))
 	      ospf_neigh_sm(nn, INM_LOADDONE);
 	    break;
 	  default:
