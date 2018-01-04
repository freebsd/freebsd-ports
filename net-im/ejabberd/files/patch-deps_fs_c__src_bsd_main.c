--- deps/fs/c_src/bsd/main.c.orig	2017-12-14 20:07:26 UTC
+++ deps/fs/c_src/bsd/main.c
@@ -11,13 +11,9 @@ int main(int argc, char *argv[]) {
     int fd, kq, nev;
     if ((fd = open(argv[1], O_RDONLY)) == -1) return 1;
     EV_SET(&change, fd, EVFILT_VNODE , EV_ADD
-                                     | EV_ENABLE
-                                     | EV_DISABLE
                                      | EV_CLEAR
                                      | EV_DELETE
                                      | EV_EOF
-                                     | EV_RECEIPT
-                                     | EV_DISPATCH
                                      | EV_ONESHOT,
                                        NOTE_DELETE
                                      | NOTE_RENAME
