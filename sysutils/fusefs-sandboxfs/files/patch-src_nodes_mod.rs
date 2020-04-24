libc crate defines ENOTSUP as an alias for EOPNOTSUPP.  nix crate
does not re-export EOPNOTSUPP on FreeBSD but ENOTSUP is available.

--- src/nodes/mod.rs.orig	2020-04-20 18:46:46 UTC
+++ src/nodes/mod.rs
@@ -97,7 +97,7 @@ fn setattr_mode(attr: &mut fuse::FileAttr, path: Optio
     if attr.kind == fuse::FileType::Symlink {
         // TODO(jmmv): Should use NoFollowSymlink to support changing the mode of a symlink if
         // requested to do so, but this is not supported on Linux.
-        return Err(nix::Error::from_errno(Errno::EOPNOTSUPP));
+        return Err(nix::Error::from_errno(Errno::ENOTSUP));
     }
 
     let result = try_path(path, |p|
@@ -144,7 +144,7 @@ fn setattr_times(attr: &mut fuse::FileAttr, path: Opti
         if attr.kind == fuse::FileType::Symlink {
             eprintln!(
                 "utimensat not present; ignoring request to change symlink times for {:?}", path);
-            Err(nix::Error::from_errno(Errno::EOPNOTSUPP))
+            Err(nix::Error::from_errno(Errno::ENOTSUP))
         } else {
             try_path(path, |p| sys::stat::utimes(p, &atime, &mtime))
         }
