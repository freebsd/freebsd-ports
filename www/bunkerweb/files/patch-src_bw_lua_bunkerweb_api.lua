--- src/bw/lua/bunkerweb/api.lua.orig	2026-09-21 08:05:39 UTC
+++ src/bw/lua/bunkerweb/api.lua
@@ -65,7 +65,7 @@
 end
 
 local function get_nginx_bin()
-	local candidates = { "/usr/sbin/nginx", "/usr/local/sbin/nginx", "/usr/bin/nginx", "/usr/local/bin/nginx" }
+	local candidates = { "/usr/local/bin/openresty", "/usr/sbin/nginx", "/usr/local/sbin/nginx", "/usr/bin/nginx", "/usr/local/bin/nginx" }
 	for _, candidate in ipairs(candidates) do
 		if file_exists(candidate) then
 			return candidate
@@ -81,7 +81,7 @@
 			return candidate
 		end
 	end
-	return "/etc/nginx/nginx.conf"
+	return "/usr/local/etc/nginx/nginx.conf"
 end
 
 api.global = { GET = {}, POST = {}, PUT = {}, DELETE = {} }
@@ -249,7 +249,7 @@
 
 local function check_audit_storage(variables_path)
 	-- Only called with our fixed config path or the internally generated staging path.
-	local handle = io.popen("python3 /usr/share/bunkerweb/utils/modsecurity_audit.py '" .. variables_path .. "' 2>&1")
+	local handle = io.popen("python3 /usr/local/share/bunkerweb/common/utils/modsecurity_audit.py '" .. variables_path .. "' 2>&1")
 	if not handle then
 		return false, "cannot run ModSecurity audit preflight"
 	end
@@ -261,7 +261,7 @@
 -- The body returns the response triple instead of sending it, so the wrapper has one
 -- place to release the swap lock whichever way the reload ends.
 local function reload_locked(test_arg)
-	local valid, validation_error = check_audit_storage("/etc/nginx/variables.env")
+	local valid, validation_error = check_audit_storage("/usr/local/etc/nginx/variables.env")
 	if not valid then
 		return HTTP_INTERNAL_SERVER_ERROR, "error", validation_error
 	end
@@ -351,19 +351,19 @@
 	-- second scheduler or the UI reaches the same instance on its own.
 	local request_id = tostring(ngx.worker.pid()) .. "." .. tostring(ngx.var.connection)
 	local tmp = "/var/tmp/bunkerweb/api_" .. self.ctx.bw.uri:sub(2) .. "." .. request_id .. ".tar.gz"
-	local destination = "/usr/share/bunkerweb/" .. self.ctx.bw.uri:sub(2)
+	local destination = "/usr/local/share/bunkerweb/" .. self.ctx.bw.uri:sub(2)
 	if self.ctx.bw.uri == "/confs" then
-		destination = "/etc/nginx"
+		destination = "/usr/local/etc/nginx"
 	elseif self.ctx.bw.uri == "/data" then
 		destination = "/data"
 	elseif self.ctx.bw.uri == "/cache" then
 		destination = "/var/cache/bunkerweb"
 	elseif self.ctx.bw.uri == "/custom_configs" then
-		destination = "/etc/bunkerweb/configs"
+		destination = "/usr/local/etc/bunkerweb/configs"
 	elseif self.ctx.bw.uri == "/plugins" then
-		destination = "/etc/bunkerweb/plugins"
+		destination = "/usr/local/etc/bunkerweb/plugins"
 	elseif self.ctx.bw.uri == "/pro_plugins" then
-		destination = "/etc/bunkerweb/pro/plugins"
+		destination = "/usr/local/etc/bunkerweb/pro/plugins"
 	end
 	local form, err = upload:new(4096)
 	if not form then
@@ -431,7 +431,7 @@
 		return self:response(HTTP_INTERNAL_SERVER_ERROR, "error", "cannot extract archive")
 	end
 
-	if destination == "/etc/nginx" then
+	if destination == "/usr/local/etc/nginx" then
 		local ran, valid, validation_error = pcall(check_audit_storage, staging .. "/variables.env")
 		if not ran or not valid then
 			execute("rm -rf '" .. staging .. "'")
