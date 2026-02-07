--- biblio.cc.orig	2018-08-25 15:59:47 UTC
+++ biblio.cc
@@ -2178,35 +2178,35 @@ void BIBLIO::add_citation()
     c[last-1]=new CITATION;
   }
   if (!c) std::cout << "allocation failure *CITATION* ! \n";
-  else {c[last-1]->doctype='\0';
-	c[last-1]->abstract='\0';
-	c[last-1]->address='\0';
-	c[last-1]->annote='\0';
-	c[last-1]->author='\0';
-	c[last-1]->booktitle='\0';
-	c[last-1]->chapter='\0';
-	c[last-1]->comment='\0';
-	c[last-1]->crossref='\0';
-	c[last-1]->edition='\0';
-	c[last-1]->editor='\0';
-	c[last-1]->howpublished='\0';
-	c[last-1]->institution='\0';
-	c[last-1]->journal='\0';
-	c[last-1]->key='\0';
-	c[last-1]->keyword='\0';
-	c[last-1]->month='\0';
-	c[last-1]->note='\0';
-	c[last-1]->number='\0';
-	c[last-1]->organization='\0';
-	c[last-1]->pages='\0';
-	c[last-1]->publisher='\0';
-	c[last-1]->reprint='\0';
-	c[last-1]->school='\0';
-	c[last-1]->series='\0';
-	c[last-1]->title='\0';
-	c[last-1]->type='\0';
-	c[last-1]->volume='\0';
-	c[last-1]->year='\0';
+  else {c[last-1]->doctype=NULL;
+	c[last-1]->abstract=NULL;
+	c[last-1]->address=NULL;
+	c[last-1]->annote=NULL;
+	c[last-1]->author=NULL;
+	c[last-1]->booktitle=NULL;
+	c[last-1]->chapter=NULL;
+	c[last-1]->comment=NULL;
+	c[last-1]->crossref=NULL;
+	c[last-1]->edition=NULL;
+	c[last-1]->editor=NULL;
+	c[last-1]->howpublished=NULL;
+	c[last-1]->institution=NULL;
+	c[last-1]->journal=NULL;
+	c[last-1]->key=NULL;
+	c[last-1]->keyword=NULL;
+	c[last-1]->month=NULL;
+	c[last-1]->note=NULL;
+	c[last-1]->number=NULL;
+	c[last-1]->organization=NULL;
+	c[last-1]->pages=NULL;
+	c[last-1]->publisher=NULL;
+	c[last-1]->reprint=NULL;
+	c[last-1]->school=NULL;
+	c[last-1]->series=NULL;
+	c[last-1]->title=NULL;
+	c[last-1]->type=NULL;
+	c[last-1]->volume=NULL;
+	c[last-1]->year=NULL;
       }
 }
 
@@ -2252,7 +2252,7 @@ void BIBLIO::del_citation(unsigned long nc) {
       c=(CITATION **)realloc(c,last*sizeof(CITATION*));
     else {
       delete[]c;
-      c='\0';
+      c=NULL;
     }
   }
 }
