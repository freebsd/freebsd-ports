--- ui/gfx/x/gen_xproto.py.orig	2021-10-08 06:26:48 UTC
+++ ui/gfx/x/gen_xproto.py
@@ -1219,6 +1219,8 @@ class GenXproto(FileWriter):
         self.write('#include <cstring>')
         self.write('#include <vector>')
         self.write()
+        self.write('#include <unistd.h>')
+        self.write()
         self.write('#include "base/component_export.h"')
         self.write('#include "base/memory/ref_counted_memory.h"')
         self.write('#include "base/memory/scoped_refptr.h"')
@@ -1313,6 +1315,7 @@ class GenXproto(FileWriter):
         self.write()
         self.write('#include <xcb/xcb.h>')
         self.write('#include <xcb/xcbext.h>')
+        self.write('#include <unistd.h>')
         self.write()
         self.write('#include "base/logging.h"')
         self.write('#include "base/posix/eintr_wrapper.h"')
