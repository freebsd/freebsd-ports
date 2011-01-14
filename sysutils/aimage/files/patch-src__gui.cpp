--- ./src/gui.cpp.orig	2008-05-24 10:00:14.000000000 -0400
+++ ./src/gui.cpp	2011-01-11 00:53:39.000000000 -0500
@@ -282,8 +282,8 @@
 	printf("Bytes written: %qd\n",im->callback_bytes_written);
 	if(acbi) printf("Current phase: %d\n",acbi->phase);
 	printf("Free space on capture drive: %qd\n",im->output_ident->freebytes());
-	printf("Elapsed Time: %s\n",im->imaging_timer.timer_text());
-	if(fraction_done>0) printf("Done in: %s\n",im->imaging_timer.eta_text(fraction_done));
+	printf("Elapsed Time: %s\n",im->imaging_timer.elapsed_text().c_str());
+	if(fraction_done>0) printf("Done in: %s\n",im->imaging_timer.eta_text(fraction_done).c_str());
 	printf("\n");
 	return;
     }
@@ -314,7 +314,7 @@
      * to use curses...
      */
 
-    mvprintw(time_row,0,"Elapsed Time: %s",im->imaging_timer.timer_text());
+    mvprintw(time_row,0,"Elapsed Time: %s",im->imaging_timer.elapsed_text().c_str());
 
     if(im->imaging){
 	attr_on(WA_BOLD,0);
@@ -356,11 +356,11 @@
 
     if(opt_use_timers){
 	mvprintw(reading_row,0,"       Time spent reading: %15s  ",
-		 im->read_timer.timer_text());
+		 im->read_timer.elapsed_text().c_str());
     }
     if(fraction_done>0){
 	mvprintw(done_in_row,0,"                  Done in:        %s ",
-		 im->imaging_timer.eta_text(fraction_done));
+		 im->imaging_timer.eta_text(fraction_done).c_str());
 	if(imagers.size()>1){
 	    printw("(this drive)");
 
@@ -373,7 +373,7 @@
 		    double total_fraction_done = tsr_ad / ts_ad;
 		    if(total_fraction_done>0 && total_fraction_done<100){
 			printw("  %s (all drives)",
-			       total_time.eta_text(total_fraction_done));
+			       total_time.eta_text(total_fraction_done).c_str());
 		    }
 		}
 	    }
@@ -406,7 +406,7 @@
     attr_off(WA_BOLD,0);
 
     if(opt_use_timers){
-	printw("  (%s)", im->write_timer.timer_text());
+	printw("  (%s)", im->write_timer.elapsed_text().c_str());
     }
 
     if(im->callback_bytes_to_write>0 && im->callback_bytes_written>0 && acbi && acbi->af){
