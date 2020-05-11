# This patch fixes a bug where attempting to view branches with a / in the name
# would return an HTTP 500 Internal Server Error.  The underlying issue ended up
# being that go-git implicitly relied on read() of a dirfd to succeed, so for a
# branch named "stable/11" it would stop and assume "stable" was the ref, but it
# was really just a directory.

# This patch was accepted upstream here:
# https://github.com/go-git/go-git/pull/39
# go-gitea is expected to merge it when go-git creates a new release for them to
# import, and this patch can silently go away as soon as it conflicts.

--- vendor/github.com/go-git/go-git/v5/storage/filesystem/dotgit/dotgit.go.orig	2020-04-01 17:02:04 UTC
+++ vendor/github.com/go-git/go-git/v5/storage/filesystem/dotgit/dotgit.go
@@ -57,6 +57,9 @@ var (
 	// targeting a non-existing object. This usually means the repository
 	// is corrupt.
 	ErrSymRefTargetNotFound = errors.New("symbolic reference target not found")
+	// ErrIsDir is returned when a reference file is attempting to be read,
+	// but the path specified is a directory.
+	ErrIsDir = errors.New("reference path is a directory")
 )
 
 // Options holds configuration for the storage.
@@ -926,6 +929,14 @@ func (d *DotGit) addRefFromHEAD(refs *[]*plumbing.Refe
 
 func (d *DotGit) readReferenceFile(path, name string) (ref *plumbing.Reference, err error) {
 	path = d.fs.Join(path, d.fs.Join(strings.Split(name, "/")...))
+	st, err := d.fs.Stat(path)
+	if err != nil {
+		return nil, err
+	}
+	if st.IsDir() {
+		return nil, ErrIsDir
+	}
+
 	f, err := d.fs.Open(path)
 	if err != nil {
 		return nil, err
