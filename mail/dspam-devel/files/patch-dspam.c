--- src/dspam.c.dist	Sun Feb 20 22:42:47 2005
+++ src/dspam.c	Sun Feb 20 22:46:22 2005
@@ -2543,8 +2543,9 @@
           LOG (LOG_CRIT, ERROR_MEM_ALLOC);
       }
 
-      if (CTX->result == DSR_ISSPAM)
-      {
+// FreeBSD patch: put the user in all emails, extremely usefull for scripts
+//      if (CTX->result == DSR_ISSPAM)
+//      {
         snprintf(data, sizeof(data), "X-DSPAM-User: %s", CTX->username);
         head = _ds_create_header_field(data);
         if (head != NULL)
@@ -2556,7 +2557,7 @@
         }
         else
           LOG (LOG_CRIT, ERROR_MEM_ALLOC);
-      }
+//      }  // end of FreeBSD patch
 
       if (!strcmp(_ds_pref_val(PTX, "showFactors"), "on")) {
 
@@ -2594,7 +2595,7 @@
 int embed_signature(DSPAM_CTX *CTX, AGENT_CTX *ATX, agent_pref_t PTX) {
   struct nt_node *node_nt;
   struct nt_c c_nt;
-/*  char toplevel_boundary[128] = { 0 }; */
+  char toplevel_boundary[128] = { 0 };
   struct _ds_message_block *block;
   int i = 0;
 
@@ -2613,13 +2614,13 @@
   if (block->media_subtype == MST_SIGNED)
     return embed_signed(CTX, ATX, PTX);
 
-/*
+
   if (block->media_type == MT_MULTIPART && block->terminating_boundary != NULL)
   {
     strlcpy(toplevel_boundary, block->terminating_boundary,
             sizeof(toplevel_boundary));
   }
-*/
+
 
   while (node_nt != NULL)
   {
@@ -2635,16 +2636,7 @@
         && (block->media_type == MT_TEXT
             || (block->boundary == NULL && i == 0
                 && block->media_type != MT_MULTIPART))
-
-        /* The part is one of the top-level parts */ 
-        && (
-/*toplevel_boundary[0] == 0 || */
-           (block->terminating_boundary 
-/*            && 
-            !strncmp(block->terminating_boundary, toplevel_boundary,
-             strlen(toplevel_boundary))   
-*/
-           )))
+        && (toplevel_boundary[0] == 0 || block->terminating_boundary))
     {
       int is_attachment = 0;
       struct _ds_header_field *field;
