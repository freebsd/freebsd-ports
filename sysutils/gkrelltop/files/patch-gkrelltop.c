--- gkrelltop.c.orig
+++ gkrelltop.c
@@ -354,6 +354,7 @@
             if(pluginMode == cpu)
                 snprintf(tmp,sizeof(tmp), "%d: %4.1f%c  %6.2d  %.30s%c", 
                     i+1, best[i]->amount, '%', best[i]->pid, best[i]->name, ch);
+#if defined(LINUX)
             else if(pluginMode == mem)
                 snprintf(tmp,sizeof(tmp), "%d: %4.1f%c %6.2dMB %6.2d  %.30s%c", 
                     i+1, best[i]->amount, '%', best[i]->rss/MEG,
@@ -365,6 +366,7 @@
                     (float)(best[i]->io_read - best[i]->previous_io_read)/KIL,
                     (float)(best[i]->io_write - best[i]->previous_io_write)/KIL,
                     best[i]->pid, best[i]->name, ch);
+#endif
 
             strncat(g_tooltip_text,tmp,sizeof(g_tooltip_text)-strlen(g_tooltip_text));
         }
