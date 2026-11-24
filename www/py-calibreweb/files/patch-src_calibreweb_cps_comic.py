https://github.com/janeczku/calibre-web/commit/79d35711d73491881ecd2b13ded02c277543dbcb

--- src/calibreweb/cps/comic.py.orig	2026-08-08 14:14:14 UTC
+++ src/calibreweb/cps/comic.py
@@ -17,6 +17,7 @@
 #   along with this program. If not, see <http://www.gnu.org/licenses/>.
 
 import os
+import tempfile
 
 from . import logger, isoLanguages, cover
 from .constants import BookMeta
@@ -30,6 +31,14 @@ except (ImportError, RuntimeError) as e:
 log = logger.create()
 
 try:
+    import py7zr
+    use_7zip = True
+except (ImportError, SyntaxError) as e:
+    py7zr = None
+    use_7zip = False
+    log.debug('Cannot import py7zr, extracting cover files from CB7 files will not work: %s', e)
+
+try:
     from natsort import natsorted as sort
 except ImportError:
     log.debug("Natural sorting unavailable: using standard "
@@ -49,6 +58,10 @@ try:
         comicapi.utils.add_rar_paths()
     except ImportError:
         load_archive_plugins = None
+    try:
+        from comicapi.archivers.sevenzip import SevenZipArchiver
+    except ImportError:
+        SevenZipArchiver = None
 except (ImportError, LookupError) as e:
     log.debug('Cannot import comicapi, extracting comic metadata will not work: %s', e)
     import zipfile
@@ -59,15 +72,95 @@ except (ImportError, LookupError) as e:
     except (ImportError, SyntaxError) as e:
         log.debug('Cannot import rarfile, extracting cover files from rar files will not work: %s', e)
         use_rarfile = False
-    try:
-        import py7zr
-        use_7zip = True
-    except (ImportError, SyntaxError) as e:
-        log.debug('Cannot import py7zr, extracting cover files from CB7 files will not work: %s', e)
-        use_7zip = False
     use_comic_meta = False
 
 
+if use_7zip and hasattr(py7zr, 'WriterFactory'):
+    class _SevenZipBuffer(py7zr.Py7zIO):
+        def __init__(self):
+            self.file = tempfile.SpooledTemporaryFile(max_size=8 * 1024 * 1024, mode='w+b')
+
+        def write(self, data):
+            return self.file.write(data)
+
+        def read(self, size=None):
+            return self.file.read() if size is None else self.file.read(size)
+
+        def seek(self, offset, whence=0):
+            return self.file.seek(offset, whence)
+
+        def flush(self):
+            self.file.flush()
+
+        def size(self):
+            position = self.file.tell()
+            self.file.seek(0, os.SEEK_END)
+            size = self.file.tell()
+            self.file.seek(position)
+            return size
+
+
+    class _SevenZipFactory(py7zr.WriterFactory):
+        def __init__(self):
+            self.buffer = _SevenZipBuffer()
+
+        def create(self, filename):
+            return self.buffer
+
+
+def _read_7zip_file(archive, name):
+    if name not in archive.getnames():
+        raise KeyError(name)
+    if hasattr(archive, 'read'):
+        return archive.read([name])[name].read()
+    factory = _SevenZipFactory()
+    try:
+        archive.extract(targets=[name], factory=factory)
+        factory.buffer.seek(0)
+        return factory.buffer.read()
+    finally:
+        factory.buffer.file.close()
+
+
+if use_comic_meta and use_7zip and SevenZipArchiver is not None:
+    class _SevenZipComicArchiver(SevenZipArchiver):
+        def read_file(self, archive_file):
+            try:
+                with py7zr.SevenZipFile(self.path, 'r') as archive:
+                    return _read_7zip_file(archive, archive_file)
+            except (py7zr.Bad7zFile, OSError) as ex:
+                log.error('7Zip file failed with error: %s', ex)
+                raise
+
+        def is_writable(self):
+            return False
+
+        def write_file(self, archive_file, data):
+            return False
+
+        def remove_file(self, archive_file):
+            return False
+
+        def rebuild(self, exclude_list):
+            return False
+
+        def copy_from_archive(self, other_archive):
+            return False
+
+
+def _open_comic_archive(path, rar_executable):
+    try:
+        archive = ComicArchive(path, rar_exe_path=rar_executable)
+    except TypeError:
+        if load_archive_plugins is not None:
+            load_archive_plugins(force=True, rar=rar_executable)
+        archive = ComicArchive(path)
+    if (use_7zip and SevenZipArchiver is not None
+            and isinstance(getattr(archive, 'archiver', None), SevenZipArchiver)):
+        archive.archiver = _SevenZipComicArchiver.open(archive.archiver.path, archive.archiver._exe)
+    return archive
+
+
 def _extract_cover_from_archive(original_file_extension, tmp_file_name, rar_executable):
     cover_data = extension = None
     if original_file_extension.upper() == '.CBZ':
@@ -102,27 +195,24 @@ def _extract_cover_from_archive(original
         except Exception as ex:
             log.error('Rarfile failed with error: {}'.format(ex))
     elif original_file_extension.upper() == '.CB7' and use_7zip:
-        cf = py7zr.SevenZipFile(tmp_file_name)
-        for name in sort(cf.getnames()):
-            ext = os.path.splitext(name)
-            if len(ext) > 1:
-                extension = ext[1].lower()
-                if extension in cover.COVER_EXTENSIONS:
-                    try:
-                        cover_data = cf.read([name])[name].read()
-                    except (py7zr.Bad7zFile, OSError) as ex:
-                        log.error('7Zip file failed with error: {}'.format(ex))
-                    break
+        try:
+            with py7zr.SevenZipFile(tmp_file_name) as cf:
+                for name in sort(cf.getnames()):
+                    ext = os.path.splitext(name)
+                    if len(ext) > 1:
+                        extension = ext[1].lower()
+                        if extension in cover.COVER_EXTENSIONS:
+                            cover_data = _read_7zip_file(cf, name)
+                            break
+        except (py7zr.Bad7zFile, OSError) as ex:
+            log.error('7Zip file failed with error: %s', ex)
     return cover_data, extension
 
 
 def _extract_cover(tmp_file_path, original_file_extension, rar_executable):
     cover_data = extension = None
     if use_comic_meta:
-        try:
-            archive = ComicArchive(tmp_file_path, rar_exe_path=rar_executable)
-        except TypeError:
-            archive = ComicArchive(tmp_file_path)
+        archive = _open_comic_archive(tmp_file_path, rar_executable)
         name_list = archive.getPageNameList if hasattr(archive, "getPageNameList") else archive.get_page_name_list
         for index, name in enumerate(name_list()):
             ext = os.path.splitext(name)
@@ -139,11 +229,7 @@ def _extract_cover(tmp_file_path, origin
 
 def get_comic_info(tmp_file_path, original_file_name, original_file_extension, rar_executable, no_cover_processing):
     if use_comic_meta:
-        try:
-            archive = ComicArchive(tmp_file_path, rar_exe_path=rar_executable)
-        except TypeError:
-            load_archive_plugins(force=True, rar=rar_executable)
-            archive = ComicArchive(tmp_file_path)
+        archive = _open_comic_archive(tmp_file_path, rar_executable)
         if hasattr(archive, "seemsToBeAComicArchive"):
             seems_archive = archive.seemsToBeAComicArchive
         else:
