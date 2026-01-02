From 0e50b31902cdb1eb242eb361c123e9e033b2af87 Mon Sep 17 00:00:00 2001
From: Daniel Garcia Moreno <daniel.garcia@suse.com>
Date: Wed, 8 Oct 2025 09:18:51 +0200
Subject: [PATCH] Ignore next/prev of documents when traversing XPath

See https://gitlab.gnome.org/GNOME/libxml2/-/issues/996
---
 xpath.c | 66 ++++++++++++++++++++++++++++++++++++++++++---------------
 1 file changed, 49 insertions(+), 17 deletions(-)

diff --git a/xpath.c b/xpath.c
index b8e197cc9..442ce02f8 100644
--- a/xpath.c
+++ b/xpath.c
@@ -6558,12 +6558,18 @@ xmlNode *
 xmlXPathNextFollowingSibling(xmlXPathParserContext *ctxt, xmlNode *cur) {
     if ((ctxt == NULL) || (ctxt->context == NULL)) return(NULL);
     if ((ctxt->context->node->type == XML_ATTRIBUTE_NODE) ||
-	(ctxt->context->node->type == XML_NAMESPACE_DECL))
-	return(NULL);
+        (ctxt->context->node->type == XML_NAMESPACE_DECL))
+        return(NULL);
+
     if (cur == (xmlNodePtr) ctxt->context->doc)
         return(NULL);
+
     if (cur == NULL)
-        return(ctxt->context->node->next);
+        cur = ctxt->context->node;
+
+    if (cur->type == XML_DOCUMENT_NODE)
+        return(NULL);
+
     return(cur->next);
 }
 
@@ -6581,17 +6587,23 @@ xmlNode *
 xmlXPathNextPrecedingSibling(xmlXPathParserContext *ctxt, xmlNode *cur) {
     if ((ctxt == NULL) || (ctxt->context == NULL)) return(NULL);
     if ((ctxt->context->node->type == XML_ATTRIBUTE_NODE) ||
-	(ctxt->context->node->type == XML_NAMESPACE_DECL))
-	return(NULL);
+        (ctxt->context->node->type == XML_NAMESPACE_DECL))
+        return(NULL);
+
     if (cur == (xmlNodePtr) ctxt->context->doc)
         return(NULL);
-    if (cur == NULL)
-        return(ctxt->context->node->prev);
-    if ((cur->prev != NULL) && (cur->prev->type == XML_DTD_NODE)) {
-	cur = cur->prev;
-	if (cur == NULL)
-	    return(ctxt->context->node->prev);
+
+    if (cur == NULL) {
+        cur = ctxt->context->node;
+    } else if ((cur->prev != NULL) && (cur->prev->type == XML_DTD_NODE)) {
+        cur = cur->prev;
+        if (cur == NULL)
+            cur = ctxt->context->node;
     }
+
+    if (cur->type == XML_DOCUMENT_NODE)
+        return(NULL);
+
     return(cur->prev);
 }
 
@@ -6626,14 +6638,27 @@ xmlXPathNextFollowing(xmlXPathParserContext *ctxt, xmlNode *cur) {
             cur = (xmlNodePtr) ns->next;
         }
     }
-    if (cur == NULL) return(NULL) ; /* ERROR */
-    if (cur->next != NULL) return(cur->next) ;
+
+    /* ERROR */
+    if (cur == NULL)
+        return(NULL);
+
+    if (cur->type == XML_DOCUMENT_NODE)
+        return(NULL);
+
+    if (cur->next != NULL)
+        return(cur->next);
+
     do {
         cur = cur->parent;
-        if (cur == NULL) break;
-        if (cur == (xmlNodePtr) ctxt->context->doc) return(NULL);
-        if (cur->next != NULL) return(cur->next);
+        if (cur == NULL)
+            break;
+        if (cur == (xmlNodePtr) ctxt->context->doc)
+            return(NULL);
+        if (cur->next != NULL && cur->type != XML_DOCUMENT_NODE)
+            return(cur->next);
     } while (cur != NULL);
+
     return(cur);
 }
 
@@ -6746,10 +6771,13 @@ xmlXPathNextPrecedingInternal(xmlXPathParserContextPtr ctxt,
         }
         ctxt->ancestor = cur->parent;
     }
-    if (cur->type == XML_NAMESPACE_DECL)
+
+    if (cur->type == XML_NAMESPACE_DECL || cur->type == XML_DOCUMENT_NODE)
         return(NULL);
+
     if ((cur->prev != NULL) && (cur->prev->type == XML_DTD_NODE))
 	cur = cur->prev;
+
     while (cur->prev == NULL) {
         cur = cur->parent;
         if (cur == NULL)
@@ -6760,6 +6788,10 @@ xmlXPathNextPrecedingInternal(xmlXPathParserContextPtr ctxt,
             return (cur);
         ctxt->ancestor = cur->parent;
     }
+
+    if (cur->type == XML_DOCUMENT_NODE)
+        return(NULL);
+
     cur = cur->prev;
     while (cur->last != NULL)
         cur = cur->last;
-- 
GitLab

