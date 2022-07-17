--- vendor/github.com/minio/mc/pkg/disk/stat_freebsd.go.orig	2022-07-17 15:41:36 UTC
+++ vendor/github.com/minio/mc/pkg/disk/stat_freebsd.go
@@ -35,7 +35,7 @@ func GetFileSystemAttrs(file string) (string, error) {
 
 	var fileAttr strings.Builder
 	fileAttr.WriteString("atime:")
-	fileAttr.WriteString(strconv.FormatInt(st.Atimespec.Sec, 10) + "#" + strconv.FormatInt(st.Atimespec.Nsec, 10))
+	fileAttr.WriteString(strconv.FormatInt(int64(st.Atimespec.Sec), 10) + "#" + strconv.FormatInt(int64(st.Atimespec.Nsec), 10))
 	fileAttr.WriteString("/gid:")
 	fileAttr.WriteString(strconv.Itoa(int(st.Gid)))
 
@@ -48,7 +48,7 @@ func GetFileSystemAttrs(file string) (string, error) {
 	fileAttr.WriteString("/mode:")
 	fileAttr.WriteString(strconv.Itoa(int(st.Mode)))
 	fileAttr.WriteString("/mtime:")
-	fileAttr.WriteString(strconv.FormatInt(st.Mtimespec.Sec, 10) + "#" + strconv.FormatInt(st.Mtimespec.Nsec, 10))
+	fileAttr.WriteString(strconv.FormatInt(int64(st.Mtimespec.Sec), 10) + "#" + strconv.FormatInt(int64(st.Mtimespec.Nsec), 10))
 	fileAttr.WriteString("/uid:")
 	fileAttr.WriteString(strconv.Itoa(int(st.Uid)))
 
