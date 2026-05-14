--- src/bw/lua/bunkerweb/helpers.lua.orig	2026-05-25 18:23:18 UTC
+++ src/bw/lua/bunkerweb/helpers.lua
@@ -80,7 +80,7 @@ helpers.order_plugins = function(plugins, variables)
 
 helpers.order_plugins = function(plugins, variables)
 	-- Extract default orders
-	local file, err, nb = open("/usr/share/bunkerweb/core/order.json", "r")
+	local file, err, nb = open("/usr/local/share/bunkerweb/common/core/order.json", "r")
 	if not file then
 		return false, err .. " (nb = " .. tostring(nb) .. ")"
 	end
@@ -353,7 +353,7 @@ function helpers.load_variables(all_variables, plugins
 			end
 		end
 	end
-	local file = open("/usr/share/bunkerweb/settings.json")
+	local file = open("/usr/local/share/bunkerweb/common/settings.json")
 	if not file then
 		return false, "can't open settings.json"
 	end
