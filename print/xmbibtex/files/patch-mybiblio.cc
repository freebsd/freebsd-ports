--- mybiblio.cc.orig	2018-08-25 16:01:23 UTC
+++ mybiblio.cc
@@ -289,7 +289,7 @@ void MYBIBLIO::FromDummy(unsigned long index) {
   else {
     if (c[index]->doctype) {
       delete[]c[index]->doctype;
-      c[index]->doctype='\0';
+      c[index]->doctype=NULL;
     }
   }
   if (strlen(d->abstract)>0) {
@@ -302,7 +302,7 @@ void MYBIBLIO::FromDummy(unsigned long index) {
   else {
     if (c[index]->abstract) {
       delete[]c[index]->abstract;
-      c[index]->abstract='\0';
+      c[index]->abstract=NULL;
     }
   }
   if (strlen(d->address)>0) {
@@ -315,7 +315,7 @@ void MYBIBLIO::FromDummy(unsigned long index) {
   else {
     if (c[index]->address) {
       delete[]c[index]->address;
-      c[index]->address='\0';
+      c[index]->address=NULL;
     }
   }
   if (strlen(d->annote)>0) {
@@ -328,7 +328,7 @@ void MYBIBLIO::FromDummy(unsigned long index) {
   else {
     if (c[index]->annote) {
       delete[]c[index]->annote;
-      c[index]->annote='\0';
+      c[index]->annote=NULL;
     }
   }
   if (strlen(d->author)>0) {
@@ -341,7 +341,7 @@ void MYBIBLIO::FromDummy(unsigned long index) {
   else {
     if (c[index]->author) {
       delete[]c[index]->author;
-      c[index]->author='\0';
+      c[index]->author=NULL;
     }
   }
   if (strlen(d->booktitle)>0) {
@@ -354,7 +354,7 @@ void MYBIBLIO::FromDummy(unsigned long index) {
   else {
     if (c[index]->booktitle) {
       delete[]c[index]->booktitle;
-      c[index]->booktitle='\0';
+      c[index]->booktitle=NULL;
     }
   }
   if (strlen(d->chapter)>0) {
@@ -367,7 +367,7 @@ void MYBIBLIO::FromDummy(unsigned long index) {
   else {
     if (c[index]->chapter) {
       delete[]c[index]->chapter;
-      c[index]->chapter='\0';
+      c[index]->chapter=NULL;
     }
   }
   if (strlen(d->comment)>0) {
@@ -380,7 +380,7 @@ void MYBIBLIO::FromDummy(unsigned long index) {
   else {
     if (c[index]->comment) {
       delete[]c[index]->comment;
-      c[index]->comment='\0';
+      c[index]->comment=NULL;
     }
   }
   if (strlen(d->crossref)>0) {
@@ -393,7 +393,7 @@ void MYBIBLIO::FromDummy(unsigned long index) {
   else {
     if (c[index]->crossref) {
       delete[]c[index]->crossref;
-      c[index]->crossref='\0';
+      c[index]->crossref=NULL;
     }
   }
   if (strlen(d->edition)>0) {
@@ -406,7 +406,7 @@ void MYBIBLIO::FromDummy(unsigned long index) {
   else {
     if (c[index]->edition) {
       delete[]c[index]->edition;
-      c[index]->edition='\0';
+      c[index]->edition=NULL;
     }
   }
   if (strlen(d->editor)>0) {
@@ -419,7 +419,7 @@ void MYBIBLIO::FromDummy(unsigned long index) {
   else {
     if (c[index]->editor) {
       delete[]c[index]->editor;
-      c[index]->editor='\0';
+      c[index]->editor=NULL;
     }
   }
   if (strlen(d->howpublished)>0) {
@@ -432,7 +432,7 @@ void MYBIBLIO::FromDummy(unsigned long index) {
   else {
     if (c[index]->howpublished) {
       delete[]c[index]->howpublished;
-      c[index]->howpublished='\0';
+      c[index]->howpublished=NULL;
     }
   }
   if (strlen(d->institution)>0) {
@@ -445,7 +445,7 @@ void MYBIBLIO::FromDummy(unsigned long index) {
   else {
     if (c[index]->institution) {
       delete[]c[index]->institution;
-      c[index]->institution='\0';
+      c[index]->institution=NULL;
     }
   }
   if (strlen(d->journal)>0) {
@@ -458,7 +458,7 @@ void MYBIBLIO::FromDummy(unsigned long index) {
   else {
     if (c[index]->journal) {
       delete[]c[index]->journal;
-      c[index]->journal='\0';
+      c[index]->journal=NULL;
     }
   }
   if (strlen(d->key)>0) {
@@ -471,7 +471,7 @@ void MYBIBLIO::FromDummy(unsigned long index) {
   else {
     if (c[index]->key) {
       delete[]c[index]->key;
-      c[index]->key='\0';
+      c[index]->key=NULL;
     }
   }
   if (strlen(d->keyword)>0) {
@@ -484,7 +484,7 @@ void MYBIBLIO::FromDummy(unsigned long index) {
   else {
     if (c[index]->keyword) {
       delete[]c[index]->keyword;
-      c[index]->keyword='\0';
+      c[index]->keyword=NULL;
     }
   }
   if (strlen(d->month)>0) {
@@ -497,7 +497,7 @@ void MYBIBLIO::FromDummy(unsigned long index) {
   else {
     if (c[index]->month) {
       delete[]c[index]->month;
-      c[index]->month='\0';
+      c[index]->month=NULL;
     }
   }
   if (strlen(d->note)>0) {
@@ -510,7 +510,7 @@ void MYBIBLIO::FromDummy(unsigned long index) {
   else {
     if (c[index]->note) {
       delete[]c[index]->note;
-      c[index]->note='\0';
+      c[index]->note=NULL;
     }
   }
   if (strlen(d->number)>0) {
@@ -523,7 +523,7 @@ void MYBIBLIO::FromDummy(unsigned long index) {
   else {
     if (c[index]->number) {
       delete[]c[index]->number;
-      c[index]->number='\0';
+      c[index]->number=NULL;
     }
   }
   if (strlen(d->organization)>0) {
@@ -536,7 +536,7 @@ void MYBIBLIO::FromDummy(unsigned long index) {
   else {
     if (c[index]->organization) {
       delete[]c[index]->organization;
-      c[index]->organization='\0';
+      c[index]->organization=NULL;
     }
   }
   if (strlen(d->pages)>0) {
@@ -549,7 +549,7 @@ void MYBIBLIO::FromDummy(unsigned long index) {
   else {
     if (c[index]->pages) {
       delete[]c[index]->pages;
-      c[index]->pages='\0';
+      c[index]->pages=NULL;
     }
   }
   if (strlen(d->publisher)>0) {
@@ -562,7 +562,7 @@ void MYBIBLIO::FromDummy(unsigned long index) {
   else {
     if (c[index]->publisher) {
       delete[]c[index]->publisher;
-      c[index]->publisher='\0';
+      c[index]->publisher=NULL;
     }
   }
   if (strlen(d->reprint)>0) {
@@ -575,7 +575,7 @@ void MYBIBLIO::FromDummy(unsigned long index) {
   else {
     if (c[index]->reprint) {
       delete[]c[index]->reprint;
-      c[index]->reprint='\0';
+      c[index]->reprint=NULL;
     }
   }
   if (strlen(d->school)>0) {
@@ -588,7 +588,7 @@ void MYBIBLIO::FromDummy(unsigned long index) {
   else {
     if (c[index]->school) {
       delete[]c[index]->school;
-      c[index]->school='\0';
+      c[index]->school=NULL;
     }
   }
   if (strlen(d->series)>0) {
@@ -601,7 +601,7 @@ void MYBIBLIO::FromDummy(unsigned long index) {
   else {
     if (c[index]->series) {
       delete[]c[index]->series;
-      c[index]->series='\0';
+      c[index]->series=NULL;
     }
   }
   if (strlen(d->title)>0) {
@@ -614,7 +614,7 @@ void MYBIBLIO::FromDummy(unsigned long index) {
   else {
     if (c[index]->title) {
       delete[]c[index]->title;
-      c[index]->title='\0';
+      c[index]->title=NULL;
     }
   }
   if (strlen(d->type)>0) {
@@ -627,7 +627,7 @@ void MYBIBLIO::FromDummy(unsigned long index) {
   else {
     if (c[index]->type) {
       delete[]c[index]->type;
-      c[index]->type='\0';
+      c[index]->type=NULL;
     }
   }
   if (strlen(d->volume)>0) {
@@ -640,7 +640,7 @@ void MYBIBLIO::FromDummy(unsigned long index) {
   else {
     if (c[index]->volume) {
       delete[]c[index]->volume;
-      c[index]->volume='\0';
+      c[index]->volume=NULL;
     }
   }
   if (strlen(d->year)>0) {
@@ -653,7 +653,7 @@ void MYBIBLIO::FromDummy(unsigned long index) {
   else {
     if (c[index]->year) {
       delete[]c[index]->year;
-      c[index]->year='\0';
+      c[index]->year=NULL;
     }
   }
 
