--- internal/upgrade/upgrade_supported.go.orig	2014-09-28 21:24:06.335428814 +0000
+++ internal/upgrade/upgrade_supported.go	2014-09-28 21:24:59.699424791 +0000
@@ -70,6 +70,7 @@
 
 // Returns the latest release, including prereleases or not depending on the argument
 func LatestRelease(prerelease bool) (Release, error) {
+	return Release{}, ErrVersionUnknown
 	resp, err := http.Get("https://api.github.com/repos/syncthing/syncthing/releases?per_page=10")
 	if err != nil {
 		return Release{}, err
