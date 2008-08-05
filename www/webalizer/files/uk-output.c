--- output.c.orig	2008-07-01 00:04:39.000000000 +0200
+++ output.c	2008-08-05 21:30:12.000000000 +0200
@@ -534,13 +534,13 @@
       "<TD ALIGN=right COLSPAN=2><FONT SIZE=\"-1\"><B>%llu</B>"              \
       "</FONT></TD></TR>\n",msg_mtot_tf,t_file);
    /* Total Pages */
-   fprintf(out_fp,"<TR><TD WIDTH=380><FONT SIZE=\"-1\">%s %s</FONT></TD>\n"  \
+   fprintf(out_fp,"<TR><TD WIDTH=380><FONT SIZE=\"-1\">%s</FONT></TD>\n"  \
       "<TD ALIGN=right COLSPAN=2><FONT SIZE=\"-1\"><B>%llu</B>"              \
-      "</FONT></TD></TR>\n",msg_h_total, msg_h_pages, t_page);
+      "</FONT></TD></TR>\n",msg_mtot_tp, t_page);
    /* Total Visits */
-   fprintf(out_fp,"<TR><TD WIDTH=380><FONT SIZE=\"-1\">%s %s</FONT></TD>\n"  \
+   fprintf(out_fp,"<TR><TD WIDTH=380><FONT SIZE=\"-1\">%s</FONT></TD>\n"  \
       "<TD ALIGN=right COLSPAN=2><FONT SIZE=\"-1\"><B>%llu</B>"              \
-      "</FONT></TD></TR>\n",msg_h_total, msg_h_visits, t_visit);
+      "</FONT></TD></TR>\n",msg_mtot_tv, t_visit);
    /* Total XFer */
    fprintf(out_fp,"<TR><TD WIDTH=380><FONT SIZE=\"-1\">%s</FONT></TD>\n"     \
       "<TD ALIGN=right COLSPAN=2><FONT SIZE=\"-1\"><B>%.0f</B>"              \
