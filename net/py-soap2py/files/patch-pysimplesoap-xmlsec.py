--- pysimplesoap/xmlsec.py.orig	2014-09-17 02:33:34 UTC
+++ pysimplesoap/xmlsec.py
@@ -203,15 +203,15 @@ def x509_verify(cacert, cert, binary=Fal
 if __name__ == "__main__":
     # basic test of enveloping signature (the reference is a part of the xml)
     sample_xml = """<Object xmlns="http://www.w3.org/2000/09/xmldsig#" Id="object">data</Object>"""
-    print canonicalize(sample_xml)
+    print(canonicalize(sample_xml))
     vars = rsa_sign(sample_xml, '#object', "no_encriptada.key", "password")
-    print SIGNED_TMPL % vars
+    print(SIGNED_TMPL % vars)
 
     # basic test of enveloped signature (the reference is the document itself)
     sample_xml = """<?xml version="1.0" encoding="UTF-8"?><Object>data%s</Object>"""
     vars = rsa_sign(sample_xml % "", '', "no_encriptada.key", "password",
                     sign_template=SIGN_ENV_TMPL, c14n_exc=False)
-    print sample_xml % (SIGNATURE_TMPL % vars)
+    print(sample_xml % (SIGNATURE_TMPL % vars))
 
     # basic signature verification:
     public_key = x509_extract_rsa_public_key(open("zunimercado.crt").read())
