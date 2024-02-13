--- src/constants.c.orig	2022-08-20 20:42:41 UTC
+++ src/constants.c
@@ -316,8 +316,6 @@ int PyXmlSec_ConstantsModule_Init(PyObject* package) {
     PYXMLSEC_ADD_NS_CONSTANT(XPathNs, "XPATH");
     PYXMLSEC_ADD_NS_CONSTANT(XPath2Ns, "XPATH2");
     PYXMLSEC_ADD_NS_CONSTANT(XPointerNs, "XPOINTER");
-    PYXMLSEC_ADD_NS_CONSTANT(Soap11Ns, "SOAP11");
-    PYXMLSEC_ADD_NS_CONSTANT(Soap12Ns, "SOAP12");
     PYXMLSEC_ADD_NS_CONSTANT(NsExcC14N, "EXC_C14N");
     PYXMLSEC_ADD_NS_CONSTANT(NsExcC14NWithComments, "EXC_C14N_WITH_COMMENT");
 
