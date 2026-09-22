Fix compile issue on FreeBSD 14.4/i386

# kilabit.info/pakakeh.go/lib/net
vendor/kilabit.info/pakakeh.go/lib/net/poll_bsd.go:158:11: cannot use poll.events[x].Ident (variable of type uint32) as uint64 value in struct literal

--- vendor/kilabit.info/pakakeh.go/lib/net/poll_bsd.go.orig	2026-09-22 14:54:26 UTC
+++ vendor/kilabit.info/pakakeh.go/lib/net/poll_bsd.go
@@ -155,7 +155,7 @@ func (poll *kqueue) WaitReadEvents() (events []PollEve
 		}
 
 		var event = &pollEvent{
-			fd:    poll.events[x].Ident,
+			fd:    uint64(poll.events[x].Ident),
 			event: poll.events[x],
 		}
 		events = append(events, event)
