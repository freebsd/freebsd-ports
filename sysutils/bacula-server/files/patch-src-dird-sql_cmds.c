--- src/dird/sql_cmds.c 7 Feb 2004 17:27:11 -00001.22.2.7.2.3
+++ src/dird/sql_cmds.c 23 Jul 2004 09:55:35 -0000
@@ -261,7 +261,7 @@
    "ORDER BY StartTime ASC";


-char *uar_sel_jobid_temp = "SELECT JobId FROM temp";
+char *uar_sel_jobid_temp = "SELECT JobId FROM temp ORDER BY StartTime ASC";

 char *uar_sel_all_temp1 = "SELECT * FROM temp1";
