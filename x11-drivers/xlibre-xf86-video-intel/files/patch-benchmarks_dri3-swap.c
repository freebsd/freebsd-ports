dri3-swap.c:237:24: error: variable 'tmp' is uninitialized when used here [-Werror,-Wuninitialized]
                        list_for_each_entry(tmp, &mru, link) {
                                            ^~~
dri3-swap.c:117:45: note: expanded from macro 'list_for_each_entry'
    for (pos = __container_of((head)->next, pos, member);               \
                                            ^~~
dri3-swap.c:114:41: note: expanded from macro '__container_of'
    (void *)((char *)(ptr) - ((char *)&(sample)->member - (char *)(sample)))
                                        ^~~~~~
dri3-swap.c:236:22: note: initialize the variable 'tmp' to silence this warning
                        struct buffer *tmp, *b = NULL;
                                          ^
                                           = NULL

--- benchmarks/dri3-swap.c.orig	2019-02-21 22:26:50 UTC
+++ benchmarks/dri3-swap.c
@@ -233,7 +233,7 @@ static void run(Display *dpy, Window win)
 	clock_gettime(CLOCK_MONOTONIC, &start);
 	do {
 		for (n = 0; n < 1000; n++) {
-			struct buffer *tmp, *b = NULL;
+			struct buffer *tmp = NULL, *b = NULL;
 			list_for_each_entry(tmp, &mru, link) {
 				if (!tmp->busy) {
 					b = tmp;
