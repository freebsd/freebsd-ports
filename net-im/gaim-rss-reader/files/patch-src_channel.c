--- src/channel.c.orig	Sun Aug  8 17:45:25 2004
+++ src/channel.c	Sun Aug  8 17:46:01 2004
@@ -97,16 +97,19 @@
 
 void rss_channel_update(Channel *channel)
 {
+    xmlDocPtr doc;
+    xmlNodePtr cur;
+    gboolean rdf = FALSE;
     rss_channel_clear(channel);
 
-    xmlDocPtr doc = xmlParseFile(channel->url);
+    doc = xmlParseFile(channel->url);
     if(doc == NULL)
     {
 	//std::cerr << "Cannot read file: " << _title << std::endl;
 	return;
     }
 
-    xmlNodePtr cur = xmlDocGetRootElement(doc);
+    cur = xmlDocGetRootElement(doc);
     if (cur == NULL)
     {
 	//std::cerr << "Empty document: " << _title << std::endl;
@@ -114,7 +117,6 @@
 	return;
     }
 
-    gboolean rdf = FALSE;
     // We must determine whether the document is RDF or RSS since they
     // have slightly different structures. We handle both.
     if(!xmlStrcmp(cur->name, (const xmlChar *)"rss"))
