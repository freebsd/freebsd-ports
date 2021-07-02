From 63e6f932ab4004f0c09a080d370861d0323b6d33 Mon Sep 17 00:00:00 2001
From: Alexey Borzov <avb@php.net>
Date: Fri, 25 Jun 2021 15:05:27 +0300
Subject: [PATCH] Attempt to fix #23 or at least be more verbose

--- HTTP/Request2/SocketWrapper.php.orig	2020-09-24 22:12:37 UTC
+++ HTTP/Request2/SocketWrapper.php
@@ -228,23 +228,31 @@ class HTTP_Request2_SocketWrapper
     public function write($data)
     {
         $totalWritten = 0;
-        while (strlen($data)) {
+        while (strlen($data) && !$this->eof()) {
             $written  = 0;
+            $error    = null;
             $timeouts = $this->_getTimeoutsForStreamSelect();
 
-            $r = [];
+            $r = null;
             $w = [$this->socket];
-            $e = [];
+            $e = null;
             if (stream_select($r, $w, $e, $timeouts[0], $timeouts[1])) {
-                // Notice: fwrite(): send of #### bytes failed with errno=10035
-                // A non-blocking socket operation could not be completed immediately.
-                $written = @fwrite($this->socket, $data);
+                set_error_handler(static function ($errNo, $errStr) use (&$error) {
+                    if (0 !== (E_NOTICE | E_WARNING) & $errNo) {
+                        $error = $errStr;
+                    }
+                });
+                $written = fwrite($this->socket, $data);
+                restore_error_handler();
             }
             $this->checkTimeout();
 
-            // http://www.php.net/manual/en/function.fwrite.php#96951
-            if (0 === (int)$written) {
-                throw new HTTP_Request2_MessageException('Error writing request');
+            // php_sockop_write() defined in /main/streams/xp_socket.c may return zero written bytes for non-blocking
+            // sockets in case of transient errors. These writes will not have notices raised and should be retried
+            if (false === $written || 0 === $written && null !== $error) {
+                throw new HTTP_Request2_MessageException(
+                    'Error writing request' . (null === $error ? '' : ': ' . $error)
+                );
             }
             $data = substr($data, $written);
             $totalWritten += $written;
