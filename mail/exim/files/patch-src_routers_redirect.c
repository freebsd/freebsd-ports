
$FreeBSD$

--- src/routers/redirect.c.orig
+++ src/routers/redirect.c
@@ -104,12 +104,6 @@
 #ifdef EXPERIMENTAL_SRS
   { "srs",                opt_stringptr,
       (void *)offsetof(redirect_router_options_block, srs) },
-  { "srs_alias",          opt_stringptr,
-      (void *)offsetof(redirect_router_options_block, srs_alias) },
-  { "srs_condition",      opt_stringptr,
-      (void *)offsetof(redirect_router_options_block, srs_condition) },
-  { "srs_db",             opt_stringptr,
-      (void *)offsetof(redirect_router_options_block, srs_db) },
 #endif
   { "syntax_errors_text", opt_stringptr,
       (void *)offsetof(redirect_router_options_block, syntax_errors_text) },
@@ -146,9 +140,6 @@
   NULL,        /* owngroups */
 #ifdef EXPERIMENTAL_SRS
   NULL,        /* srs */
-  NULL,        /* srs_condition */
-  NULL,        /* srs_db */
-  NULL,        /* srs_alias */
 #endif
   022,         /* modemask */
   RDO_REWRITE, /* bit_options */
@@ -545,30 +536,26 @@
 #ifdef EXPERIMENTAL_SRS
   /* For reverse SRS, fill the srs_recipient expandsion variable,
   on failure, return decline/fail as relevant */
-  if(ob->srs != NULL)
+if(ob->srs != NULL)
   {
-    BOOL usesrs = TRUE;
-
-    if(ob->srs_condition != NULL)
-      usesrs = expand_check_condition(ob->srs_condition, "srs_condition expansion failed", NULL);
-
-    if(usesrs)
-      if(Ustrcmp(ob->srs, "reverse") == 0 || Ustrcmp(ob->srs, "reverseandforward") == 0)
-      {
-        uschar *res;
-        int n_srs;
+  if (Ustrcmp(ob->srs, "reverse") == 0 || Ustrcmp(ob->srs, "reverseandforward") == 0)
+    {
+    uschar *res;
+    int     ret;
+    DEBUG(D_route)
+      debug_printf("SRS: (Forward) \n");
 
-        srs_orig_recipient = addr->address;
-        eximsrs_init();
-        if(ob->srs_db)
-          eximsrs_db_set(TRUE, ob->srs_db);
-        if((n_srs = eximsrs_reverse(&res, addr->address)) != OK)
-          return n_srs;
-        srs_recipient = res;
-        eximsrs_done();
-        DEBUG(D_any)
-          debug_printf("SRS: Recipient '%s' rewritten to '%s'\n", srs_orig_recipient, srs_recipient);
-      }
+    srs_orig_recipient = addr->address;
+    eximsrs_init();
+    ret = eximsrs_reverse(&res, addr->address);
+    if (ret != OK)
+      return ret;
+    srs_recipient = res;
+    eximsrs_done();
+    DEBUG(D_route)
+      debug_printf("SRS: Recipient '%s' rewritten to '%s'\n",
+        srs_orig_recipient, srs_recipient);
+   }
   }
 #endif
 
@@ -797,33 +784,23 @@
 
 #ifdef EXPERIMENTAL_SRS
   /* On successful redirection, check for SRS forwarding and adjust sender */
-  if(ob->srs != NULL)
+if(ob->srs != NULL)
   {
-    BOOL usesrs = TRUE;
-
-    if(ob->srs_condition != NULL)
-      usesrs = expand_check_condition(ob->srs_condition, "srs_condition expansion failed", NULL);
-
-    if(usesrs)
-      if((Ustrcmp(ob->srs, "forward") == 0 || Ustrcmp(ob->srs, "reverseandforward") == 0) && !verify)
-      {
-        uschar *res;
-        uschar *usedomain;
-        int n_srs;
-
-        srs_orig_sender = sender_address;
-        eximsrs_init();
-        if(ob->srs_db)
-          eximsrs_db_set(FALSE, ob->srs_db);
-
-        if(ob->srs_alias != NULL ? (usedomain = expand_string(ob->srs_alias)) == NULL : 1)
-          usedomain = deliver_domain;
-
-        if((n_srs = eximsrs_forward(&res, sender_address, usedomain)) != OK)
-          return n_srs;
-        sender_address = res;
-        DEBUG(D_any)
-          debug_printf("SRS: Sender '%s' rewritten to '%s'\n", srs_orig_sender, sender_address);
+  if ((Ustrcmp(ob->srs, "forward") == 0 || Ustrcmp(ob->srs, "reverseandforward") == 0) && !verify )
+    {
+    uschar *res;
+    int     ret;
+    DEBUG(D_route)
+      debug_printf("SRS: (Forward) \n");
+    srs_orig_sender = sender_address;
+    eximsrs_init();
+    ret = eximsrs_forward(&res, sender_address, deliver_domain);
+    if (ret != OK)
+      return ret;
+    sender_address = res;
+    DEBUG(D_route)
+      debug_printf("SRS: Sender '%s' rewritten to '%s'\n",
+        srs_orig_sender, sender_address);
     }
   }
 #endif
