--- lib/ephy-spell-check.c.orig	2008-03-17 00:41:47.000000000 -0400
+++ lib/ephy-spell-check.c	2008-03-17 00:47:22.000000000 -0400
@@ -69,8 +69,15 @@ ephy_spell_check_init (EphySpellCheck *s
 		priv->dict = enchant_broker_request_dict (priv->broker, *locale);
 		if (priv->dict != NULL) break;
 	}
-	if (priv->dict == NULL)
-		g_warning (enchant_broker_get_error (priv->broker));
+	if (priv->dict == NULL) {
+		g_warning ("No dictionary found for current locale; trying 'en'");
+		priv->dict = enchant_broker_request_dict (priv->broker, "en");
+
+		if (priv->dict == NULL) {
+			g_warning (enchant_broker_get_error (priv->broker));
+			g_warning ("No dictionary found; expect a crash until LANG is properly set");
+		}
+	}
 }
 
 static void
