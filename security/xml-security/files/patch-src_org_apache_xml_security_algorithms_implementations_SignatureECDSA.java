--- src/org/apache/xml/security/algorithms/implementations/SignatureECDSA.java.orig	2010-11-11 10:38:28.000000000 +0100
+++ src/org/apache/xml/security/algorithms/implementations/SignatureECDSA.java	2010-12-14 12:40:29.000000000 +0100
@@ -1,5 +1,5 @@
 /*
- * Copyright  1999-2004 The Apache Software Foundation.
+ * Copyright  1999-2010 The Apache Software Foundation.
  *
  *  Licensed under the Apache License, Version 2.0 (the "License");
  *  you may not use this file except in compliance with the License.
@@ -40,6 +40,7 @@
 /**
  *
  * @author $Author: raul $
+ * @author Alex Dupre
  */
 public abstract class SignatureECDSA extends SignatureAlgorithmSpi {
 
@@ -69,34 +70,42 @@
    private static byte[] convertASN1toXMLDSIG(byte asn1Bytes[])
            throws IOException {
 
-      byte rLength = asn1Bytes[3];
+      if (asn1Bytes.length < 8 || asn1Bytes[0] != 48) {
+         throw new IOException("Invalid ASN.1 format of ECDSA signature");
+      }
+      int offset;
+      if (asn1Bytes[1] > 0) {
+         offset = 2;
+      } else if (asn1Bytes[1] == (byte) 0x81) {
+         offset = 3;
+      } else {
+         throw new IOException("Invalid ASN.1 format of ECDSA signature");
+      }
+      
+      byte rLength = asn1Bytes[offset + 1];
       int i;
 
-      for (i = rLength; (i > 0) && (asn1Bytes[(4 + rLength) - i] == 0); i--);
+      for (i = rLength; (i > 0) && (asn1Bytes[(offset + 2 + rLength) - i] == 0); i--);
 
-      byte sLength = asn1Bytes[5 + rLength];
+      byte sLength = asn1Bytes[offset + 2 + rLength + 1];
       int j;
 
       for (j = sLength;
-              (j > 0) && (asn1Bytes[(6 + rLength + sLength) - j] == 0); j--);
+              (j > 0) && (asn1Bytes[(offset + 2 + rLength + 2 + sLength) - j] == 0); j--);
 
-      int rawLen = ((i+7)/8)*8;
+      int rawLen = Math.max(i, j);
       
-      int tmp = ((j+7)/8)*8;
-      
-      if (tmp > rawLen)
-          rawLen = tmp;
-      
-      if ((asn1Bytes[0] != 48) || (asn1Bytes[1] != asn1Bytes.length - 2)
-              || (asn1Bytes[2] != 2) || rawLen < 24
-              || (asn1Bytes[4 + rLength] != 2)     ) {
+      if ((asn1Bytes[offset - 1] & 0xff) != asn1Bytes.length - offset
+              || (asn1Bytes[offset - 1] & 0xff) != 2 + rLength + 2 + sLength
+              || asn1Bytes[offset] != 2
+              || asn1Bytes[offset + 2 + rLength] != 2) {
          throw new IOException("Invalid ASN.1 format of ECDSA signature");
       } 
       byte xmldsigBytes[] = new byte[2*rawLen];
 
-      System.arraycopy(asn1Bytes, (4 + rLength) - i, xmldsigBytes, rawLen - i,
+      System.arraycopy(asn1Bytes, (offset + 2 + rLength) - i, xmldsigBytes, rawLen - i,
                           i);
-      System.arraycopy(asn1Bytes, (6 + rLength + sLength) - j, xmldsigBytes,
+      System.arraycopy(asn1Bytes, (offset + 2 + rLength + 2 + sLength) - j, xmldsigBytes,
                        2*rawLen - j, j);
 
        return xmldsigBytes;      
@@ -118,10 +127,6 @@
    private static byte[] convertXMLDSIGtoASN1(byte xmldsigBytes[])
            throws IOException {
 
-      if (xmldsigBytes.length < 48) {
-         throw new IOException("Invalid XMLDSIG format of ECDSA signature");
-      }
-
       int rawLen = xmldsigBytes.length/2;
       
       int i;
@@ -143,20 +148,34 @@
       if (xmldsigBytes[2*rawLen - k] < 0) {
          l += 1;
       }
-
-      byte asn1Bytes[] = new byte[6 + j + l];
-
+      
+      int len = 2 + j + 2 + l;
+      if (len > 255) {
+         throw new IOException("Invalid XMLDSIG format of ECDSA signature");
+      }
+      int offset;
+      byte asn1Bytes[];
+      if (len < 128) {
+         asn1Bytes = new byte[2 + 2 + j + 2 + l];
+         offset = 1;
+      } else {
+         asn1Bytes = new byte[3 + 2 + j + 2 + l];
+         asn1Bytes[1] = (byte) 0x81;
+         offset = 2;
+      }
       asn1Bytes[0] = 48;
-      asn1Bytes[1] = (byte) (4 + j + l);
-      asn1Bytes[2] = 2;
-      asn1Bytes[3] = (byte) j;
+      asn1Bytes[offset++] = (byte) len;
+      asn1Bytes[offset++] = 2;
+      asn1Bytes[offset++] = (byte) j;
 
-      System.arraycopy(xmldsigBytes, rawLen - i, asn1Bytes, (4 + j) - i, i);
+      System.arraycopy(xmldsigBytes, rawLen - i, asn1Bytes, (offset + j) - i, i);
+      
+      offset += j;
 
-      asn1Bytes[4 + j] = 2;
-      asn1Bytes[5 + j] = (byte) l;
+      asn1Bytes[offset++] = 2;
+      asn1Bytes[offset++] = (byte) l;
 
-      System.arraycopy(xmldsigBytes, 2*rawLen - k, asn1Bytes, (6 + j + l) - k, k);
+      System.arraycopy(xmldsigBytes, 2*rawLen - k, asn1Bytes, (offset + l) - k, k);
 
       return asn1Bytes;
    }
@@ -386,4 +405,73 @@
       }
    }
 
+   /**
+    * Class SignatureRSASHA256
+    *
+    * @author Alex Dupre
+    * @version $Revision$
+    */
+   public static class SignatureECDSASHA256 extends SignatureECDSA {
+
+      /**
+       * Constructor SignatureRSASHA256
+       *
+       * @throws XMLSignatureException
+       */
+      public SignatureECDSASHA256() throws XMLSignatureException {
+         super();
+      }
+
+      /** @inheritDoc */
+      public String engineGetURI() {
+         return XMLSignature.ALGO_ID_SIGNATURE_ECDSA_SHA256;
+      }
+   }
+
+   /**
+    * Class SignatureRSASHA384
+    *
+    * @author Alex Dupre
+    * @version $Revision$
+    */
+   public static class SignatureECDSASHA384 extends SignatureECDSA {
+
+      /**
+       * Constructor SignatureRSASHA384
+       *
+       * @throws XMLSignatureException
+       */
+      public SignatureECDSASHA384() throws XMLSignatureException {
+         super();
+      }
+
+      /** @inheritDoc */
+      public String engineGetURI() {
+         return XMLSignature.ALGO_ID_SIGNATURE_ECDSA_SHA384;
+      }
+   }
+
+   /**
+    * Class SignatureRSASHA512
+    *
+    * @author Alex Dupre
+    * @version $Revision$
+    */
+   public static class SignatureECDSASHA512 extends SignatureECDSA {
+
+      /**
+       * Constructor SignatureRSASHA512
+       *
+       * @throws XMLSignatureException
+       */
+      public SignatureECDSASHA512() throws XMLSignatureException {
+         super();
+      }
+
+      /** @inheritDoc */
+      public String engineGetURI() {
+         return XMLSignature.ALGO_ID_SIGNATURE_ECDSA_SHA512;
+      }
+   }
+
 }
