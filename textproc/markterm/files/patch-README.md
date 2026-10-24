--- README.md.orig	2026-10-18 23:13:37 UTC
+++ README.md
@@ -465,6 +465,24 @@ PORT=8080 bin/markpdf-web  # or wherever you like
 PORT=8080 bin/markpdf-web  # or wherever you like
 ```
 
+Custom fonts: by default the playground renders with fonts auto-scanned
+from the system directories (`/usr/share/fonts`, `/usr/local/share/fonts`,
+and `$HOME/.local/share/fonts`). To use faces that live elsewhere, pass
+`--fontdir <dir>` on the command line (or set `MARKPDF_WEB_FONTDIR=<dir>`);
+every `.ttf` under the directory is registered recursively and takes
+priority over the system fonts:
+
+```bash
+bin/markpdf-web --fontdir /path/to/my/ttf-fonts
+MARKPDF_WEB_FONTDIR=/path/to/my/ttf-fonts bin/markpdf-web   # equivalent
+```
+
+Fonts are matched by their internal family name in CSS. When a directory
+contains several faces with the same family name (e.g. one typeface's
+condensed and wide cuts both report `Advocate`), the closest-weight match
+wins; point `--fontdir` at a directory holding exactly the faces you want
+for deterministic results.
+
 Documents live in the visitor's browser (localStorage) and in
 shareable `#d=...` URLs. Submitted markdown is uploaded to the server,
 rendered in memory, and streamed back with the response — no PDF file
