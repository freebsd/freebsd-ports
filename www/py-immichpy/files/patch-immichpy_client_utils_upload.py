-- st_birthtime exists here, so the statx(2) branch is dead code on
-- FreeBSD. Import it where it is used so the module loads without
-- pystatx, which is Linux only.
--
-- TODO: drop once upstream moves the import into the branch.

--- immichpy/client/utils/upload.py.orig	2026-11-06 15:09:38 UTC
+++ immichpy/client/utils/upload.py
@@ -24,7 +24,6 @@ from rich.progress import (
     TimeRemainingColumn,
     TransferSpeedColumn,
 )
-from statx import statx
 
 from immichpy.client.generated.api.albums_api import AlbumsApi
 from immichpy.client.generated.api.assets_api import AssetsApi
@@ -245,6 +244,8 @@ def get_file_times(
         if sys.platform == "win32":
             ctime = stats.st_ctime
         else:
+            from statx import statx
+
             ctime = statx(os.fspath(path)).btime
 
     return datetime.fromtimestamp(ctime or mtime, tz=UTC), datetime.fromtimestamp(
