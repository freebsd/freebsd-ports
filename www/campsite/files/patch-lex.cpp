--- implementation/parser/parser/lex.cpp (revision 5608)
+++ implementation/parser/parser/lex.cpp (revision 5648)
@@ -238,5 +238,5 @@
 	pcoCtx->insertAttr(new CIntegerAttr("number", "Number"));
 	pcoCtx->insertAttr(new CStringAttr("name", "Name"));
-	pcoCtx->insertAttr(new CDateAttr("publish_date", "PublicationDate"));
+	pcoCtx->insertAttr(new CDateTimeAttr("publish_date", "PublicationDate"));
 	pcoCtx->insertAttr(new CAttribute("iscurrent"));
 	pcoCtx->insertAttr(new CAttribute("defined"));
@@ -247,5 +247,5 @@
 	pcoCtx->insertAttr(new CStringAttr("name", "Name"));
 	pcoCtx->insertAttr(new CIntegerAttr("number", "Number"));
-	pcoCtx->insertAttr(new CDateAttr("publish_date", "PublicationDate"));
+	pcoCtx->insertAttr(new CDateTimeAttr("publish_date", "PublicationDate"));
 	pcoCtx->insertAttr(new CIntegerAttr("publish_year", "YEAR(PublicationDate)"));
 	pcoCtx->insertAttr(new CIntegerAttr("publish_month", "MONTH(PublicationDate)"));
@@ -264,5 +264,5 @@
 	pcoCtx->insertAttr(new CStringAttr("name", "Name"));
 	pcoCtx->insertAttr(new CIntegerAttr("number", "Number"));
-	pcoCtx->insertAttr(new CDateAttr("date", "PublicationDate"));
+	pcoCtx->insertAttr(new CDateTimeAttr("date", "PublicationDate"));
 	pcoCtx->insertAttr(new CIntegerAttr("year", "YEAR(PublicationDate)"));
 	pcoCtx->insertAttr(new CIntegerAttr("mon_nr", "MONTH(PublicationDate)"));
@@ -322,5 +322,5 @@
 	pcoCtx = new CStatementContext(CMS_CT_IF);
 	pcoCtx->insertAttr(new CStringAttr("name", "Name"));
-	pcoCtx->insertAttr(new CDateAttr("upload_date", "UploadDate"));
+	pcoCtx->insertAttr(new CDateTimeAttr("upload_date", "UploadDate"));
 	pcoCtx->insertAttr(new CDateTimeAttr("publish_date", "PublishDate"));
 	pcoCtx->insertAttr(new CAttribute("has_keyword"));
@@ -338,5 +338,5 @@
 	pcoCtx->insertAttr(new CStringAttr("name", "Name"));
 	pcoCtx->insertAttr(new CIntegerAttr("number", "Number"));
-	pcoCtx->insertAttr(new CDateAttr("upload_date", "UploadDate"));
+	pcoCtx->insertAttr(new CDateTimeAttr("upload_date", "UploadDate"));
 	pcoCtx->insertAttr(new CDateTimeAttr("publish_date", "PublishDate"));
 	pcoCtx->insertAttr(new CStringAttr("keyword", "Keywords"));
@@ -363,6 +363,6 @@
 	pcoCtx->insertAttr(new CStringAttr("mon_name", "UploadDate"));
 	pcoCtx->insertAttr(new CStringAttr("wday_name", "UploadDate"));
-	pcoCtx->insertAttr(new CDateAttr("upload_date", "UploadDate"));
-	pcoCtx->insertAttr(new CDateAttr("uploaddate", "UploadDate"));
+	pcoCtx->insertAttr(new CDateTimeAttr("upload_date", "UploadDate"));
+	pcoCtx->insertAttr(new CDateTimeAttr("uploaddate", "UploadDate"));
 	pcoCtx->insertAttr(new CDateTimeAttr("publishdate", "PublishDate"));
 	pcoCtx->insertAttr(new CStringAttr("template"));
@@ -918,5 +918,5 @@
 	pcoCtx->insertAttr(new CStringAttr("ReaderEMail"));
 	pcoCtx->insertAttr(new CStringAttr("ReaderEMailObfuscated"));
-	pcoCtx->insertAttr(new CDateAttr("SubmitDate"));
+	pcoCtx->insertAttr(new CDateTimeAttr("SubmitDate"));
 	pcoCtx->insertAttr(new CStringAttr("Subject"));
 	pcoCtx->insertAttr(new CStringAttr("Content"));

