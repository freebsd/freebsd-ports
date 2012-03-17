--- ./lib/cpluff/libcpluff/psymbol.c.orig	2011-12-23 04:12:21.000000000 +0100
+++ ./lib/cpluff/libcpluff/psymbol.c	2012-01-02 10:14:38.000000000 +0100
@@ -249,9 +249,11 @@
 		provider_info->usage_count++;
 
 		if (cpi_is_logged(context, CP_LOG_DEBUG)) {
+#ifndef __clang__
 			char owner[64];
 			/* TRANSLATORS: First %s is the context owner */
 			cpi_debugf(context, "%s resolved symbol %s defined by plug-in %s.", cpi_context_owner(context, owner, sizeof(owner)), name, id);
+#endif
 		}
 	} while (0);
 
@@ -315,9 +317,11 @@
 			hash_delete_free(context->resolved_symbols, node);
 			free(symbol_info);
 			if (cpi_is_logged(context, CP_LOG_DEBUG)) {
+#ifndef __clang__
 				char owner[64];
 				/* TRANSLATORS: First %s is the context owner */
 				cpi_debugf(context, _("%s released the symbol at address %p defined by plug-in %s."), cpi_context_owner(context, owner, sizeof(owner)), ptr, provider_info->plugin->plugin->identifier);
+#endif
 			}
 		}
 	
