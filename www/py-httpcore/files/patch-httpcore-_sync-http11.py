Obtained from:	https://github.com/encode/httpcore/commit/4cf288e0007cb73561b9020af9228f076ba2a94e

--- httpcore/_sync/http11.py.orig	2022-05-17 12:45:06 UTC
+++ httpcore/_sync/http11.py
@@ -1,7 +1,16 @@
 import enum
 import time
 from types import TracebackType
-from typing import Iterable, Iterator, List, Optional, Tuple, Type, Union
+from typing import (
+    Iterable,
+    Iterator,
+    List,
+    Optional,
+    Tuple,
+    Type,
+    Union,
+    cast,
+)
 
 import h11
 
@@ -17,13 +26,11 @@ from .._trace import Trace
 from ..backends.base import NetworkStream
 from .interfaces import ConnectionInterface
 
-H11Event = Union[
+# A subset of `h11.Event` types supported by `_send_event`
+H11SendEvent = Union[
     h11.Request,
-    h11.Response,
-    h11.InformationalResponse,
     h11.Data,
     h11.EndOfMessage,
-    h11.ConnectionClosed,
 ]
 
 
@@ -127,14 +134,14 @@ class HTTP11Connection(ConnectionInterface):
             event = h11.Data(data=chunk)
             self._send_event(event, timeout=timeout)
 
-        event = h11.EndOfMessage()
-        self._send_event(event, timeout=timeout)
+        self._send_event(h11.EndOfMessage(), timeout=timeout)
 
     def _send_event(
-        self, event: H11Event, timeout: Optional[float] = None
+        self, event: h11.Event, timeout: Optional[float] = None
     ) -> None:
         bytes_to_send = self._h11_state.send(event)
-        self._network_stream.write(bytes_to_send, timeout=timeout)
+        if bytes_to_send is not None:
+            self._network_stream.write(bytes_to_send, timeout=timeout)
 
     # Receiving the response...
 
@@ -168,7 +175,9 @@ class HTTP11Connection(ConnectionInterface):
             elif isinstance(event, (h11.EndOfMessage, h11.PAUSED)):
                 break
 
-    def _receive_event(self, timeout: Optional[float] = None) -> H11Event:
+    def _receive_event(
+        self, timeout: Optional[float] = None
+    ) -> Union[h11.Event, Type[h11.PAUSED]]:
         while True:
             with map_exceptions({h11.RemoteProtocolError: RemoteProtocolError}):
                 event = self._h11_state.next_event()
@@ -192,7 +201,8 @@ class HTTP11Connection(ConnectionInterface):
 
                 self._h11_state.receive_data(data)
             else:
-                return event
+                # mypy fails to narrow the type in the above if statement above
+                return cast(Union[h11.Event, Type[h11.PAUSED]], event)
 
     def _response_closed(self) -> None:
         with self._state_lock:
