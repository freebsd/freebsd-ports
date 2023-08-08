--- perl-libxml-mm.c.orig	2022-09-21 16:57:45 UTC
+++ perl-libxml-mm.c
@@ -121,7 +121,7 @@ extern SV* PROXY_NODE_REGISTRY_MUTEX;
 extern SV* PROXY_NODE_REGISTRY_MUTEX;
 
 /* Utility method used by PmmDumpRegistry */
-void PmmRegistryDumpHashScanner(void * payload, void * data, xmlChar * name)
+void PmmRegistryDumpHashScanner(void * payload, void * data, const xmlChar * name)
 {
 	LocalProxyNodePtr lp = (LocalProxyNodePtr) payload;
 	ProxyNodePtr node = (ProxyNodePtr) lp->proxy;
@@ -215,7 +215,7 @@ static void
 /* PP: originally this was static inline void, but on AIX the compiler
    did not chew it, so I'm removing the inline */
 static void
-PmmRegistryHashDeallocator(void *payload, xmlChar *name)
+PmmRegistryHashDeallocator(void *payload, const xmlChar *name)
 {
 	Safefree((LocalProxyNodePtr) payload);
 }
@@ -279,7 +279,7 @@ void *
  * internal, used by PmmCloneProxyNodes
  */
 void *
-PmmRegistryHashCopier(void *payload, xmlChar *name)
+PmmRegistryHashCopier(void *payload, const xmlChar *name)
 {
 	ProxyNodePtr proxy = ((LocalProxyNodePtr) payload)->proxy;
 	LocalProxyNodePtr lp;
