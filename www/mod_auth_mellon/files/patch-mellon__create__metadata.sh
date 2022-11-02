--- mellon_create_metadata.sh.orig	2022-11-02 11:48:53 UTC
+++ mellon_create_metadata.sh
@@ -75,6 +75,13 @@ CERT="$(grep -v '^-----' "$OUTFILE.cert")"
 cat >"$OUTFILE.xml" <<EOF
 <EntityDescriptor entityID="$ENTITYID" xmlns="urn:oasis:names:tc:SAML:2.0:metadata" xmlns:ds="http://www.w3.org/2000/09/xmldsig#">
   <SPSSODescriptor protocolSupportEnumeration="urn:oasis:names:tc:SAML:2.0:protocol" AuthnRequestsSigned="true">
+    <KeyDescriptor use="encryption">
+      <ds:KeyInfo xmlns:ds="http://www.w3.org/2000/09/xmldsig#">
+        <ds:X509Data>
+          <ds:X509Certificate>$CERT</ds:X509Certificate>
+        </ds:X509Data>
+      </ds:KeyInfo>
+    </KeyDescriptor>
     <KeyDescriptor use="signing">
       <ds:KeyInfo xmlns:ds="http://www.w3.org/2000/09/xmldsig#">
         <ds:X509Data>
