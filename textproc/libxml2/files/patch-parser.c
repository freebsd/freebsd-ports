From 72a46a519ce7326d9a00f0b6a7f2a8e958cd1675 Mon Sep 17 00:00:00 2001
From: Daniel Veillard <veillard@redhat.com>
Date: Thu, 23 Oct 2014 11:35:36 +0800
Subject: Fix missing entities after CVE-2014-3660 fix

For https://bugzilla.gnome.org/show_bug.cgi?id=738805

The fix for CVE-2014-3660 introduced a regression in some case
where entity substitution is required and the entity is used
first in anotther entity referenced from an attribute value

---

From 0e6659ec960734b0b01aad196d4bdb4a3800b493 Mon Sep 17 00:00:00 2001
From: Lubomir Rintel <lkundrak@v3.sk>
Date: Thu, 16 Oct 2014 19:10:59 +0200
Subject: [PATCH] Revert "Missing initialization for the catalog module"

It's not correct to always load the default catalog.
https://bugzilla.redhat.com/show_bug.cgi?id=1153753

This reverts commit 054c716ea1bf001544127a4ab4f4346d1b9947e7.

--- parser.c.orig	2014-10-29 14:28:43.755327730 +0100
+++ parser.c	2014-10-29 14:28:55.287325756 +0100
@@ -7235,7 +7235,8 @@
      * far more secure as the parser will only process data coming from
      * the document entity by default.
      */
-    if ((ent->checked == 0) &&
+    if (((ent->checked == 0) ||
+         ((ent->children == NULL) && (ctxt->options & XML_PARSE_NOENT))) &&
         ((ent->etype != XML_EXTERNAL_GENERAL_PARSED_ENTITY) ||
          (ctxt->options & (XML_PARSE_NOENT | XML_PARSE_DTDVALID)))) {
 	unsigned long oldnbent = ctxt->nbentities;
@@ -14830,9 +14831,6 @@
 #ifdef LIBXML_XPATH_ENABLED
 	xmlXPathInit();
 #endif
-#ifdef LIBXML_CATALOG_ENABLED
-        xmlInitializeCatalog();
-#endif
 	xmlParserInitialized = 1;
 #ifdef LIBXML_THREAD_ENABLED
     }
