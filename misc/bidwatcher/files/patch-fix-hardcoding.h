--- /dev/null	Fri Mar 15 14:13:05 2002
+++ fix-hardcoding.h	Fri Mar 15 14:14:08 2002
@@ -0,0 +1,19 @@
+#ifndef _FIX_HARDCODING_H_
+#define _FIX_HARDCODING_H_
+
+#ifdef NEW_CGI_PATH
+#define PATH_CGI_eBayISAPI	"/ws/eBayISAPI.dll?"
+#else
+#define PATH_CGI_eBayISAPI	"/aw-cgi/eBayISAPI.dll?"
+#endif
+#define PATH_CGI_TimeShow	PATH_CGI_eBayISAPI "TimeShow"
+#define PATH_CGI_ViewItem	PATH_CGI_eBayISAPI "ViewItem&item="
+#define PATH_CGI_MakeBid	PATH_CGI_eBayISAPI "MakeBid&item="
+#define PATH_CGI_AcceptBid	PATH_CGI_eBayISAPI "AcceptBid&item="
+#define PATH_CGI_ViewBidItems	PATH_CGI_eBayISAPI "MfcISAPICommand=ViewBidItems&userid="
+#define PATH_CGI_ViewListedItems PATH_CGI_eBayISAPI "ViewListedItems&userid="
+#define PATH_CGI_ReturnUserEmail PATH_CGI_eBayISAPI "ReturnUserEmail"
+
+#define DOT_BIDWATCHER		"/.bidwatcher"
+
+#endif /* _FIX_HARDCODING_H_ */
