
$FreeBSD$

--- src/routers/redirect.c.orig
+++ src/routers/redirect.c
@@ -1,4 +1,4 @@
-/* $Cambridge: exim/exim-src/src/routers/redirect.c,v 1.13 2005/06/27 15:11:04 tom Exp $ */
+/* $Cambridge: exim/exim-src/src/routers/redirect.c,v 1.10 2005/04/28 13:06:32 ph10 Exp $ */
 
 /*************************************************
 *     Exim - an Internet mail transport agent    *
@@ -108,14 +108,6 @@
 #ifdef EXPERIMENTAL_SRS
   { "srs",                opt_stringptr,
       (void *)offsetof(redirect_router_options_block, srs) },
-  { "srs_alias",          opt_stringptr,
-      (void *)offsetof(redirect_router_options_block, srs_alias) },
-  { "srs_condition",      opt_stringptr,
-      (void *)offsetof(redirect_router_options_block, srs_condition) },
-  { "srs_dbinsert",       opt_stringptr,
-      (void *)offsetof(redirect_router_options_block, srs_dbinsert) },
-  { "srs_dbselect",       opt_stringptr,
-      (void *)offsetof(redirect_router_options_block, srs_dbselect) },
 #endif
   { "syntax_errors_text", opt_stringptr,
       (void *)offsetof(redirect_router_options_block, syntax_errors_text) },
@@ -154,10 +146,6 @@
   NULL,        /* owngroups */
 #ifdef EXPERIMENTAL_SRS
   NULL,        /* srs */
-  NULL,        /* srs_alias */
-  NULL,        /* srs_condition */
-  NULL,        /* srs_dbinsert */
-  NULL,        /* srs_dbselect */
 #endif
   022,         /* modemask */
   RDO_REWRITE, /* bit_options */
@@ -532,10 +520,6 @@
 addr_prop.extra_headers = NULL;
 addr_prop.remove_headers = NULL;
 
-#ifdef EXPERIMENTAL_SRS
-addr_prop.srs_sender = NULL;
-#endif
-
 /* When verifying and testing addresses, the "logwrite" command in filters
 must be bypassed. */
 
@@ -562,90 +546,28 @@
   }
 
 #ifdef EXPERIMENTAL_SRS
-  /* Perform SRS on recipient/return-path as required  */
-
-  if(ob->srs != NULL)
+  /* For reverse SRS, fill the srs_recipient expandsion variable,
+  on failure, return decline/fail as relevant */
+if(ob->srs != NULL)
   {
-    BOOL usesrs = TRUE;
-
-    if(ob->srs_condition != NULL)
-      usesrs = expand_check_condition(ob->srs_condition, "srs_condition expansion failed", NULL);
-
-    if(usesrs)
+  if (Ustrcmp(ob->srs, "reverse") == 0 || Ustrcmp(ob->srs, "reverseandforward") == 0)
     {
-      int srs_action = 0, n_srs;
-      uschar *res;
-      uschar *usedomain;
-
-      /* What are we doing? */
-      if(Ustrcmp(ob->srs, "forward") == 0)
-        srs_action = 1;
-      else if(Ustrcmp(ob->srs, "reverseandforward") == 0)
-      {
-        srs_action = 3;
-
-        if((ob->srs_dbinsert == NULL) ^ (ob->srs_dbselect == NULL))
-          return DEFER;
-      }
-      else if(Ustrcmp(ob->srs, "reverse") == 0)
-        srs_action = 2;
-
-      /* Reverse SRS */
-      if(srs_action & 2)
-      {
-        srs_orig_recipient = addr->address;
-
-        eximsrs_init();
-        if(ob->srs_dbselect)
-          eximsrs_db_set(TRUE, ob->srs_dbselect);
-/* Comment this out for now...
-//        else
-//          eximsrs_db_set(TRUE, NULL);
-*/
-
-        if((n_srs = eximsrs_reverse(&res, addr->address)) == OK)
-        {
-          srs_recipient = res;
-          DEBUG(D_any)
-            debug_printf("SRS (reverse): Recipient '%s' rewritten to '%s'\n", srs_orig_recipient, srs_recipient);
-        }
-
-        eximsrs_done();
-
-        if(n_srs != OK)
-          return n_srs;
-      }
-
-      /* Forward SRS */
-      /* No point in actually performing SRS if we are just verifying a recipient */
-      if((srs_action & 1) && !verify && (sender_address ? sender_address[0] != 0 : FALSE))
-      {
-
-        srs_orig_sender = sender_address;
-        eximsrs_init();
-        if(ob->srs_dbinsert)
-          eximsrs_db_set(FALSE, ob->srs_dbinsert);
-/* Comment this out for now...
-//        else
-//          eximsrs_db_set(FALSE, NULL);
-*/
-
-        if(ob->srs_alias != NULL ? (usedomain = expand_string(ob->srs_alias)) == NULL : 1)
-          usedomain = deliver_domain;
-
-        if((n_srs = eximsrs_forward(&res, sender_address, usedomain)) == OK)
-        {
-          addr_prop.srs_sender = res;
-          DEBUG(D_any)
-            debug_printf("SRS (forward): Sender '%s' rewritten to '%s'\n", srs_orig_sender, res);
-        }
-
-        eximsrs_done();
+    uschar *res;
+    int     ret;
+    DEBUG(D_route)
+      debug_printf("SRS: (Forward) \n");
 
-        if(n_srs != OK)
-          return n_srs;
-      }
-    }
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
 
@@ -877,6 +799,29 @@
     (addr_prop.errors_address != NULL)? addr_prop.errors_address : US"",
     (addr_prop.errors_address != NULL)? "\n" : "");
   }
+
+#ifdef EXPERIMENTAL_SRS
+  /* On successful redirection, check for SRS forwarding and adjust sender */
+if(ob->srs != NULL)
+  {
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
+    }
+  }
+#endif
 
 /* Control gets here only when the address has been completely handled. Put the
 original address onto the succeed queue so that any retry items that get
