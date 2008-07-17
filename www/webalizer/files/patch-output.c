--- output.c.orig	2008-06-10 09:50:08.000000000 +0200
+++ output.c	2008-06-20 18:43:04.000000000 +0200
@@ -989,6 +989,20 @@
       hptr=*pointer++;
       if (hptr->flag == OBJ_REG)
       {
+#ifdef USE_CLICKABLE_REFERER
+         if (strstr(hptr->string,"://")!=NULL)
+            fprintf(out_fp,
+               "%-8llu %6.02f%%  %8llu %6.02f%%  %8.0f %6.02f%%  "            \
+               "%8llu %6.02f%%  <A HREF=\"%s\">%s</A>\n",
+               hptr->count,
+               (t_hit==0)?0:((float)hptr->count/t_hit)*100.0,hptr->files,
+               (t_file==0)?0:((float)hptr->files/t_file)*100.0,hptr->xfer/1024,
+               (t_xfer==0)?0:((float)hptr->xfer/t_xfer)*100.0,hptr->visit,
+               (t_visit==0)?0:((float)hptr->visit/t_visit)*100.0,
+               hptr->string,
+               hptr->string);
+         else
+#endif
          fprintf(out_fp,
             "%-8llu %6.02f%%  %8llu %6.02f%%  %8.0f %6.02f%%  "            \
             "%8llu %6.02f%%  %s\n",
