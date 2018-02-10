--- src/display.cpp.orig	2018-02-10 07:49:09 UTC
+++ src/display.cpp
@@ -311,7 +311,7 @@ void display::display_realtime_stats(con
 
 	ss << mb_read << "MB of " << fdht->stat_megs() << "MB done, ";
 	char msg[64];
-	snprintf(msg,sizeof(msg),"%02"PRIu64":%02"PRIu64":%02"PRIu64" left", hour, min, seconds);
+	snprintf(msg,sizeof(msg),"%02" PRIu64":%02" PRIu64":%02" PRIu64" left", hour, min, seconds);
 	ss << msg;
     }
     ss << "\r";
@@ -424,14 +424,14 @@ void display::display_audit_results()
   
     if (opt_verbose)    {
 	if(opt_verbose >= MORE_VERBOSE){
-	    status("   Input files examined: %"PRIu64, this->match.total);
-	    status("  Known files expecting: %"PRIu64, this->match.expect);
+	    status("   Input files examined: %" PRIu64, this->match.total);
+	    status("  Known files expecting: %" PRIu64, this->match.expect);
 	}
-	status("          Files matched: %"PRIu64, this->match.exact);
-	status("Files partially matched: %"PRIu64, this->match.partial);
-	status("            Files moved: %"PRIu64, this->match.moved);
-	status("        New files found: %"PRIu64, this->match.unknown);
-	status("  Known files not found: %"PRIu64, this->match.unused);
+	status("          Files matched: %" PRIu64, this->match.exact);
+	status("Files partially matched: %" PRIu64, this->match.partial);
+	status("            Files moved: %" PRIu64, this->match.moved);
+	status("        New files found: %" PRIu64, this->match.unknown);
+	status("  Known files not found: %" PRIu64, this->match.unused);
     }
 }
 
