--- lasso/xml/saml-2.0/samlp2_logout_request.c.orig	2024-11-08 07:04:30 UTC
+++ lasso/xml/saml-2.0/samlp2_logout_request.c
@@ -128,14 +128,10 @@ get_xmlNode(LassoNode *node, gboolean lasso_dump)
 	lasso_foreach(it, other_session_index) {
 		xmlNode *child = xmlSecAddChild(xmlnode, BAD_CAST SESSION_INDEX,
 				BAD_CAST LASSO_SAML2_PROTOCOL_HREF);
-#if (XMLSEC_MAJOR > 1) || (XMLSEC_MAJOR == 1 && XMLSEC_MINOR > 2) || (XMLSEC_MAJOR == 1 && XMLSEC_MINOR == 2 && XMLSEC_SUBMINOR > 12)
-		xmlSecNodeEncodeAndSetContent(child, BAD_CAST it->data);
-#else
 		xmlChar *content;
 		content = xmlEncodeSpecialChars(child->doc, BAD_CAST it->data);
 		xmlNodeSetContent(child, content);
 		xmlFree(content);
-#endif
 	}
 	((LassoSamlp2LogoutRequest*)node)->SessionIndex = keep_session_index;
 	lasso_release_list_of_strings(other_session_index);
