--- src/LogParser.cpp.orig	2006-02-17 15:40:13 UTC
+++ src/LogParser.cpp
@@ -240,8 +240,8 @@ bool cLogParser::FeedEntry(const struct pfloghdr* pfHe
 		return false;
 
 
-	if (pfHeader->ifname)
-		entry.SetIfName(pfHeader->ifname);
+	/* if (pfHeader->ifname) */
+	entry.SetIfName(pfHeader->ifname);
 
 	entry.SetRuleNumber(ntohl(pfHeader->rulenr));
 	entry.SetAction(pfHeader->action);
