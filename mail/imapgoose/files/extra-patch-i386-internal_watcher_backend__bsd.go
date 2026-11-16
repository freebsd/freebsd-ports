--- internal/watcher/backend_bsd.go.orig	2026-11-16 06:24:59 UTC
+++ internal/watcher/backend_bsd.go
@@ -57,12 +57,14 @@ func (b *bsdBackend) Add(path string) error {
 		return fmt.Errorf("failed to open %s: %w", path, err)
 	}
 
-	dirEvent := unix.Kevent_t{
-		Ident:  uint64(fd),
-		Filter: int16(unix.EVFILT_VNODE),
-		Flags:  uint16(unix.EV_ADD | unix.EV_CLEAR | unix.EV_ENABLE),
-		Fflags: unix.NOTE_WRITE | unix.NOTE_DELETE | unix.NOTE_RENAME,
-	}
+	dirEvent := unix.Kevent_t{}
+	unix.SetKevent(
+		&dirEvent,
+		fd,
+		unix.EVFILT_VNODE,
+		unix.EV_ADD | unix.EV_CLEAR | unix.EV_ENABLE,
+	)
+	dirEvent.Fflags = unix.NOTE_WRITE | unix.NOTE_DELETE | unix.NOTE_RENAME
 
 	n, err := unix.Kevent(b.fd, []unix.Kevent_t{dirEvent}, nil, nil)
 	if n == -1 || err != nil {
@@ -86,11 +88,9 @@ func (b *bsdBackend) remove(path string) error {
 		return fmt.Errorf("path not being watched: %s", path)
 	}
 
-	dirEvent := unix.Kevent_t{
-		Ident:  uint64(fd),
-		Filter: int16(unix.EVFILT_VNODE),
-		Flags:  uint16(unix.EV_DELETE),
-	}
+	dirEvent := unix.Kevent_t{}
+	unix.SetKevent(&dirEvent, fd, unix.EVFILT_VNODE, unix.EV_DELETE)
+
 	if _, err := unix.Kevent(b.fd, []unix.Kevent_t{dirEvent}, nil, nil); err != nil {
 		return fmt.Errorf("failed to remove directory from kqueue: %w", err)
 	}
