--- agent/session/utility/utility_unix.go.orig	2019-05-15 22:56:33 UTC
+++ agent/session/utility/utility_unix.go
@@ -65,7 +65,7 @@ func (u *SessionUtil) CreateLocalAdminUser(log log.T) 
 		}
 	}
 
-	err = u.createSudoersFileIfNotPresent(log)
+	err = nil
 	return
 }
 
