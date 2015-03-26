--- swig/python/zorba_api.i.orig	2012-10-03 22:35:16 UTC
+++ swig/python/zorba_api.i
@@ -93,7 +93,7 @@ public:
   int getIndex( const char* uri, const char* localPart ) const
   {
     if (attr == NULL)
-      return NULL;
+      return 0;
     else
       return attr->getIndex(uri, localPart);
   };
@@ -101,7 +101,7 @@ public:
   int getIndex(const char* qName ) const
   {
     if (attr == NULL)
-      return NULL;
+      return 0;
     else
       return attr->getIndex(qName);
   };
