--- ./lib/cpluff/libcpluff/logging.c.orig	2011-12-23 04:12:21.000000000 +0100
+++ ./lib/cpluff/libcpluff/logging.c	2012-01-02 10:14:38.000000000 +0100
@@ -130,9 +130,11 @@
 	if (status == CP_ERR_RESOURCE) {
 		cpi_error(context, N_("Logger could not be registered due to insufficient memory."));		
 	} else if (cpi_is_logged(context, CP_LOG_DEBUG)) {
+#ifndef __clang__
 		char owner[64];
 		/* TRANSLATORS: %s is the context owner */
 		cpi_debugf(context, N_("%s registered a logger."), cpi_context_owner(context, owner, sizeof(owner)));
+#endif
 	}
 	cpi_unlock_context(context);
 
@@ -167,9 +169,11 @@
 		update_logging_limits(context);
 	}
 	if (cpi_is_logged(context, CP_LOG_DEBUG)) {
+#ifndef __clang__
 		char owner[64];
 		/* TRANSLATORS: %s is the context owner */
 		cpi_debugf(context, N_("%s unregistered a logger."), cpi_context_owner(context, owner, sizeof(owner)));
+#endif
 	}
 	cpi_unlock_context(context);
 }
