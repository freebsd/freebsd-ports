commit effc00474111bf5dff1297dd3c6811c1fdf6b6ca
Author: Florian Schlichting <fsfs@debian.org>
Date:   Thu Mar 23 22:14:41 2023 +0100

    use "." to concatenate strings, not "+" (fixes #288)
    
    Unsupported operand types: string + string at /usr/share/davical/inc/caldav-ACL.php:146

diff --git a/inc/caldav-ACL.php b/inc/caldav-ACL.php
index 861d4389..cb0fa213 100644
--- inc/caldav-ACL.php.orig
+++ inc/caldav-ACL.php
@@ -143,7 +143,7 @@ function process_ace( $grantor, $by_principal, $by_collection, $ace ) {
       $grantee = new DAVResource( DeconstructURL($principal_content->GetContent()) );
       $grantee_id = $grantee->getProperty('principal_id');
       if ( !$grantee->Exists() || !$grantee->IsPrincipal() )
-        $request->PreconditionFailed(403,'recognized-principal', 'Principal "' + $principal_content->GetContent() + '" not found.');
+        $request->PreconditionFailed(403,'recognized-principal', 'Principal "' . $principal_content->GetContent() . '" not found.');
       $sqlparms = array( ':to_principal' => $grantee_id);
       $where = 'WHERE to_principal=:to_principal AND ';
       if ( isset($by_principal) ) {
diff --git a/testing/tests/regression-suite/0946-ACL-err.result b/testing/tests/regression-suite/0946-ACL-err.result
new file mode 100644
index 00000000..c0ad5ef7
--- /dev/null
+++ testing/tests/regression-suite/0946-ACL-err.result
@@ -0,0 +1,11 @@
+HTTP/1.1 403 Forbidden
+Date: Dow, 01 Jan 2000 00:00:00 GMT
+DAV: 1, 2, 3, access-control, calendar-access, calendar-schedule
+DAV: extended-mkcol, bind, addressbook, calendar-auto-schedule, calendar-proxy
+Content-Length: 137
+Content-Type: text/xml; charset="utf-8"
+
+<?xml version="1.0" encoding="utf-8" ?>
+<error xmlns="DAV:">
+  <recognized-principal/>Principal "/caldav.php/user40/" not found.
+</error>
diff --git a/testing/tests/regression-suite/0946-ACL-err.test b/testing/tests/regression-suite/0946-ACL-err.test
new file mode 100644
index 00000000..945f3a13
--- /dev/null
+++ testing/tests/regression-suite/0946-ACL-err.test
@@ -0,0 +1,41 @@
+#
+# ACL setting default privileges on a collection to nothing, and
+#     specific privileges to include read-acl.
+#
+TYPE=ACL
+URL=http://regression.host/caldav.php/user1/home/
+HEADER=User-Agent: RFC3744 Spec Tests
+HEADER=Content-Type: text/xml; charset="UTF-8"
+HEAD
+
+
+BEGINDATA
+<?xml version="1.0" encoding="utf-8" ?>
+<acl xmlns="DAV:" xmlns:CalDAV="urn:ietf:params:xml:ns:caldav">
+  <ace>
+    <principal>
+      <href>/caldav.php/user40/</href>
+    </principal>
+    <grant>
+      <privilege><read/></privilege>
+      <privilege><read-acl/></privilege>
+      <privilege><read-current-user-privilege-set/></privilege>
+      <privilege><CalDAV:read-free-busy/></privilege>
+    </grant>
+  </ace>
+  <ace>
+    <principal><authenticated/></principal>
+    <grant>
+      <privilege/>
+    </grant>
+  </ace>
+</acl>
+ENDDATA
+
+QUERY
+SELECT by_principal, by_collection, privileges, p_to.displayname, to_principal
+   FROM grants JOIN dav_principal p_to ON (to_principal=principal_id)
+          LEFT JOIN collection ON (by_collection=collection.collection_id)
+  WHERE collection.dav_name = '/user1/home/'
+ENDQUERY
+
