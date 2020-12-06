--- pkg/secrets/check_rights_nix.go.orig	2020-11-17 11:00:08 UTC
+++ pkg/secrets/check_rights_nix.go
@@ -11,6 +11,7 @@ import (
 	"fmt"
 	"os/user"
 	"syscall"
+	"golang.org/x/sys/unix"
 )
 
 func checkRights(path string, allowGroupExec bool) error {
@@ -64,7 +65,7 @@ func checkGroupPermission(stat *syscall.Stat_t, usr *u
 	}
 
 	// If *group* executable, user can RWX, group can RX, and nothing else for anyone.
-	if stat.Mode&(syscall.S_IRWXO|syscall.S_IWGRP) != 0 {
+	if stat.Mode&(syscall.S_IRWXO|unix.S_IWGRP) != 0 {
 		return fmt.Errorf("invalid executable '%s', 'others' have rights on it or 'group' has write permissions on it", path)
 	}
 
@@ -82,7 +83,7 @@ func checkGroupPermission(stat *syscall.Stat_t, usr *u
 		}
 
 		// Check that *group* can at least exec.
-		if stat.Mode&(syscall.S_IXGRP) == 0 {
+		if stat.Mode&(unix.S_IXGRP) == 0 {
 			return fmt.Errorf("invalid executable: '%s' is not executable by group", path)
 		}
 	}
