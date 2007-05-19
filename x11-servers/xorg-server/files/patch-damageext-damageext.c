commit 8274ea6aa97b06a56b7468c3908894c0ff72b687
Author: Eric Anholt <eric@anholt.net>
Date:   Thu Feb 1 12:15:54 2007 -0800

    Set the Damage version supported in the server, instead of using damageproto.
    
    This was caught by distributions upgrading damageproto to 1.1, before the
    server they had supported it.  The server then advertised the new version
    without supporting the protocol.

diff --git a/damageext/damageext.c b/damageext/damageext.c
index ae1091e..739d20f 100755
--- damageext/damageext.c
+++ damageext/damageext.c
@@ -35,6 +35,13 @@ int		DamageClientPrivateIndex;
 RESTYPE		DamageExtType;
 RESTYPE		DamageExtWinType;
 
+/* Version of the damage extension supported by the server, as opposed to the
+ * DAMAGE_* defines from damageproto for what version the proto header
+ * supports.
+ */
+#define SERVER_DAMAGE_MAJOR	1
+#define SERVER_DAMAGE_MINOR	0
+
 #define prScreen	screenInfo.screens[0]
 
 static void
@@ -143,16 +150,16 @@ ProcDamageQueryVersion(ClientPtr client)
     rep.type = X_Reply;
     rep.length = 0;
     rep.sequenceNumber = client->sequence;
-    if (stuff->majorVersion < DAMAGE_MAJOR) {
+    if (stuff->majorVersion < SERVER_DAMAGE_MAJOR) {
 	rep.majorVersion = stuff->majorVersion;
 	rep.minorVersion = stuff->minorVersion;
     } else {
-	rep.majorVersion = DAMAGE_MAJOR;
-	if (stuff->majorVersion == DAMAGE_MAJOR && 
-	    stuff->minorVersion < DAMAGE_MINOR)
+	rep.majorVersion = SERVER_DAMAGE_MAJOR;
+	if (stuff->majorVersion == SERVER_DAMAGE_MAJOR && 
+	    stuff->minorVersion < SERVER_DAMAGE_MINOR)
 	    rep.minorVersion = stuff->minorVersion;
 	else
-	    rep.minorVersion = DAMAGE_MINOR;
+	    rep.minorVersion = SERVER_DAMAGE_MINOR;
     }
     pDamageClient->major_version = rep.majorVersion;
     pDamageClient->minor_version = rep.minorVersion;
