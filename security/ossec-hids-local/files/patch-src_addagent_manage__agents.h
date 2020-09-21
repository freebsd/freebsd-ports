--- src/addagent/manage_agents.h.orig	2020-02-14 19:46:22 UTC
+++ src/addagent/manage_agents.h
@@ -147,4 +147,4 @@ extern fpos_t fp_pos;
 #define GMF_UNKN_ERROR  ARGV0 ": Could not run GetModuleFileName which returned (%ld).\n"
 
 
-int willchroot;
+extern int willchroot;
