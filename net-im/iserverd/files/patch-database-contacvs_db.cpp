--- database/contacts_db.cpp.orig	2011-01-20 14:17:48.000000000 +0100
+++ database/contacts_db.cpp	2011-01-20 14:19:28.000000000 +0100
@@ -252,9 +252,9 @@
       }
       
       *contact = (unsigned long *)malloc(sizeof(unsigned long)*number);
-      DEBUG(200, ("Trying to malloc %d bytes for %d records (result: %06X)\n",
+      DEBUG(200, ("Trying to malloc %d bytes for %d records (result: %06X)\n",
                   (sizeof(unsigned long)*number), number, 
-		  (unsigned int)*contact));
+		  *contact));
 		
       for (int i=0;i<number;i++) (*contact)[i] = atoul(PQgetvalue(res, i, 0));	
 
