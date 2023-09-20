- patch from https://github.com/yt-dlp/yt-dlp/issues/8156

--- yt_dlp/extractor/arte.py.orig	2022-05-18 03:37:32 UTC
+++ yt_dlp/extractor/arte.py
@@ -169,7 +169,7 @@ def _real_extract(self, url):
                 )))
 
             short_label = traverse_obj(stream_version, 'shortLabel', expected_type=str, default='?')
-            if stream['protocol'].startswith('HLS'):
+            if 'HLS' in stream['protocol']:
                 fmts, subs = self._extract_m3u8_formats_and_subtitles(
                     stream['url'], video_id=video_id, ext='mp4', m3u8_id=stream_version_code, fatal=False)
                 for fmt in fmts:
