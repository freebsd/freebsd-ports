# Fix use of h2.settings -> h2.settings.SettingCodes.* Based on:
# HTTP20Connection: Fix use of ENABLE_PUSH
# https://github.com/Lukasa/hyper/pull/402

# Fix hpack import (hpack_compat is gone now)
# https://github.com/python-hyper/hpack/pull/60

--- test/test_hyper.py.orig	2019-05-17 10:17:07 UTC
+++ test/test_hyper.py
@@ -1,14 +1,13 @@
 # -*- coding: utf-8 -*-
-import h2.settings
-
 from h2.frame_buffer import FrameBuffer
 from h2.connection import ConnectionState
+from h2.settings import SettingCodes
 from hyperframe.frame import (
     Frame, DataFrame, RstStreamFrame, SettingsFrame, PushPromiseFrame,
     WindowUpdateFrame, HeadersFrame, ContinuationFrame, GoAwayFrame,
     PingFrame, FRAME_MAX_ALLOWED_LEN
 )
-from hpack.hpack_compat import Encoder
+from hpack import Encoder
 from hyper.common.connection import HTTPConnection
 from hyper.http20.connection import HTTP20Connection
 from hyper.http20.response import HTTP20Response, HTTP20Push
@@ -766,7 +765,7 @@ class TestHyperConnection(object):
         # the default max frame size (16,384 bytes). That will, on the third
         # frame, trigger the processing to increment the flow control window,
         # which should then not happen.
-        f = SettingsFrame(0, settings={h2.settings.INITIAL_WINDOW_SIZE: 100})
+        f = SettingsFrame(0, settings={SettingCodes.INITIAL_WINDOW_SIZE: 100})
 
         c = HTTP20Connection('www.google.com')
         c._sock = DummySocket()
