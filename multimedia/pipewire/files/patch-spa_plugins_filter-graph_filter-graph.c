--- spa/plugins/filter-graph/filter-graph.c.orig	2025-03-14 10:07:06 UTC
+++ spa/plugins/filter-graph/filter-graph.c
@@ -34,6 +34,16 @@
 #include "audio-plugin.h"
 #include "audio-dsp-impl.h"
 
+#if !defined(strdupa)
+# define strdupa(s)								      \
+	({									      \
+		const char *__old = (s);					      \
+		size_t __len = strlen(__old) + 1;				      \
+		char *__new = (char *) alloca(__len);				      \
+		(char *) memcpy(__new, __old, __len);				      \
+	})
+#endif
+
 #undef SPA_LOG_TOPIC_DEFAULT
 #define SPA_LOG_TOPIC_DEFAULT &log_topic
 SPA_LOG_TOPIC_DEFINE_STATIC(log_topic, "spa.filter-graph");
