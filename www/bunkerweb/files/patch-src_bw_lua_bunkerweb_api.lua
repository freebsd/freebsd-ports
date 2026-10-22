--- src/bw/lua/bunkerweb/api.lua.orig	2026-10-21 13:42:35 UTC
+++ src/bw/lua/bunkerweb/api.lua
@@ -68,7 +68,7 @@ local function get_nginx_bin()
 end
 
 local function get_nginx_bin()
-	local candidates = { "/usr/sbin/nginx", "/usr/local/sbin/nginx", "/usr/bin/nginx", "/usr/local/bin/nginx" }
+	local candidates = { "/usr/local/bin/openresty", "/usr/sbin/nginx", "/usr/local/sbin/nginx", "/usr/bin/nginx", "/usr/local/bin/nginx" }
 	for _, candidate in ipairs(candidates) do
 		if file_exists(candidate) then
 			return candidate
@@ -84,7 +84,7 @@ local function get_nginx_conf()
 			return candidate
 		end
 	end
-	return "/etc/nginx/nginx.conf"
+	return "/usr/local/etc/nginx/nginx.conf"
 end
 
 api.global = { GET = {}, POST = {}, PUT = {}, DELETE = {} }
@@ -279,7 +279,7 @@ local function check_audit_storage(variables_path)
 
 local function check_audit_storage(variables_path)
 	-- Only called with our fixed config path or the internally generated staging path.
-	local handle = io.popen("python3 /usr/share/bunkerweb/utils/modsecurity_audit.py '" .. variables_path .. "' 2>&1")
+	local handle = io.popen("python3 /usr/local/share/bunkerweb/common/utils/modsecurity_audit.py '" .. variables_path .. "' 2>&1")
 	if not handle then
 		return false, "cannot run ModSecurity audit preflight"
 	end
@@ -518,7 +518,7 @@ local function reload_checked(test_arg)
 end
 
 local function reload_checked(test_arg)
-	local valid, validation_error = check_audit_storage("/etc/nginx/variables.env")
+	local valid, validation_error = check_audit_storage("/usr/local/etc/nginx/variables.env")
 	if not valid then
 		return HTTP_INTERNAL_SERVER_ERROR, "error", validation_error
 	end
@@ -618,19 +618,19 @@ api.global.POST["^/confs$"] = function(self)
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
@@ -699,7 +699,7 @@ api.global.POST["^/confs$"] = function(self)
 		return self:response(HTTP_INTERNAL_SERVER_ERROR, "error", "cannot extract archive")
 	end
 
-	if destination == "/etc/nginx" then
+	if destination == "/usr/local/etc/nginx" then
 		local ran, valid, validation_error = pcall(check_audit_storage, staging .. "/variables.env")
 		if not ran or not valid then
 			execute("rm -rf '" .. staging .. "'")
@@ -716,7 +716,7 @@ api.global.POST["^/confs$"] = function(self)
 		return self:response(HTTP_SERVICE_UNAVAILABLE, "error", "another push swap is in progress")
 	end
 	local generating
-	if destination == "/etc/nginx" then
+	if destination == "/usr/local/etc/nginx" then
 		local status, failure
 		generating, status, failure = acquire_generating_lock()
 		if not generating then
