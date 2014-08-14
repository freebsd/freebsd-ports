--- ./upgrade/upgrade_supported.go.orig	2014-08-14 02:03:33.321542734 +0000
+++ ./upgrade/upgrade_supported.go	2014-08-14 02:03:37.807542195 +0000
@@ -70,6 +70,7 @@
 
 // Returns the latest release, including prereleases or not depending on the argument
 func LatestRelease(prerelease bool) (Release, error) {
+	return Release{}, ErrVersionUnknown
 	resp, err := http.Get("https://api.github.com/repos/syncthing/syncthing/releases?per_page=10")
 	if err != nil {
 		return Release{}, err
