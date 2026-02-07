present-speed.c:317:23: error: variable 'b' is uninitialized when used here [-Werror,-Wuninitialized]
                list_for_each_entry(b, &mru, link)
                                    ^
present-speed.c:115:45: note: expanded from macro 'list_for_each_entry'
    for (pos = __container_of((head)->next, pos, member);               \
                                            ^~~
present-speed.c:112:41: note: expanded from macro '__container_of'
    (void *)((char *)(ptr) - ((char *)&(sample)->member - (char *)(sample)))
                                        ^~~~~~
present-speed.c:297:19: note: initialize the variable 'b' to silence this warning
                struct buffer *b;
                                ^
                                 = NULL
present-speed.c:229:19: error: variable 'tmp' is used uninitialized whenever its declaration is reached
      [-Werror,-Wsometimes-uninitialized]
                        struct buffer *tmp, *b = NULL;
                        ~~~~~~~~~~~~~~~^~~
present-speed.c:231:24: note: uninitialized use occurs here
                        list_for_each_entry(tmp, &mru, link) {
                                            ^~~
present-speed.c:115:45: note: expanded from macro 'list_for_each_entry'
    for (pos = __container_of((head)->next, pos, member);               \
                                            ^~~
present-speed.c:112:41: note: expanded from macro '__container_of'
    (void *)((char *)(ptr) - ((char *)&(sample)->member - (char *)(sample)))
                                        ^~~~~~
present-speed.c:229:22: note: initialize the variable 'tmp' to silence this warning
                        struct buffer *tmp, *b = NULL;
                                          ^
                                           = NULL
present-speed.c:557:24: error: variable 'b' is uninitialized when used here [-Werror,-Wuninitialized]
                        list_for_each_entry(b, &pp[i].mru, link)
                                            ^
present-speed.c:115:45: note: expanded from macro 'list_for_each_entry'
    for (pos = __container_of((head)->next, pos, member);               \
                                            ^~~
present-speed.c:112:41: note: expanded from macro '__container_of'
    (void *)((char *)(ptr) - ((char *)&(sample)->member - (char *)(sample)))
                                        ^~~~~~
present-speed.c:537:20: note: initialize the variable 'b' to silence this warning
                        struct buffer *b;
                                        ^
                                         = NULL
present-speed.c:467:19: error: variable 'tmp' is used uninitialized whenever its declaration is reached
      [-Werror,-Wsometimes-uninitialized]
                        struct buffer *tmp, *b = NULL;
                        ~~~~~~~~~~~~~~~^~~
present-speed.c:469:24: note: uninitialized use occurs here
                        list_for_each_entry(tmp, &pp[i].mru, link) {
                                            ^~~
present-speed.c:115:45: note: expanded from macro 'list_for_each_entry'
    for (pos = __container_of((head)->next, pos, member);               \
                                            ^~~
present-speed.c:112:41: note: expanded from macro '__container_of'
    (void *)((char *)(ptr) - ((char *)&(sample)->member - (char *)(sample)))
                                        ^~~~~~
present-speed.c:467:22: note: initialize the variable 'tmp' to silence this warning
                        struct buffer *tmp, *b = NULL;
                                          ^
                                           = NULL

--- test/present-speed.c.orig	2019-02-21 22:26:50 UTC
+++ test/present-speed.c
@@ -226,7 +226,7 @@ static void run(Display *dpy, Window win, const char *
 	clock_gettime(CLOCK_MONOTONIC, &start);
 	do {
 		for (n = 0; n < 1000; n++) {
-			struct buffer *tmp, *b = NULL;
+			struct buffer *tmp = NULL, *b = NULL;
 retry:
 			list_for_each_entry(tmp, &mru, link) {
 				if (tmp->fence.xid)
@@ -294,7 +294,7 @@ retry:
 	} while (end.tv_sec < start.tv_sec + 10);
 
 	if (options & DRI3) {
-		struct buffer *b;
+		struct buffer *b = NULL;
 		XID pixmap;
 
 		pixmap = xcb_generate_id(c);
@@ -464,7 +464,7 @@ static void perpixel(Display *dpy,
 	clock_gettime(CLOCK_MONOTONIC, &start);
 	do {
 		for (i = 0; i < sz; i++) {
-			struct buffer *tmp, *b = NULL;
+			struct buffer *tmp = NULL, *b = NULL;
 retry:
 			list_for_each_entry(tmp, &pp[i].mru, link) {
 				if (tmp->fence.xid)
@@ -534,7 +534,7 @@ retry:
 	for (i = 0; i < sz; i++) {
 		if (options & DRI3) {
 			int depth = DefaultDepth(dpy, DefaultScreen(dpy));
-			struct buffer *b;
+			struct buffer *b = NULL;
 			XID pixmap;
 
 			pixmap = xcb_generate_id(c);
