--- exclude.c.orig	Sun Feb 27 16:34:27 2005
+++ exclude.c	Sat May 21 18:52:41 2005
@@ -1109,7 +1109,7 @@
 		    && !(ent->match_flags & MATCHFLG_MERGE_FILE)) {
 			int f = am_sender || protocol_version < 29 ? f_out : -1;
 			send_rules(f, &cvs_filter_list);
-			if (f >= 0)
+			if (f >= 0 || f_out < 0)
 				continue;
 		}
 		p = get_rule_prefix(ent->match_flags, ent->pattern, 1, &plen);
