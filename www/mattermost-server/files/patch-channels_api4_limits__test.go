--- channels/api4/limits_test.go.orig	2026-05-26 04:10:36 UTC
+++ channels/api4/limits_test.go
@@ -28,8 +28,8 @@ func TestGetServerLimits(t *testing.T) {
 
 		// Should have full access to all limits data
 		require.Greater(t, serverLimits.ActiveUserCount, int64(0))
-		require.Equal(t, int64(200), serverLimits.MaxUsersLimit)
-		require.Equal(t, int64(250), serverLimits.MaxUsersHardLimit)
+		require.Equal(t, int64(2500), serverLimits.MaxUsersLimit)
+		require.Equal(t, int64(5000), serverLimits.MaxUsersHardLimit)
 		require.Equal(t, int64(0), serverLimits.PostHistoryLimit)
 		require.Equal(t, int64(0), serverLimits.LastAccessiblePostTime)
 	})
