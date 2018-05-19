--- vendor/github.com/karrick/godirwalk/readdir.go.orig	2018-04-30 10:37:07 UTC
+++ vendor/github.com/karrick/godirwalk/readdir.go
@@ -2,6 +2,9 @@ package godirwalk
 
 import (
 	"os"
+	"path/filepath"
+
+	"github.com/pkg/errors"
 )
 
 // Dirent stores the name and file system mode type of discovered file system
@@ -11,6 +14,22 @@ type Dirent struct {
 	modeType os.FileMode
 }
 
+// NewDirent returns a newly initialized Dirent structure, or an error. This
+// function does not follow symbolic links.
+//
+// This function is rarely used, as Dirent structures are provided by other
+// functions in this library that read and walk directories.
+func NewDirent(osPathname string) (*Dirent, error) {
+	fi, err := os.Lstat(osPathname)
+	if err != nil {
+		return nil, errors.Wrap(err, "cannot lstat")
+	}
+	return &Dirent{
+		name:     filepath.Base(osPathname),
+		modeType: fi.Mode() & os.ModeType,
+	}, nil
+}
+
 // Name returns the basename of the file system entry.
 func (de Dirent) Name() string { return de.name }
 
@@ -28,6 +47,10 @@ func (de Dirent) ModeType() os.FileMode { return de.mo
 // may be set for a node. For instance, on Windows, a symbolic link that points
 // to a directory will have both the directory and the symbolic link bits set.
 func (de Dirent) IsDir() bool { return de.modeType&os.ModeDir != 0 }
+
+// IsRegular returns true if and only if the Dirent represents a regular
+// file. That is, it ensures that no mode type bits are set.
+func (de Dirent) IsRegular() bool { return de.modeType&os.ModeType == 0 }
 
 // IsSymlink returns true if and only if the Dirent represents a file system
 // symbolic link. Note that on some operating systems, more than one file mode
