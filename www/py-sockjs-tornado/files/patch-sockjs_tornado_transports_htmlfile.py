Description: Fix XSS in the htmlfile transport: reject a "c" callback
  parameter that contains anything other than [A-Za-z0-9._-] with a 500
  instead of embedding it in the script block of the response, as the
  SockJS protocol requires.  Backport of the unreleased upstream fix,
  with the misindented first line of the new block corrected (upstream
  master fails to import with an IndentationError; upstream PR #124).
  Also make the existing regex a raw string, which silences a
  SyntaxWarning for "\W" on Python 3.12+.
Issue ID: https://github.com/mrjoes/sockjs-tornado/pull/124
Changeset: https://github.com/mrjoes/sockjs-tornado/commit/59f99e02ee210764f0cdefc93d11e6060aa937d1
TODO: Drop when a release includes the fix and PR #124.

--- sockjs/tornado/transports/htmlfile.py.orig	2020-04-24 14:07:26 UTC
+++ sockjs/tornado/transports/htmlfile.py
@@ -19,7 +19,8 @@ except:
     from cgi import escape


-RE = re.compile('[\W_]+')
+RE = re.compile(r'[\W_]+')
+CALLBACK_RE = re.compile('[^a-zA-Z0-9-_.]')


 # HTMLFILE template
@@ -62,6 +63,12 @@ class HtmlFileTransport(streamingbase.St
             self.set_status(500)
             self.finish()
             return
+
+        if CALLBACK_RE.search(callback):
+            self.write('invalid "callback" parameter')
+            self.set_status(500)
+            self.finish()
+            return

         # TODO: Fix me - use parameter
         self.write(HTMLFILE_HEAD % escape(RE.sub('', callback)))
