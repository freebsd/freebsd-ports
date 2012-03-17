--- ./lib/cpluff/libcpluff/pinfo.c.orig	2011-12-23 04:12:21.000000000 +0100
+++ ./lib/cpluff/libcpluff/pinfo.c	2012-01-02 10:14:38.000000000 +0100
@@ -570,9 +570,11 @@
 	if (status != CP_OK) {
 		cpi_error(context, _("A plug-in listener could not be registered due to insufficient memory."));
 	} else if (cpi_is_logged(context, CP_LOG_DEBUG)) {
+#ifndef __clang__
 		char owner[64];
 		/* TRANSLATORS: %s is the context owner */
 		cpi_debugf(context, N_("%s registered a plug-in listener."), cpi_context_owner(context, owner, sizeof(owner)));
+#endif
 	}
 	cpi_unlock_context(context);
 	
@@ -592,9 +594,11 @@
 		process_unregister_plistener(context->env->plugin_listeners, node, NULL);
 	}
 	if (cpi_is_logged(context, CP_LOG_DEBUG)) {
+#ifndef __clang__
 		char owner[64];
 		/* TRANSLATORS: %s is the context owner */
 		cpi_debugf(context, N_("%s unregistered a plug-in listener."), cpi_context_owner(context, owner, sizeof(owner)));
+#endif
 	}
 	cpi_unlock_context(context);
 }
