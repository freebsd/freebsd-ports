--- ./deluge/core/torrentmanager.py.orig	2012-04-10 05:53:16.000000000 +0400
+++ ./deluge/core/torrentmanager.py	2013-02-02 13:11:53.000000000 +0400
@@ -419,9 +419,16 @@
             # before adding to the session.
             if options["mapped_files"]:
                 for index, filename in options["mapped_files"].items():
+                    try:
+                        fname = unicode(fname, "utf-8")
+                    except TypeError:
+                        pass
                     filename = deluge.core.torrent.sanitize_filepath(filename)
                     log.debug("renaming file index %s to %s", index, filename)
-                    torrent_info.rename_file(index, utf8_encoded(filename))
+                    try:
+                        torrent_info.rename_file(index, fname)
+                    except TypeError:
+                        torrent_info.rename_file(index, fname.encode("utf-8"))
 
             add_torrent_params["ti"] = torrent_info
             add_torrent_params["resume_data"] = ""
