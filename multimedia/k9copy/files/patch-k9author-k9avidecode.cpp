--- k9author/k9avidecode.cpp.orig	2012-05-04 03:23:44.723888015 +0600
+++ k9author/k9avidecode.cpp	2012-05-04 03:24:56.101895834 +0600
@@ -263,3 +263,11 @@
 QString k9AviDecode::getError() const {
     return m_error;
 }
+
+
+void av_free_packet(AVPacket *pkt) {
+	if (pkt) {
+		if (pkt->destruct) pkt->destruct(pkt);
+			pkt->data = NULL; pkt->size = 0;
+	}
+}
