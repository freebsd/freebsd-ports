Eric Wong: connection/poolable: do not write before event_write

Blindly attempting to write to a socket before a TCP connection can be
established returns EAGAIN on Linux, but not on FreeBSD 8/9.  This
causes Danga::Socket to error out, as it won't attempt to buffer on
anything but EAGAIN on write() attempts.

Now, we buffer writes explicitly after the initial socket creation and
connect(), and only call Danga::Socket::write when we've established
writability.  This works on Linux, too, and avoids an unnecessary
syscall in most cases.

Reported-by: Alex Yakovenko <aleksey.yakovenko@gmail.com>

--- lib/MogileFS/Connection/Poolable.pm.orig	2013-08-19 05:52:33.000000000 +0300
+++ lib/MogileFS/Connection/Poolable.pm	2013-11-20 22:57:31.000000000 +0200
@@ -13,6 +13,7 @@ use fields (
     'mfs_expire_cb',  # Danga::Socket::Timer callback
     'mfs_requests',   # number of requests made on this object
     'mfs_err',        # used to propagate an error to start()
+    'mfs_writeq',     # arrayref if connecting, undef otherwise
 );
 use Socket qw(SO_KEEPALIVE);
 use Time::HiRes;
@@ -27,6 +28,9 @@ sub new {
     $self->{mfs_hostport} = [ $ip, $port ];
     $self->{mfs_requests} = 0;
 
+    # newly-created socket, we buffer writes until event_write is triggered
+    $self->{mfs_writeq} = [];
+
     return $self;
 }
 
@@ -53,6 +57,38 @@ sub mark_idle {
     $self->{mfs_requests}++;
 }
 
+sub write {
+    my ($self, $arg) = @_;
+    my $writeq = $self->{mfs_writeq};
+
+    if (ref($writeq) eq "ARRAY") {
+        # if we're still connecting, we must buffer explicitly for *BSD
+        # and not attempt a real write() until event_write is triggered
+        push @$writeq, $arg;
+        $self->watch_write(1); # enable event_write triggering
+        0; # match Danga::Socket::write return value
+    } else {
+        $self->SUPER::write($arg);
+    }
+}
+
+# Danga::Socket will trigger this when a socket is writable
+sub event_write {
+    my ($self) = @_;
+
+    # we may have buffered writes in mfs_writeq during non-blocking connect(),
+    # this is needed on *BSD but unnecessary (but harmless) on Linux.
+    my $writeq = delete $self->{mfs_writeq};
+    if ($writeq) {
+        $self->watch_write(0); # ->write will re-enable if needed
+        foreach my $queued (@$writeq) {
+            $self->write($queued);
+        }
+    } else {
+        $self->SUPER::event_write();
+    }
+}
+
 # the request running on this connection is retryable if this socket
 # has ever been marked idle.  The connection pool can never be 100%
 # reliable for detecting dead sockets, and all HTTP requests made by
