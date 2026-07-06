--- channels/app/limits_test.go.orig	2026-05-26 04:10:36 UTC
+++ channels/app/limits_test.go
@@ -27,8 +27,8 @@ func TestGetServerLimits(t *testing.T) {
 
 		// InitBasic creates 3 users by default
 		require.Equal(t, int64(3), serverLimits.ActiveUserCount)
-		require.Equal(t, int64(200), serverLimits.MaxUsersLimit)
-		require.Equal(t, int64(250), serverLimits.MaxUsersHardLimit)
+		require.Equal(t, int64(2500), serverLimits.MaxUsersLimit)
+		require.Equal(t, int64(5000), serverLimits.MaxUsersHardLimit)
 	})
 
 	t.Run("user count should increase on creating new user and decrease on permanently deleting", func(t *testing.T) {
@@ -266,7 +266,7 @@ func TestIsAtUserLimit(t *testing.T) {
 			th.App.Srv().SetLicense(nil)
 
 			mockUserStore := storemocks.UserStore{}
-			mockUserStore.On("Count", mock.Anything).Return(int64(200), nil) // Under hard limit of 250
+			mockUserStore.On("Count", mock.Anything).Return(int64(4000), nil) // Under hard limit of 5000
 			mockUserStore.On("AnalyticsGetSingleChannelGuestCount").Return(int64(0), nil)
 			mockStore := th.App.Srv().Store().(*storemocks.Store)
 			mockStore.On("User").Return(&mockUserStore)
@@ -282,7 +282,7 @@ func TestIsAtUserLimit(t *testing.T) {
 			th.App.Srv().SetLicense(nil)
 
 			mockUserStore := storemocks.UserStore{}
-			mockUserStore.On("Count", mock.Anything).Return(int64(250), nil) // At hard limit of 250
+			mockUserStore.On("Count", mock.Anything).Return(int64(5000), nil) // At hard limit of 5000
 			mockUserStore.On("AnalyticsGetSingleChannelGuestCount").Return(int64(0), nil)
 			mockStore := th.App.Srv().Store().(*storemocks.Store)
 			mockStore.On("User").Return(&mockUserStore)
@@ -298,7 +298,7 @@ func TestIsAtUserLimit(t *testing.T) {
 			th.App.Srv().SetLicense(nil)
 
 			mockUserStore := storemocks.UserStore{}
-			mockUserStore.On("Count", mock.Anything).Return(int64(300), nil) // Over hard limit of 250
+			mockUserStore.On("Count", mock.Anything).Return(int64(6000), nil) // Over hard limit of 5000
 			mockUserStore.On("AnalyticsGetSingleChannelGuestCount").Return(int64(0), nil)
 			mockStore := th.App.Srv().Store().(*storemocks.Store)
 			mockStore.On("User").Return(&mockUserStore)
@@ -528,8 +528,8 @@ func TestExtraUsersBehavior(t *testing.T) {
 		require.Nil(t, appErr)
 
 		// Unlicensed servers use hard-coded limits without extra users
-		require.Equal(t, int64(200), serverLimits.MaxUsersLimit)
-		require.Equal(t, int64(250), serverLimits.MaxUsersHardLimit)
+		require.Equal(t, int64(2500), serverLimits.MaxUsersLimit)
+		require.Equal(t, int64(5000), serverLimits.MaxUsersHardLimit)
 	})
 }
 
