===================================================================
RCS file: /cvs/gnome/pan2/pan/tasks/socket-impl-gio.cc,v
retrieving revision 1.2
retrieving revision 1.3
diff -u -r1.2 -r1.3
--- pan/tasks/socket-impl-gio.cc.orig	2006/10/06 15:25:53	1.2
+++ pan/tasks/socket-impl-gio.cc	2006/10/13 15:29:34	1.3
@@ -377,7 +377,7 @@
       {
          // see if we've got a partial line buffered up
          if (_channel->read_buf && _channel->read_buf->len) {
-           _partial_line.assign (_channel->read_buf->str, _channel->read_buf->len);
+           _partial_line.append (_channel->read_buf->str, _channel->read_buf->len);
            g_string_set_size (_channel->read_buf, 0);
          }
          // more to come
