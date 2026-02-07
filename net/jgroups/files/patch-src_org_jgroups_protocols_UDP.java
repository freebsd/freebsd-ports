--- src/org/jgroups/protocols/UDP.java.orig	2011-03-18 10:35:34.000000000 +0100
+++ src/org/jgroups/protocols/UDP.java	2011-03-18 10:39:00.000000000 +0100
@@ -535,7 +535,7 @@
                 log.warn("send buffer of socket " + sock + " was set to " +
                         Util.printBytes(send_buf_size) + ", but the OS only allocated " +
                         Util.printBytes(actual_size) + ". This might lead to performance problems. Please set your " +
-                        "max send buffer in the OS correctly (e.g. net.core.wmem_max on Linux)");
+                        "max send buffer in the OS correctly (e.g. net.core.wmem_max on Linux or kern.ipc.maxsockbuf on FreeBSD)");
             }
         }
         catch(Throwable ex) {
@@ -549,7 +549,7 @@
                 log.warn("receive buffer of socket " + sock + " was set to " +
                         Util.printBytes(recv_buf_size) + ", but the OS only allocated " +
                         Util.printBytes(actual_size) + ". This might lead to performance problems. Please set your " +
-                        "max receive buffer in the OS correctly (e.g. net.core.rmem_max on Linux)");
+                        "max receive buffer in the OS correctly (e.g. net.core.rmem_max on Linux or kern.ipc.maxsockbuf on FreeBSD)");
             }
         }
         catch(Throwable ex) {
