
$FreeBSD$

--- sip/b2b/B2bDef.hxx	2003/01/19 18:01:33	1.1
+++ sip/b2b/B2bDef.hxx	2003/01/19 18:02:05
@@ -95,7 +95,8 @@
 {
    BT_NONE=0,
    BT_USER_REQ=1,
-   BT_SESSION_TIMEOUT=5
+   BT_SESSION_TIMEOUT=5,
+   BT_SERVICE_UNAVAIL=15
 };
 
 typedef vector<Sptr<UaBase> >  UserAgentPeerList;
