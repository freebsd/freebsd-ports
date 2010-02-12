--- src/dird/ua_prune.c~	2010-01-25 07:56:28.000000000 +0000
+++ src/dird/ua_prune.c	2010-01-26 13:31:52.000000000 +0000
@@ -389,7 +389,7 @@
     * Select all files that are older than the JobRetention period
     *  and stuff them into the "DeletionCandidates" table.
     */
-   edit_utime(now-period, ed1, sizeof(ed1));
+   edit_utime(period, ed1, sizeof(ed1));
    Jmsg(ua->jcr, M_INFO, 0, _("Begin pruning Jobs older than %s.\n"), ed1);
    edit_int64(now - period, ed1);
    Mmsg(query, insert_delcand, (char)JobType, ed1, 
