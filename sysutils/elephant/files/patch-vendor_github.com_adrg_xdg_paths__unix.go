--- vendor/github.com/adrg/xdg/paths_unix.go.orig	2025-10-15 14:39:48 UTC
+++ vendor/github.com/adrg/xdg/paths_unix.go
@@ -21,7 +21,7 @@ func initBaseDirs(home string) {
 	baseDirs.dataHome = pathutil.EnvPath(envDataHome, filepath.Join(home, ".local", "share"))
 	baseDirs.data = pathutil.EnvPathList(envDataDirs, "/usr/local/share", "/usr/share")
 	baseDirs.configHome = pathutil.EnvPath(envConfigHome, filepath.Join(home, ".config"))
-	baseDirs.config = pathutil.EnvPathList(envConfigDirs, "/etc/xdg")
+	baseDirs.config = pathutil.EnvPathList(envConfigDirs, "%%LOCALBASE%%/etc/xdg", "/etc/xdg")
 	baseDirs.stateHome = pathutil.EnvPath(envStateHome, filepath.Join(home, ".local", "state"))
 	baseDirs.cacheHome = pathutil.EnvPath(envCacheHome, filepath.Join(home, ".cache"))
 	baseDirs.runtime = pathutil.EnvPath(envRuntimeDir, filepath.Join("/run/user", strconv.Itoa(os.Getuid())))
