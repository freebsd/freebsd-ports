--- src/org/apache/xml/security/signature/XMLSignature.java.orig	2010-11-11 10:38:26.000000000 +0100
+++ src/org/apache/xml/security/signature/XMLSignature.java	2010-12-14 12:40:29.000000000 +0100
@@ -1,5 +1,5 @@
 /*
- * Copyright  1999-2009 The Apache Software Foundation.
+ * Copyright  1999-2010 The Apache Software Foundation.
  *
  *  Licensed under the Apache License, Version 2.0 (the "License");
  *  you may not use this file except in compliance with the License.
@@ -107,6 +107,12 @@
     public static final String ALGO_ID_MAC_HMAC_SHA512 = Constants.MoreAlgorithmsSpecNS + "hmac-sha512";
     /**Signature - Optional ECDSAwithSHA1 */
     public static final String ALGO_ID_SIGNATURE_ECDSA_SHA1 = "http://www.w3.org/2001/04/xmldsig-more#ecdsa-sha1";
+    /**Signature - Optional ECDSAwithSHA256 */
+    public static final String ALGO_ID_SIGNATURE_ECDSA_SHA256 = "http://www.w3.org/2001/04/xmldsig-more#ecdsa-sha256";
+    /**Signature - Optional ECDSAwithSHA384 */
+    public static final String ALGO_ID_SIGNATURE_ECDSA_SHA384 = "http://www.w3.org/2001/04/xmldsig-more#ecdsa-sha384";
+    /**Signature - Optional ECDSAwithSHA512 */
+    public static final String ALGO_ID_SIGNATURE_ECDSA_SHA512 = "http://www.w3.org/2001/04/xmldsig-more#ecdsa-sha512";
 
     /** ds:Signature.ds:SignedInfo element */
     private SignedInfo _signedInfo = null;
