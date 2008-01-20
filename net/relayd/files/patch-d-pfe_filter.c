--- relayd/pfe_filter.c.orig	2007-12-21 05:15:43.000000000 +0900
+++ relayd/pfe_filter.c	2008-01-20 15:31:28.856798863 +0900
@@ -89,6 +89,7 @@
 		    sizeof(tables[i].pfrt_name))
 			goto toolong;
 		tables[i].pfrt_flags |= PFR_TFLAG_PERSIST;
+		log_debug("init_tables: prepare anchor \"%s\" and table \"%s\"", tables[i].pfrt_anchor, tables[i].pfrt_name);
 		i++;
 	}
 	if (i != env->rdrcount)
@@ -239,10 +240,15 @@
 	    sizeof(io.pfrio_table.pfrt_name)) >=
 	    sizeof(io.pfrio_table.pfrt_name))
 		goto toolong;
+	/* pfctl -Tflush */
 	if (ioctl(env->pf->dev, DIOCRCLRADDRS, &io) == -1)
 		fatal("flush_table: cannot flush table addresses");
+	/* pfctl -Tzero */
+#if 0
+	/* XXX: ioctl(DIOCRCLRTSTATS) requires io.pfrio_esize to be set as sizeof(struct pfr_table), but here doesn't set it. */
 	if (ioctl(env->pf->dev, DIOCRCLRTSTATS, &io) == -1)
 		fatal("flush_table: cannot flush table stats");
+#endif
 	log_debug("flush_table: flushed table %s", rdr->conf.name);
 	return;
 
@@ -321,7 +327,9 @@
 		rio.rule.dst.addr.type = PF_ADDR_ADDRMASK;
 		rio.rule.dst.port_op = PF_OP_EQ;
 		rio.rule.dst.port[0] = address->port;
+#if 0
 		rio.rule.rtableid = -1; /* stay in the main routing table */
+#endif
 		rio.rule.action = PF_RDR;
 		if (strlen(rdr->conf.tag))
 			(void)strlcpy(rio.rule.tagname, rdr->conf.tag,
@@ -362,7 +370,7 @@
 
 		if (ioctl(env->pf->dev, DIOCADDRULE, &rio) == -1)
 			fatal("cannot add rule");
-		log_debug("sync_ruleset: rule added");
+		log_debug("sync_ruleset: rule added into anchor \"%s\", table \"%s\"", rio.anchor, pio.addr.addr.v.tblname);
 	}
 	if (transaction_commit(env) == -1)
 		log_warn("sync_ruleset: add rules transaction failed");
