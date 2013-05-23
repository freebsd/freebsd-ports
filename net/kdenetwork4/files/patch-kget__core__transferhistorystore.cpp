------------------------------------------------------------------------
r1355676 | rkcosta | 2013-05-20 16:16:41 +0300 (Mon, 20 May 2013) | 6 lines

Fix most-vexing parse error introduced in r1345874.

By the way, why is this revision only in branches/KDE/4.10 and not in trunk?

CCMAIL: david.narvaez@computer.org


Index: kget/core/transferhistorystore.cpp
===================================================================
--- kget/core/transferhistorystore.cpp	(revision 1355675)
+++ kget/core/transferhistorystore.cpp	(revision 1355676)
@@ -554,7 +554,7 @@
 void NepomukStore::load()
 {
     Nepomuk::Query::QueryServiceClient * queryService = new Nepomuk::Query::QueryServiceClient(this);
-    Nepomuk::Query::ResourceTypeTerm historyTypeTerm(Nepomuk::Types::Class(Nepomuk::HistoryItem::resourceTypeUri()));
+    Nepomuk::Query::ResourceTypeTerm historyTypeTerm((Nepomuk::Types::Class(Nepomuk::HistoryItem::resourceTypeUri())));
     Nepomuk::Query::Query historyQuery(historyTypeTerm);
 
     connect(queryService, SIGNAL(newEntries(const QList<Nepomuk::Query::Result>&)), this, SLOT(loadResult(const QList<Nepomuk::Query::Result>&)));

------------------------------------------------------------------------
