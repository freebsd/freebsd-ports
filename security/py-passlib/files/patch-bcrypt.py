--- passlib/handlers/bcrypt.orig	2025-10-06 16:28:59.171474455 -0400
+++ passlib/handlers/bcrypt.py	2025-10-08 10:38:00.682318159 -0400
@@ -374,14 +374,26 @@
             NOTE: if in future we need to deliberately create hashes which have this bug,
                   can use something like 'hashpw(repeat_string(secret[:((1+secret) % 256) or 1]), 72)'
             """
-            # check if it exhibits wraparound bug
+
+            # Secret which will trip the wraparound bug, if present
             secret = (b"0123456789"*26)[:255]
-            bug_hash = ident.encode("ascii") + b"04$R1lJ2gkNaoPGdafE.H.16.nVyh2niHsGJhayOHLMiXlI45o8/DU.6"
-            if verify(secret, bug_hash):
-                return True
 
-            # if it doesn't have wraparound bug, make sure it *does* handle things
-            # correctly -- or we're in some weird third case.
+            # Python bcrypt >= 5.0.0 will raise an exception on passwords great than 72 characters,
+            # whereas earlier versions without the wraparound bug silently truncated the input to 72
+            # characters. See if the exception is generated.
+
+            try:
+                bug_hash = ident.encode("ascii") + b"04$R1lJ2gkNaoPGdafE.H.16.nVyh2niHsGJhayOHLMiXlI45o8/DU.6"
+
+                # If we get here, the backend auto-truncates, test for wraparound bug
+                if verify(secret, bug_hash):
+                    return True
+            except ValueError:
+                # Backend explicitly will not auto-truncate, truncate the password to 72 characters
+                secret = secret[:72]
+
+            # Check to make sure that the backend still hashes correctly; if not, we're in a failure case
+            # not related to the original wraparound bug or bcrypt >= 5.0.0 input length restriction.
             correct_hash = ident.encode("ascii") + b"04$R1lJ2gkNaoPGdafE.H.16.1MKHPvmKwryeulRe225LKProWYwt9Oi"
             if not verify(secret, correct_hash):
                 raise RuntimeError("%s backend failed to verify %s wraparound hash" % (backend, ident))
@@ -617,10 +629,16 @@
         except ImportError: # pragma: no cover
             return False
         try:
-            version = _bcrypt.__about__.__version__
+            # "New style" (793bef 2023-11-23) version
+            version = _bcrypt.__version__
         except:
-            log.warning("(trapped) error reading bcrypt version", exc_info=True)
-            version = '<unknown>'
+            try:
+                # Old style verion
+                version = _bcrypt.__about__.__version__
+            except:
+                # Can't find version
+                log.warning("(trapped) error reading bcrypt version", exc_info=True)
+                version = '<unknown>'
 
         log.debug("detected 'bcrypt' backend, version %r", version)
         return mixin_cls._finalize_backend_mixin(name, dryrun)
